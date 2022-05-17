#ifndef PORTS_H
#define PORTS_H

#include "./../../kernel/stdlib/stdint.h"
/*
static inline void outb(uint32_t port, uint8_t data);
static inline uint8_t inb(uint32_t port);
static inline void outw(uint32_t port, uint16_t data);
static inline uint16_t inw(uint32_t port);
static inline void outl(uint32_t port, uint32_t data);
static inline uint32_t inl(uint32_t port);
*/

/*
 *  THESE FUNCTIONS ARE FOR SENDING AND RECIEVING DATA USING THE CPU. THEY ARE VERY USEFUL FOR MANAGING HARDWARE, AND
 *  COMMUNICATING WITH HARDWARE.
 */

/*
 *  THESE FUNCTIONS ARE FOR INPUTTING AND OUTPUTTING BYTEs (8 bits)
 */
static inline void outb(uint32_t port, uint8_t data)
{
    __asm__ volatile("outb %b0, %w1" : : "a" (data), "Nd" (port));
}

static inline uint8_t inb(uint32_t port)
{
    uint8_t data;
    __asm__ volatile("inb %w1, %b0" : "=a" (data) : "Nd" (port));
    return data;
}

/*
 *  THESE FUNCTIONS ARE FOR INPUTTING AND OUTPUTTING WORDs (16 bits)
 */
static inline void outw(uint32_t port, uint16_t data)
{
    __asm__ volatile("outw %w0, %w1" : : "a" (data), "Nd" (port));
}

static inline uint16_t inw(uint32_t port)
{
    uint16_t data;
    __asm__ volatile("inw %w1, %w0" : "=a" (data) : "Nd" (port));
    return data;
}

/*
 *  THESE FUNCTIONS ARE FOR INPUTTING AND OUTPUTTING DWORDs (32 bits)
 */
static inline void outl(uint32_t port, uint32_t data)
{
    __asm__ volatile("outl %0, %w1" : : "a" (data), "Nd" (port));
}

static inline uint32_t inl(uint32_t port)
{
    uint32_t data;
    __asm__ volatile("inl %w1, %0" : "=a" (data) : "Nd" (port));
    return data;
}

#endif