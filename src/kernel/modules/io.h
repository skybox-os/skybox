#ifndef IO_H
#define IO_H

#include "./../stdlib/stdint.h"

void init_term();
void printf(char* STRING_TO_PRINT);
void putc(char CHARACTER_TO_PRINT);
void printn(uint32_t NUMBER_TO_PRINT);

#endif