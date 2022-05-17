#include "./io.h"
#include "./../drivers/vga.h"
#include "./../config.h"
#include "./../stdlib/stdint.h"
#include "./../stdlib/string.h"

void init_term()
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_initialize();
    #endif
}

void printf(char* STRING_TO_PRINT)
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_writestring(STRING_TO_PRINT);
    #endif
}

void putc(char CHARACTER_TO_PRINT)
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_putchar(CHARACTER_TO_PRINT);
    #endif
}