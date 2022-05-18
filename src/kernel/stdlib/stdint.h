#ifndef STDINT_H
#define STDINT_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned int size_t;

void _itoa(int num, char *number);
uint32_t digit_count(int num);
uint32_t bytes_to_uint32(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

#endif