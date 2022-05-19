#include "./skyef.h"
#include <stdbool.h>    /*  THE FILE stdbool.h HASN'T BEEN IMPLEMENTED INTO OUR OPERATING SYSTEM YET, SO WE JUST IMPORT IT FROM
                            THE COMPILER. DON'T WORRY, AS WE CAN STILL USE LIBRARIES LIKE THIS WHILE CREATING A KERNEL.             */
#include "./process.h"
#include "./io.h"

bool check_skyef(char* CONTENTS)
{
    if(CONTENTS[0] == 'S' && CONTENTS[1] == 'E' && CONTENTS[2] == 'F')
    {
        return true;
    }
    else
    {
        return false;
    }
}

process_exit_code_t execute_skyef(char* CONTENTS, process_id_t *PROCESS_ID)
{
    PROCESS_ID = register_new_process();
    if(check_skyef(CONTENTS) == true)
    {
        uint32_t MEMORY_WE_NEED = 0;
        MEMORY_WE_NEED = bytes_to_uint32_lil_endian(CONTENTS[3], CONTENTS[4], CONTENTS[5], CONTENTS[6]);
        uint32_t *PROG_MEM_ADDRESS = kmalloc(MEMORY_WE_NEED);
        uint32_t BYTES_READ = 7;
        for(;;)
        {
            if(CONTENTS[BYTES_READ] == 0xFF)
            {
                break;
            }
            else if(CONTENTS[BYTES_READ] == 0xFE)
            {
                printf("Hello, world!");
            }
            else if(CONTENTS[BYTES_READ] == 0x01)
            {
                BYTES_READ = BYTES_READ + 6;
                uint32_t full_number = bytes_to_uint32_lil_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                *(int *)full_number = CONTENTS[BYTES_READ + 5];
            }
            BYTES_READ++;
        }
    }
    else
    {
        return 0x000000FE;
    }
}