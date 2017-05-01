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
#include <cdc.h>

#define SET_DEVICE_ADDRESS 0x0500
#define GET_DEVICE_DESCRIPTOR 0x0680
#define SET_DEVICE_CONFIGURATION 0x0900

#define SET_LINE_CODING 0x2021
#define GET_LINE_CODING 0x21A1
#define SET_CONTROL_LINE_STATE 0x2221
#define SEND_BREAK 0x2321

#define EP0_TX_DATA 0x0040
#define EP0_RX_DATA 0x0080
#define EP0_SIZE 64

#define EP1_RX_DATA0 0x00C0
#define EP1_RX_DATA1 0x0140
#define EP1_SIZE 64

#define EP2_TX_DATA0 0x01C0
#define EP2_TX_DATA1 0x0240
#define EP2_SIZE 64

#define EP3_TX_DATA 0x02C0
#define EP3_SIZE 64

struct ep_buffer
{
    u32_t time;
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
    0x02, // bDeviceClass
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
    0x43,
    0x00, // wTotalLength
    0x02, // bNumInterfaces
    0x01, // bConfigurationValue
    0x00, // iConfiguration String Index
    0xC0, // bmAttributes
    0x01, // bMaxPower

    0x09, // bLength
    0x04, // bDescriptorType
    0x01, // bInterface Number
    0x00, // bAlternateSetting
    0x02, // bNumEndpoints
    0x0A, // bInterfaceClass
    0x00, // bInterfaceSubClass
    0x00, // bInterfaceProtocol
    0x00, // iInterface String Index

    0x07, // bLength
    0x05, // bDescriptorType
    0x01, // bEndpoint Address
    0x02, // bmAttributes
    EP1_SIZE,
    0x00, // wMaxPacketSize
    0x01,  // bInterval

    0x07, // bLength
    0x05, // bDescriptorType
    0x82, // bEndpoint Address
    0x02, // bmAttributes
    EP2_SIZE,
    0x00, // wMaxPacketSize
    0x01, // bInterval

    0x09, // bLength
    0x04, // bDescriptorType
    0x00, // bInterface Number
    0x00, // bAlternateSetting
    0x01, // bNumEndpoints
    0x02, // bInterfaceClass
    0x02, // bInterfaceSubClass
    0x02, // bInterfaceProtocol
    0x00, // iInterface String Index

    0x05, // bLength
    0x24, // bDescriptorType
    0x00, // bDescriptorSubtype
    0x10,
    0x01, // bcdCDC

    0x05, // bLength
    0x24, // bDescriptorType
    0x01, // bDescriptorSubtype
    0x03, // bmCapabilities
    0x01, // bDataInterface

    0x04, // bLength
    0x24, // bDescriptorType
    0x02, // bDescriptorSubtype
    0x00, // bmCapabilities

    0x05, // bLength
    0x24, // bDescriptorType
    0x06, // bDescriptorSubtype
    0x00, // bDataInterface
    0x01, // bSlaveInterface

    0x07, // bLength
    0x05, // bDescriptorType
    0x83, // bEndpoint
    0x03, // bmAttributes
    EP3_SIZE,
    0x00, // wMaxPacketSize
    0x01 // bInterval
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

static u16_t usb_connected;
static u8_t coding_changed;
static u8_t zlp;
static u16_t tail_size;
static u16_t tail_address;

struct ep_buffer ep0;
struct ep_buffer ep1;
struct ep_buffer ep2;

static struct usb_setup setup;
static struct line_coding coding = {600, 0, 0, 8};

static u32_t limit(u32_t size, u32_t max_size)
{
    return size <= max_size ? size : max_size;
}

static void write_pma(const void *data, u32_t offset, u32_t size)
{
    u32_t count = (size + 1) / sizeof(u16_t);
    const u8_t *source = data;
    u16_t *destination = (void *)PMA + offset;
    while (count--)
    {
        u16_t value = *source++;
        value |= *source++ << 8;
        *destination++ = value;
    }
}

static void read_pma(void *data, u32_t offset, u32_t size)
{
    u8_t *destination = (u8_t *)data;
    const u8_t *source = (const void *)PMA + offset;
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
    if (setup.request == SET_LINE_CODING)
    {
        read_pma(&coding, EP0_RX_DATA, 7);
        write_ep0_buffer(0, 0);
        coding_changed = 1;
    }
    else
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
        USB->EP1R = 1 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_STAT_RX_1 | USB_EP_STAT_RX_0 | USB_EP_DBUF_RX;
        USB->EP2R = 2 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_STAT_TX_1 | USB_EP_STAT_TX_0 | USB_EP_DBUF_TX;
        USB->EP3R = 3 | USB_EP_TYPE_INTERRUPT | USB_EP_STAT_TX_1;
        write_ep0_buffer(0, 0);
        usb_connected = 1;
        return;

    case SET_LINE_CODING:
        USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_RX_0;
        return;

    case GET_LINE_CODING:
        write_ep0_buffer(&coding, 7);
        return;

    case SET_CONTROL_LINE_STATE:
        write_ep0_buffer(0, 0);
        return;

    case SEND_BREAK:
        write_ep0_buffer(0, 0);
        return;

    default:
        break;
    };

    USB->EP0R = USB_EP_TYPE_CONTROL | USB_EP_STAT_RX_1 | USB_EP_STAT_RX_0 | USB_EP_STAT_TX_1 | USB_EP_STAT_TX_0;
}

static void read_ep1_buffer(void)
{
    const u32_t buffer = USB->EP1R & USB_EP_DTOG_RX ? 4 : 6;
    const u32_t available = PMA[buffer + 1] & USB_PMA_COUNT;
    const u32_t count = limit(ep1.size, available);

    read_pma(ep1.data, PMA[buffer], count);
    tail_address = PMA[buffer] + count;
    tail_size = available - count;

    ep1.time = ep0.time;
    ep1.size -= count;
    ep1.data += count;
}

static void output_ep1_handler(void)
{
    USB->EP1R = 1 | USB_EP_TYPE_BULK | USB_EP_KIND;
    if (ep1.data && ep1.size)
    {
        USB->EP1R = 1 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_DBUF_RX | USB_EP_CTR_RX;
        read_ep1_buffer();
    }

    if (!ep1.size)
        ep1.data = 0;
}

static void write_ep2_buffer(void)
{
    const u32_t buffer = USB->EP2R & USB_EP_DBUF_TX ? 10 : 8;
    const u32_t count = limit(ep2.size, EP2_SIZE);

    write_pma(ep2.data, PMA[buffer], count);
    PMA[buffer + 1] = count;

    zlp = ep2.size == EP2_SIZE;

    ep2.time = ep0.time;
    ep2.size -= count;
    ep2.data += count;
}

static void input_ep2_handler(void)
{
    USB->EP2R = 2 | USB_EP_TYPE_BULK | USB_EP_KIND;
    if (ep2.data && (ep2.size || zlp))
    {
        write_ep2_buffer();
        USB->EP2R = 2 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_DBUF_TX | USB_EP_CTR_TX;
    }
    else
        ep2.data = 0;
}

static void input_ep3_handler(void)
{
    USB->EP3R = 3 | USB_EP_TYPE_INTERRUPT;
}

static void poll_buffer(struct ep_buffer *ep)
{
    if (ep->data && ep->time)
    {
        if (!--ep->time)
            ep->data = 0;
    }
}

static void usb_sof_handler(void)
{
    USB->ISTR = ~USB_ISTR_SOF;
    poll_buffer(&ep1);
    poll_buffer(&ep2);
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
    USB->EP2R = 0;
    USB->EP3R = 0;
    USB->DADDR = USB_DADDR_EF;
    usb_connected = 0;
    coding_changed = 0;
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

    if (USB->EP1R & USB_EP_CTR_RX)
        output_ep1_handler();

    if (USB->EP2R & USB_EP_CTR_TX)
        input_ep2_handler();

    if (USB->EP3R & USB_EP_CTR_TX)
        input_ep3_handler();

    if (USB->ISTR & USB_ISTR_SOF)
        usb_sof_handler();

    if (USB->ISTR & USB_ISTR_ESOF)
        usb_esof_handler();

    if (USB->ISTR & USB_ISTR_RESET)
        usb_reset_handler();
}

void start_cdc_service(void)
{
    USB->CNTR = USB_CNTR_FRES;
    USB->CNTR = USB_CNTR_CTRM | USB_CNTR_RESETM | USB_CNTR_SOFM | USB_CNTR_ESOFM;
    USB->BTABLE = 0;

    PMA[0] = EP0_TX_DATA;
    PMA[1] = 0;
    PMA[2] = EP0_RX_DATA;
    PMA[3] = USB_PMA_BLSIZE | USB_PMA_NUM_BLOCK_0;

    PMA[4] = EP1_RX_DATA0;
    PMA[5] = USB_PMA_BLSIZE | USB_PMA_NUM_BLOCK_1 | USB_PMA_NUM_BLOCK_0;
    PMA[6] = EP1_RX_DATA1;
    PMA[7] = USB_PMA_BLSIZE | USB_PMA_NUM_BLOCK_1 | USB_PMA_NUM_BLOCK_0;

    PMA[8] = EP2_TX_DATA0;
    PMA[9] = 0;
    PMA[10] = EP2_TX_DATA1;
    PMA[11] = 0;

    PMA[12] = EP3_TX_DATA;
    PMA[13] = 0;
    PMA[14] = 0;
    PMA[15] = 0;

    USB->ISTR = 0;
    NVIC->ISER = NVIC_ISER_SETENA_31;
    USB->BCDR = USB_BCDR_DPPU;
}

void stop_cdc_service(void)
{
    NVIC->ICER = NVIC_ICER_CLRENA_31;
    USB->BCDR = 0;
    USB->CNTR = USB_CNTR_PDWN | USB_CNTR_FRES;
}

u32_t has_cdc_connection(void)
{
    return usb_connected;
}

u32_t has_cdc_line_coding(void)
{
    return coding_changed;
}

const struct line_coding *get_cdc_line_coding(void)
{
    coding_changed = 0;
    return &coding;
}

void set_cdc_timeout(u32_t ms)
{
    ep0.time = ms;
}

static u32_t end_condition(struct ep_buffer *ep)
{
    return !ep->data || !usb_connected;
}

u32_t write_cdc_data(const void *data, u32_t size)
{
    ep2.time = ep0.time;
    ep2.size = size;
    ep2.data = (void *)data;

    write_ep2_buffer();
    USB->EP2R = 2 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_DBUF_TX | USB_EP_CTR_TX;

    yield_thread((condition_t)end_condition, &ep2);
    return size - ep2.size;
}

u32_t read_cdc_data(void *data, u32_t size)
{
    const u32_t count = limit(tail_size, size);
    read_pma(data, tail_address, count);
    tail_size -= count;
    tail_address += count;

    ep1.time = ep0.time;
    ep1.size = size - count;
    ep1.data = data + count;

    const u32_t hardware_buffer = USB->EP1R & USB_EP_DBUF_RX ? 1 : 0;
    const u32_t software_buffer = USB->EP1R & USB_EP_DTOG_RX ? 1 : 0;
    if (hardware_buffer == software_buffer)
    {
        read_ep1_buffer();
        USB->EP1R = 1 | USB_EP_TYPE_BULK | USB_EP_KIND | USB_EP_DBUF_RX | USB_EP_CTR_RX;
    }

    yield_thread((condition_t)end_condition, &ep1);
    return size - ep1.size;
}
