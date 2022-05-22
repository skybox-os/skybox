#include "./debug.h"
#include "./../config.h"
#include "./../modules/io.h"
#include "./../stdlib/string.h"

/*
 *  THIS FUNCTION IS USEFUL FOR SEEING EVERYTHING THAT IS HAPPENING IN OUR
 *  OPERATING SYSTEM. IT IS RECOMMENDED TO DISABLE DEBUG MODE IN config.h
 *  TO USE SkyboxOS NORMALLY.
 */
void DEBUG(char* TXT)
{
    #ifdef DEBUG_MODE
    char* a = "[DEBUG]: ";
    strcpy(a, TXT);
    printf(a);
    #endif
}

/*
 *  THIS FUNCTION IS FOR PRINTING ERRORS, AND THEN HALTING THE COMPUTER.
 *  DO NOT USE THIS FUNCTION FOR ERRORS THAT AREN'T SERIOUS OR CRITICAL.
 */
void ERROR(char* TXT)
{
    char* a = "[ERROR]: ";
    strcpy(a, TXT);
    printf(a);
    asm volatile("hlt");
}