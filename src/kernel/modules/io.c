#include "./io.h"
#include "./../drivers/vga.h"
#include "./../config.h"
#include "./../stdlib/stdint.h"

uint16_t vga_textmode_pos = 0;
uint8_t foreground_color = WHITE;
uint8_t background_color = BLACK;

/*
 *  THE TERMINAL COLORS GLOBALLY SHALL BE THE VGA TEXT-MODE COLORS
 *  BY DEFAULT, EVEN IF THE TERMINAL IS RAN IN A GRAPHICS ENVIRONMENT
 */

/*
 *  THIS FUNCTION PRINTS OUT A CHARACTER
 */
void putc(char CHARACTER_TO_PRINT)
{
    #ifdef IO_MODE_VGA_TEXT_MODE
        vga_buffer[vga_textmode_pos] = vga_entry(CHARACTER_TO_PRINT, foreground_color, background_color);
        vga_textmode_pos++;
    #endif
}

/*
 *  THIS FUNCTION PRINTS OUT A STRING
 */
void printf(char *TEXT_TO_PRINT)
{
    #ifdef IO_MODE_VGA_TEXT_MODE
        //TODO: Implement this function!
    #endif
}

/*
 *  THIS FUNCTION CHANGES THE COLOR OF FOLLOWING TEXT
 */
void change_color(uint8_t fore_color, uint8_t back_color)
{
    foreground_color = fore_color;
    background_color = back_color;
}

void clear_terminal()
{
    #ifdef IO_MODE_VGA_TEXT_MODE
        clear_vga_buffer(vga_buffer, WHITE, BLACK);
    #endif
}