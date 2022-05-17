#include "kernel.h"
#include "./drivers/vga.h"
#include "./modules/io.h"

void kernel_entry()
{
    //first init vga with fore & back colors
    init_vga(WHITE, BLACK);

    //assign each ASCII character to video buffer
    //you can change colors here
    putc('h');
    vga_buffer[10] = vga_entry('H', WHITE, BLACK);
    vga_buffer[11] = vga_entry('e', WHITE, BLACK);
}
