#ifndef IO_H
#define IO_H

#include "./../stdlib/stdint.h"

void putc(char CHARACTER_TO_PRINT);
void printf(char *TEXT_TO_PRINT);
void change_color(uint8_t fore_color, uint8_t back_color);
void clear_terminal();

#endif