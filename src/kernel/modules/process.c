#include "./process.h"

uint32_t NUMBER_OF_PROCESSES = 0;

process_id_t register_new_process()
{
    NUMBER_OF_PROCESSES++;
    return NUMBER_OF_PROCESSES;
}