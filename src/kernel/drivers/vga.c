#include "./vga.h"
#include "./../stdlib/stdint.h"

uint16_t vga_entry(unsigned char ch, uint8_t fore_color, uint8_t back_color) 
{
    uint16_t ax = 0;
    uint8_t ah = 0, al = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}

//clear video buffer array
void clear_vga_buffer(uint16_t **buffer, uint8_t fore_color, uint8_t back_color)
{
    uint32_t i;
    for(i = 0; i < BUFSIZE; i++){
        (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
    }
}

//initialize vga buffer
void init_vga(uint8_t fore_color, uint8_t back_color)
{
    vga_buffer = (uint16_t*)VGA_ADDRESS;  //point vga_buffer pointer to VGA_ADDRESS 
    clear_vga_buffer(&vga_buffer, fore_color, back_color);  //clear buffer
}