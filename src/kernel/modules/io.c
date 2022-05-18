#include "./io.h"
#include "./../drivers/vga.h"
#include "./../config.h"
#include "./../stdlib/stdint.h"
#include "./../stdlib/string.h"
#include "./../drivers/serial.h"

void init_term()
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_initialize();
    #elif defined SERIAL_TERMINAL
    init_serial();
    #endif
}

void printf(char* STRING_TO_PRINT)
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_writestring(STRING_TO_PRINT);
    #elif defined SERIAL_TERMINAL
    for(int i = 0; i <= strlen(STRING_TO_PRINT); i++)
    {
        write_serial(STRING_TO_PRINT[i]);
    }
    #endif
}

/*
 *  I COULD REPLACE uint32_t WITH int, BUT I PREFER TO JUST LEAVE IT THE
 *  WAY IT IS FOR COMPABILITY AND LESS ERRORS.
 */
void printn(uint32_t NUMBER_TO_PRINT)
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_print_int(NUMBER_TO_PRINT);
    #elif defined SERIAL_TERMINAL
    char str_num[digit_count(NUMBER_TO_PRINT)+1];
	_itoa(NUMBER_TO_PRINT, str_num);
    printf(str_num);
    #endif
}

void putc(char CHARACTER_TO_PRINT)
{
    #ifdef VGA_TEXT_MODE
    vga_text_mode_putchar(CHARACTER_TO_PRINT);
    #elif defined SERIAL_TERMINAL
    write_serial(CHARACTER_TO_PRINT);
    #endif
}