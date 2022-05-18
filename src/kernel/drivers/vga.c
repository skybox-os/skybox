#include <stdbool.h>
#include <stddef.h>
#include "./../stdlib/stdint.h"
#include "./../stdlib/string.h"
#include "./vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t vga_text_mode_row;
static size_t vga_text_mode_column;
static uint8_t vga_text_mode_color;
static uint16_t* vga_text_mode_buffer;

void vga_text_mode_initialize(void) {
	vga_text_mode_row = 0;
	vga_text_mode_column = 0;
	vga_text_mode_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	vga_text_mode_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			vga_text_mode_buffer[index] = vga_entry(' ', vga_text_mode_color);
		}
	}
}

void vga_text_mode_setcolor(uint8_t color) {
	vga_text_mode_color = color;
}

void vga_text_mode_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	vga_text_mode_buffer[index] = vga_entry(c, color);
}

void vga_text_mode_putchar(char c) {
	unsigned char uc = c;
	vga_text_mode_putentryat(uc, vga_text_mode_color, vga_text_mode_column, vga_text_mode_row);
	if (++vga_text_mode_column == VGA_WIDTH) {
		vga_text_mode_column = 0;
		if (++vga_text_mode_row == VGA_HEIGHT)
			vga_text_mode_row = 0;
	}
}

void vga_text_mode_print_int(int num)
{
	char str_num[digit_count(num)+1];
	_itoa(num, str_num);
	vga_text_mode_writestring(str_num);
}

void vga_text_mode_next_line()
{
	vga_text_mode_row = 0;
	vga_text_mode_column++;
}

void vga_text_mode_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		if(data[i] == '\n')
		{
			vga_text_mode_next_line();
		}
		else
		{
			vga_text_mode_putchar(data[i]);
		}
	}
}

void vga_text_mode_writestring(const char* data) {
	vga_text_mode_write(data, strlen(data));
}
