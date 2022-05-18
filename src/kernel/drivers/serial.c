#include "./serial.h"
#include "./../../arch/x86/ports.h"

#define PORT 0x3f8
 
int init_serial()
{
    outb(PORT + 1, 0x00);
    outb(PORT + 3, 0x80);
    outb(PORT + 0, 0x03);
    outb(PORT + 1, 0x00);
    outb(PORT + 3, 0x03);
    outb(PORT + 2, 0xC7);
    outb(PORT + 4, 0x0B);
    outb(PORT + 4, 0x1E);
    outb(PORT + 0, 0xAE);
    if(inb(PORT + 0) != 0xAE) {
        return 1;
    }
    outb(PORT + 4, 0x0F);
    return 0;
}

int serial_received()
{
    return inb(PORT + 5) & 1;
}
 
char read_serial()
{
    while (serial_received() == 0);
 
    return inb(PORT);
}

int is_transmit_empty()
{
    return inb(PORT + 5) & 0x20;
}
 
void write_serial(char a)
{
    while (is_transmit_empty() == 0);
 
    outb(PORT,a);
}