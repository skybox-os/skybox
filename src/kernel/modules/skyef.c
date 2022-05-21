#include "./skyef.h"
#include <stdbool.h>    /*  THE FILE stdbool.h HASN'T BEEN IMPLEMENTED INTO OUR OPERATING SYSTEM YET, SO WE JUST IMPORT IT FROM
                            THE COMPILER. DON'T WORRY, AS WE CAN STILL USE LIBRARIES LIKE THIS WHILE CREATING A KERNEL.             */
#include "./process.h"
#include "./io.h"

/*
 *  THE FULL DOCUMENTATION OF THE INSTRUCTIONS AND WHAT
 *  THEY DO ARE LOCATED IN THE /doc/ FOLDER IN THIS
 *  CODE REPOSITORY.
 */

bool check_skyef(unsigned char CONTENTS[])
{
    if(CONTENTS[0] == 0x53 && CONTENTS[1] == 0x45 && CONTENTS[2] == 0x46)
    {
        return true;
    }
    else
    {
        return false;
    }
}

process_exit_code_t execute_skyef(unsigned char CONTENTS[]/*, process_id_t *PROCESS_ID*/)
{
    //PROCESS_ID = register_new_process();
    if(check_skyef(CONTENTS) == true)
    {
        /*
         *  THE VARIABLE MEMORY_WE_NEED IS TO BE USED IN THE FUTURE WHEN WE IMPLEMENT
         *  A FUNCTION FOR ALLOCATING MEMORY. FOR NOW, WE MUST INTRODUCE SOME REGULAR
         *  INSTRUCTIONS FOR SkyEF PROGRAMS.
         */
        uint32_t MEMORY_WE_NEED = 0;
        MEMORY_WE_NEED = bytes_to_uint32_lil_endian(CONTENTS[3], CONTENTS[4], CONTENTS[5], CONTENTS[6]);
        /*
         *  NOW WE NEED TO FIND A WAY TO ALLOCATE THE MEMORY BY USING THE
         *  NUMBER OF MEMORY NEEDED WHICH IS STORED IN THE VARIABLE
         *  CALLED MEMORY_WE_NEED.
         */
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
                BYTES_READ = BYTES_READ + 5;
                uint32_t full_number = bytes_to_uint32_lil_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                unsigned char *addr = (unsigned char *)full_number;
                *addr = CONTENTS[BYTES_READ + 5];
            }
            BYTES_READ++;
        }
    }
    else
    {
        return 0x000000FE;
    }
}