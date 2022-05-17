/*  
 *   ____________________________________________________________________________________________________________
 *  |SkyBox, a small operating system that I am designing to be unique from all other operating systems; that    |
 *  |it can run its own apps, and other apps designed for different operating systems. I know it will be a       |
 *  |hard, hard task, but I believe that I can do it.                                                            |
 *  |============================================================================================================|
 *  |The center of the whole operating system is here, although the operating system starts at boot.s, although  |
 *  |there may be different boot.s files, because there are different assembly files for different architectures.|
 *  |____________________________________________________________________________________________________________|
 */

#include "kernel.h"
#include "./drivers/vga.h"
#include "./modules/io.h"
#include "./drivers/keyboard.h"
#include "./utils/ascii.h"

void kernel_entry()
{
    init_term();
    printf("SkyBox, a state-of-the-art operating system designed by Matthew Majfud-Wilinski. Created in May 16th, 2022.\n\n");
}