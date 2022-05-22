#include "./skybin.h"
#include "./../stdlib/string.h"

/*
 *  THIS FUNCTION IS A BIT EXPERIMENTAL; IT RUNS RAW MACHINE CODE. THIS IS
 *  TO BE USED BY SkyEF.
 */
void RUN_MACHINE_CODE(unsigned char code[])
{
    void *buf;
    int i = ((int (*) (void))buf)();
}