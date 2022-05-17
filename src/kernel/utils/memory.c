#include "./memory.h"
#include "./../stdlib/stdint.h"

uint32_t last_memory_address_that_was_allocated = 0;


/*
 *  I'M NOT SURE IF I UNDERSTAND WHAT MEMORY ALLOCATION IS, BUT I HAVE TRIED MY BEST TO MAKE MY OWN IMPLEMENTATION
 *  OF kmalloc() IN C... BASICALLY, ALL IT DOES, IS RETURN ME A POINTER TO THE ADDRESS WHERE THE ALLOCATED MEMORY
 *  STARTS.
 */
void *kmalloc(size_t size)
{
    int j = last_memory_address_that_was_allocated;
    for(int i = last_memory_address_that_was_allocated; i <= last_memory_address_that_was_allocated + size; i++)
    {
        *(int *)i = 0;
    }
    return j;
}


/*
 *  I'M NOT SURE IF I DID THIS ONE CORRECTLY EITHER, BUT I TRIED MAKING THIS FUNCTION CLEAR / DE-ALLOCATE MEMORY, BY
 *  JUST USING THE ADDRESS OF WHERE THE ALLOCATED MEMORY STARTS, AND THR SIZE OF THE ALLOCATED MEMORY... OR REALLY
 *  ALL THIS DOES IS SIMPLY SET THE VALUE OF AN AREA OF MEMORY TO ALL ZEROES.
 */
void free(uint32_t pos, size_t size)
{
    for(int i = pos; i <= size + pos; i++)
    {
        *(int *)i = 0;
    }
}