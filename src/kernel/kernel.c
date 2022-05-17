#include "kernel.h"
#include "./drivers/vga.h"
#include "./modules/io.h"
#include "./drivers/keyboard.h"
#include "./utils/ascii.h"

void kernel_entry()
{
    init_term();
    printf("Skybox, a state-of-the-art operating system designed by Matthew Majfud-Wilinski. Created in May 16th, 2022.\n\n");
}