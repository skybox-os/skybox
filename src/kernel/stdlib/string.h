#ifndef STRING_H
#define STRING_H

#include "./stdint.h"

/*
 *  ALL OF THESE FUNCTIONS ARE IMPLEMENTED INSTEAD OF USING <string.h>, BECAUSE
 *  I BELIEVE THAT IT IS MORE PRACTICAL TO IMPLEMENT CUSTOM FUNCTIONS WHEN
 *  CREATING A KERNEL IN C.
 */
void *memset(void *dst, char c, uint32_t n);
void *memcpy(void *dst, const void *src, uint32_t n);
int memcmp(uint8_t *s1, uint8_t *s2, uint32_t n);
int strlen(const char *s);
int strcmp(const char *s1, char *s2);
int strncmp(const char *s1, const char *s2, int c);
char* strncat(char* destination, const char* source, unsigned int num);
int strcpy(char *dst, const char *src);
void strcat(char *dest, const char *src);
int isspace(char c);
int isalpha(char c);
char upper(char c);
char lower(char c);
void itoa(char *buf, int base, int d);
char *strstr(const char *in, const char *str);

#endif