#ifndef VGA_H
#define VGA_H

#include "./../stdlib/stdint.h"

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

extern uint16_t* vga_buffer;

#define NULL 0

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint16_t vga_entry(unsigned char ch, uint8_t fore_color, uint8_t back_color);
void clear_vga_buffer(uint16_t **buffer, uint8_t fore_color, uint8_t back_color);
void init_vga(uint8_t fore_color, uint8_t back_color);

#endif