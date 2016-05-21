#
# Swamp - cooperative multitasking operating system
# Copyright (c) 2016 rksdna
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

# Project files

TARGET = app
SCRIPT = kernel/target/stm32f042x4.ld
DIRS = kernel cdc
INCDIRS = $(addsuffix /include, $(DIRS))
SRCDIRS = $(addsuffix /source, $(DIRS)) .
PORT = /dev/ttyUSB0

HEX = $(TARGET).hex
ELF = $(TARGET).elf
MAP = $(TARGET).map
LST = $(TARGET).lst
INC = $(foreach DIR, $(INCDIRS),-I $(DIR))
SRC = $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c))
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

# Tools and flags

PREFIX = arm-none-eabi-

CC = $(PREFIX)gcc
LD = $(PREFIX)ld
OC = $(PREFIX)objcopy
OD = $(PREFIX)objdump
SZ = $(PREFIX)size
BS = swamp-boot
RM = rm -f

CFLAGS = -nostdinc -mcpu=cortex-m0 -mthumb -Wall -Wno-main -Os -g -MD $(INC) 
LFLAGS = -nostdlib -T $(SCRIPT) -Map $(MAP) 

-include $(DEP)

# Targets

.PHONY: all clean install

all: $(HEX) $(LST)

$(HEX): $(ELF)
	@echo "Creating $(HEX)..."
	
	$(OC) -j .text -j .data -O ihex $< $@

$(LST): $(ELF)
	@echo "Creating $(LST)..."
	$(OD) -S -d -g $(ELF) > $(LST)
	$(SZ) $<

$(ELF): $(OBJ)
	@echo "Linking $(ELF)..."
	$(LD) $(LFLAGS)  -o $@ $^

%.o: %.c
	@ echo "Compiling $@..."
	$(CC) -c $(CFLAGS) -o $@ $<

install: $(HEX)
	@echo "Installing $(HEX)..."
	$(BS) -c $(PORT) -e -w $(HEX) -t -d

clean:
	@echo "Cleaning..."
	$(RM) $(OBJ) $(DEP) $(ELF) $(MAP) $(HEX) $(LST)

