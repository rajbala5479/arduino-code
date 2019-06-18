# C compiler
CC=avr-gcc
# Utility to copy object file
OBJCOPY=avr-objcopy

#-Os : Optimize for size, -Os enables all -O2 optimizations except the ones that increase size
#-D name = definition : Define macro
CFLAGS=-Os -DF_CPU=16000000UL -mmcu=atmega328p
PORT=/dev/ttyACM0

# -O : The output format
# -R : Remove the sections from .elf file
blink.hex: blink.elf
	${OBJCOPY} -O ihex -R .eeprom blink.elf blink.hex

blink.elf: blink.o
	${CC} -o blink.elf blink.o

blink.o: blink.c
	${CC} ${CFLAGS} -c -o blink.o blink.c

install : blink.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${PORT} -b 115200 -U flash:w:blink.hex

clean: 
	rm -f blink.o blink.elf blink.hex

