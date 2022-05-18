#include "./time.h"

#include "./../stdlib/stdint.h"

void delay_in_ticks(uint32_t ticks)
{
    for(uint32_t x = 0; x <= ticks; x++) { }
}