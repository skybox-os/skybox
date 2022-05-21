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
#include "./modules/time.h"
#include "./stdlib/stdint.h"
#include "./modules/skyef.h"
#include "./modules/process.h"

/*
 *  IMPORTANT TIPS FOR SKYBOX DEVELOPMENT!
 *
 *  WHEN USING SERIAL MODE (DEFAULT I/O MODE), **PLEASE** USE \r\n TO MAKE
 *  NEW LINES, BECAUSE OTHERWISE SOME OTHER ISSUES MAY HAPPEN.
 *
 *  ALSO TAKE NOTE THAT x86 PROCESSORS ARE LITTLE-ENDIAN.
 */

void kernel_entry()
{
    init_term();
    printf("\r\nSkybox (C) 2022, created by Matthew Majfud-Wilinski.\r\nSkybox is a state-of-the-art operating system designed for simplicity, while being able to do advanced things.\r\n");
    unsigned char a[] = {0x53, 0x45, 0x46, 0b00000000, 0b00000000, 0b00000000, 0b11111111, 0x01, 0b10000000, 0b00000000, 0b00000000, 0b11100001, 32, 0x02, 0b10000000, 0b00000000, 0b00000000, 0b11100001, 0xFE, 0xFF};
    process_exit_code_t b;
    process_id_t c;
    b = execute_skyef(a/*, c*/);
    in_memb(bytes_to_uint32_lil_endian(0b10000000, 0b00000000, 0b00000000, 0b11100001));
}