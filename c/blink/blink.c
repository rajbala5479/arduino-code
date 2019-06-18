#include<avr/io.h>
#include<util/delay.h>

//#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
//#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)

#define LS(bit) (1 << bit)
#define MYDDRB _SFR_IO8(0x04)
#define MYPORTB _SFR_IO8(0x05)

int main(){

    MYDDRB |= LS(5);

    while(1) {
        MYPORTB |= LS(5);
        _delay_ms(1000);

        MYPORTB &= ~LS(5);
        _delay_ms(1000);
    }

    return 0;
}