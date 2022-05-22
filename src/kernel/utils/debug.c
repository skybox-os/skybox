#include "./debug.h"
#include "./../config.h"
#include "./../modules/io.h"
#include "./../stdlib/string.h"

void DEBUG(char* TXT)
{
    #ifdef DEBUG_MODE
        char* a = "[DEBUG]: ";
        strcpy(a, TXT);
        printf(a);
    #endif
}