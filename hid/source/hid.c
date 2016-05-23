/*
 * Swamp - cooperative multitasking operating system
 * Copyright (c) 2016 rksdna
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stm32/nvic.h>
#include <stm32/usb.h>
#include <threads.h>
#include <hid.h>

#define SET_DEVICE_ADDRESS 0x0500
#define GET_DEVICE_DESCRIPTOR 0x0680
#define SET_DEVICE_CONFIGURATION 0x0900

#define SET_IDLE 0x0A21
#define GET_REPORT_DESCRIPTOR 0x0681
#define SET_REPORT 0x0921

#define EP0_TX_DATA 0x0040
#define EP0_RX_DATA 0x0080
#define EP0_SIZE 64

#define EP1_TX_DATA 0x00C0
#define EP1_SIZE 64

struct ep_buffer
{
    u32_t size;
    void *data;
};

struct usb_setup
{
    u16_t request;
    u16_t value;
    u16_t index;
    u16_t length;
};

static const u8_t device_descriptor[] =
{
    0x12, // bLength
    0x01, // bDescriptorType
    0x10,
    0x01, // bcdUSB USB Version
    0x00, // bDeviceClass
    0x00, // bDeviceSubclass
    0x00, // bDeviceProtocol
    EP0_SIZE, // bMaxPacketSize
    0x83,
    0x04, // idVendor
    0x40,
    0x57, // idProduct
    0x00,
    0x00, // bcdDevice
    0x01, // iManufacturer String Index
    0x02, // iProduct String Index
    0x00, // iSerialNumber String Index
    0x01  // bNumberConfigurations
};

static const u8_t configuration_descriptor[] =
{
    0x09, // bLength
    0x02, // bDescriptorType
    0x22,
    0x00, // wTotalLength
    0x01, // bNumInterfaces
    0x01, // bConfigurationValue
    0x00, // iConfiguration
    0x80, // bmAttributes
    0x01, // bMaxPower

    0x09, // bLength
    0x04, // bDescriptorType
    0x00, // bInterface Number
    0x00, // bAlternateSetting
    0x01, // bNumEndpoints
    0x03, // bInterfaceClass HID generic
    0x01, // bInterfaceSubClass
    0x01, // bInterfaceProtocol
    0x00, // iInterface String Index

    0x09, // bLength
    0x21, // bDescriptorType
    0x11,
    0x01, // bcdHID
    0x00, // bCountryCode
    0x01, // bNumDescriptors
    0x22, // bDescriptorType
    0x3F,
    0x00, // wDescriptorLength

    0x07, // bLength
    0x05, // bDescriptorType
    0x81, // bEndpoint EP1 IN
    0x03, // bmAttributes - Interrupt
    EP1_SIZE,
    0x00, // wMaxPacketSize
    0x01, // bInterval
};

static const u8_t language_descriptor[] =
{
    0x04, // bLenght
    0x03, // bDescriptorType
    0x09,
    0x04  // wLangId
};

static const u8_t manufacturer_descriptor[] =
{
    0x0C, // bLenght
    0x03, // bDescriptorType
    'S', 0x00,
    'w', 0x00,
    'a', 0x00,
    'm', 0x00,
    'p', 0x00,
};

static const u8_t product_descriptor[] =
{
    0x0C, // bLenght
    0x03, // bDescriptorType
    'S', 0x00,
    'w', 0x00,
    'a', 0x00,
    'm', 0x00,
    'p', 0x00,
};

static const u8_t hid_report_descriptor[] =
{
    0x05, 0x01, // Usage Page (Generic Desktop)
    0x09, 0x06,	// Usage (Keyboard)
    0xA1, 0x01, // Collection (Application)
    0x75, 0x01, // Report Size (1)
    0x95, 0x08, // Report Count (8)
    0x05, 0x07, // Usage Page (Key Codes)
    0x19, 0xE0, // Usage Minimum (224)
    0x29, 0xE7, // Usage Maximum (231)
    0x15, 0x00, // Logical Minimum (0)
    0x25, 0x01, // Logical Maximum (1)
    0x81, 0x02, // Input (Data, Variable, Absolute)
    0x95, 0x01, // Report Count (1)
    0x75, 0x08, // Report Size (8)
    0x81, 0x01, // Input (Constant)
    0x95, 0x05, // Report Count (5)
    0x75, 0x01, // Report Size (1)
    0x05, 0x08, // Usage Page (LEDs)
    0x19, 0x01, // Usage Minimum (1)
    0x29, 0x05, // Usage Maximum (5)
    0x91, 0x02, // Output (Data, Variable, Absolute)
    0x95, 0x01, // Report Count (1)
    0x75, 0x03, // Report Size (3)
    0x91, 0x01, // Output (Constant)
    0x95, 0x06, // Report Count (6)
    0x75, 0x08, // Report Size (8)
    0x15, 0x00, // Logical Minimum (0)
    0x25, 0xFF, // Logical Maximum(255)
    0x05, 0x07, // Usage Page (Key Codes)
    0x19, 0x00, // Usage Minimum (0)
    0x29, 0xFF, // Usage Maximum (255)
    0x81, 0x00, // Input (Data, Array)
    0xC0        // End Collection
};

static u16_t usb_connected;
static u16_t hid_timeout;

struct ep_buffer ep0;

static struct usb_setup setup;

static u32_t limit(u32_t size, u32_t max_size)
{
    return size <= max_size ? size : max_size;
}

static void write_pma(const void *data, u32_t offset, u32_t size)
{
    u32_t count = (size + 1) / sizeof(u16_t);
    u8_t *source = (u8_t *)data;
    u16_t *destination = (u16_t *)((u8_t *)PMA + offset);
    while (count--)
    {
        u16_t value = *source++;
        value |= *source++ << 8;
        *destination++ = value;
    }
}

static void read_pma(void *data, u32_t offset, u32_t size)
{
    u8_t *source = (u8_t *)PMA + offset;
    u8_t *destination = (u8_t *)data;
    while (size--)
        *destination++ = *source++;
}

static void write_ep0_buffer(const void *data, u32_t size)
{
    const u32_t count = limit(size, EP0_SIZE);

    write_pma(data, EP0_TX_DATA, count);
    PMA[1] = count;
    USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_TX_0;

    ep0.size = size - count;
    ep0.data = (void *)data + count;

    if (!ep0.size && (count != EP0_SIZE))
        ep0.data = 0;
}

static void input_ep0_handler(void)
{
    if (setup.request == SET_DEVICE_ADDRESS)
        USB->DADDR = (setup.value & USB_DADDR_ADD) | USB_DADDR_EF;

    if (ep0.size)
        write_ep0_buffer(ep0.data, ep0.size);
    else
        USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_RX_0;
}

static void output_ep0_handler(void)
{
    USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_RX_0 | USB_EP_CTR_TX;
}

static void setup_ep0_handler(void)
{
    read_pma((void *)&setup, EP0_RX_DATA, sizeof(struct usb_setup));
    switch (setup.request)
    {
    case GET_DEVICE_DESCRIPTOR:
        switch (setup.value)
        {
        case 0x0100:
            write_ep0_buffer(device_descriptor, limit(setup.length, sizeof(device_descriptor)));
            return;

        case 0x0200:
            write_ep0_buffer(configuration_descriptor, limit(setup.length, sizeof(configuration_descriptor)));
            return;

        case 0x0300:
            write_ep0_buffer(language_descriptor, limit(setup.length, sizeof(language_descriptor)));
            return;

        case 0x0301:
            write_ep0_buffer(manufacturer_descriptor, limit(setup.length, sizeof(manufacturer_descriptor)));
            return;

        case 0x0302:
            write_ep0_buffer(product_descriptor, limit(setup.length, sizeof(product_descriptor)));
            return;

        default:
            break;
        }
        break;

    case SET_DEVICE_ADDRESS:
        write_ep0_buffer(0, 0);
        return;

    case SET_DEVICE_CONFIGURATION:
        USB->EP1R = 1 | USB_EP_TYPE_INTERRUPT | USB_EP_STAT_TX_1;
        write_ep0_buffer(0, 0);
        usb_connected = 1;
        return;

    case SET_IDLE:
        write_ep0_buffer(0, 0);
        return;

    case GET_REPORT_DESCRIPTOR:
        write_ep0_buffer(hid_report_descriptor, limit(setup.length, sizeof(hid_report_descriptor)));
        return;

    case SET_REPORT:
        write_ep0_buffer(0, 0);
        return;

    default:
        break;
    };

    USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_RX_1 | USB_EP_STAT_RX_0 | USB_EP_STAT_TX_1 | USB_EP_STAT_TX_0;
}

static void input_ep1_handler(void)
{
    USB->EP1R = 1 | USB_EP_TYPE_INTERRUPT;
    hid_timeout = 0;
}

static void usb_sof_handler(void)
{
    USB->ISTR = ~USB_ISTR_SOF;
    if (hid_timeout)
        hid_timeout--;
}

static void usb_esof_handler(void)
{
    USB->ISTR = ~USB_ISTR_ESOF;
    usb_connected = 0;
}

static void usb_reset_handler(void)
{
    USB->ISTR = ~USB_ISTR_RESET;
    USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_TX_1 | USB_EP_STAT_RX_1 | USB_EP_STAT_RX_0;
    USB->EP1R = 0;
    USB->DADDR = USB_DADDR_EF;
    usb_connected = 0;
}

void irq31_handler(void)
{
    if (USB->EP0R & USB_EP_CTR_TX)
        input_ep0_handler();

    if (USB->EP0R & USB_EP_CTR_RX)
    {
        if (USB->EP0R & USB_EP_SETUP)
            setup_ep0_handler();
        else
            output_ep0_handler();
    }

    if (USB->EP1R & USB_EP_CTR_TX)
        input_ep1_handler();

    if (USB->ISTR & USB_ISTR_SOF)
        usb_sof_handler();

    if (USB->ISTR & USB_ISTR_ESOF)
        usb_esof_handler();

    if (USB->ISTR & USB_ISTR_RESET)
        usb_reset_handler();
}

void start_hid_service(void)
{
    USB->CNTR = USB_CNTR_FRES;
    USB->CNTR = USB_CNTR_CTRM | USB_CNTR_RESETM | USB_CNTR_SOFM | USB_CNTR_ESOFM;
    USB->BTABLE = 0;

    PMA[0] = EP0_TX_DATA;
    PMA[1] = 0;
    PMA[2] = EP0_RX_DATA;
    PMA[3] = USB_PMA_BLSIZE | USB_PMA_NUM_BLOCK_0;

    PMA[4] = EP1_TX_DATA;
    PMA[5] = 0;
    PMA[6] = 0;
    PMA[7] = 0;

    USB->ISTR = 0;
    NVIC->ISER = NVIC_ISER_SETENA_31;
    USB->BCDR = USB_BCDR_DPPU;
}

void stop_hid_service(void)
{
    NVIC->ICER = NVIC_ICER_CLRENA_31;
    USB->BCDR = 0;
    USB->CNTR = USB_CNTR_PDWN | USB_CNTR_FRES;
}

u32_t has_hid_connection(void)
{
    return usb_connected;
}

static u32_t end_condition(void)
{
    return !hid_timeout || !usb_connected;
}

void write_hid_report(struct hid_report *report)
{
    PMA[5] = sizeof(struct hid_report);
    write_pma(report, EP1_TX_DATA, sizeof(struct hid_report));
    USB->EP1R = 1 | USB_EP_TYPE_INTERRUPT | USB_EP_STAT_TX_0;
    hid_timeout = 10;
    yield_thread((condition_t)end_condition, 0);
}
