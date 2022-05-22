#include "./skyef.h"
#include <stdbool.h>    /*  THE FILE stdbool.h HASN'T BEEN IMPLEMENTED INTO OUR OPERATING SYSTEM YET, SO WE JUST IMPORT IT FROM
                            THE COMPILER. DON'T WORRY, AS WE CAN STILL USE LIBRARIES LIKE THIS WHILE CREATING A KERNEL.             */
#include "./process.h"
#include "./io.h"
#include "./../utils/memory.h"

/*
 *  THE FULL DOCUMENTATION OF THE INSTRUCTIONS AND WHAT
 *  THEY DO ARE LOCATED IN THE /doc/ FOLDER IN THIS
 *  CODE REPOSITORY.
 */

bool check_skyef(unsigned char CONTENTS[])
{
    if(CONTENTS[0] == 0x53 && CONTENTS[1] == 0x45 && CONTENTS[2] == 0x46)
    {
        DEBUG("THE SkyEF CONTENTS ARE VALID...\r\n");
        return true;
    }
    else
    {
        DEBUG("THE SkyEF CONTENTS ARE NOT VALID...\r\n");
        return false;
    }
}

process_exit_code_t execute_skyef(unsigned char CONTENTS[], process_id_t *PROCESS_ID)
{
    DEBUG("CREATED A NEW PROCESS...\r\n");
    PROCESS_ID = register_new_process();
    if(check_skyef(CONTENTS) == true)
    {
        /*
         *  THE VARIABLE MEMORY_WE_NEED IS TO BE USED IN THE FUTURE WHEN WE IMPLEMENT
         *  A FUNCTION FOR ALLOCATING MEMORY. FOR NOW, WE MUST INTRODUCE SOME REGULAR
         *  INSTRUCTIONS FOR SkyEF PROGRAMS.
         */
        uint32_t MEMORY_WE_NEED = 0;
        MEMORY_WE_NEED = bytes_to_uint32_big_endian(CONTENTS[3], CONTENTS[4], CONTENTS[5], CONTENTS[6]);
        /*
         *  FOR NOW, WE ARE ALLOCATING MEMORY BY SIMPLY CREATING A UNSIGNED
         *  CHAR ARRAY. THAT CAN ONLY BE USED BY THE PROGRAM ITSELF, AND NO
         *  OTHER PROGRAM.
         */
        uint32_t BYTES_READ = 7;
        unsigned char ALLOCATED_MEMORY[MEMORY_WE_NEED];
        for(;;)
        {
            if(CONTENTS[BYTES_READ] == 0xFF)
            {
                DEBUG("SkyEF PROGRAM BEING HALTED...\r\n");
                break;
            }
            else if(CONTENTS[BYTES_READ] == 0xFE)
            {
                DEBUG("TEST INSTRUCTION BEING USED...\r\n");
                printf("Hello, world!\r\n");
            }
            else if(CONTENTS[BYTES_READ] == 0x01)
            {
                BYTES_READ = BYTES_READ + 5;
                DEBUG("SETTING MEMORY CONTENTS...\r\n");
                uint32_t full_number = bytes_to_uint32_big_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                out_memb(full_number, CONTENTS[BYTES_READ + 5]);
            }
            else if(CONTENTS[BYTES_READ] == 0x02)
            {
                BYTES_READ = BYTES_READ + 4;
                uint32_t full_number = bytes_to_uint32_big_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
            }
            else if(CONTENTS[BYTES_READ] == 0x03)
            {
                BYTES_READ = BYTES_READ + 8;
                DEBUG("SETTING A 32-BIT VARIABLE...\r\n");
                uint32_t full_number = bytes_to_uint32_big_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                ALLOCATED_MEMORY[full_number] = 4;  /* TELL THEM THAT THIS VALUE IS 8 BYTES LONG. */
                ALLOCATED_MEMORY[full_number + 1] = CONTENTS[BYTES_READ + 5];
                ALLOCATED_MEMORY[full_number + 2] = CONTENTS[BYTES_READ + 6];
                ALLOCATED_MEMORY[full_number + 3] = CONTENTS[BYTES_READ + 7];
                ALLOCATED_MEMORY[full_number + 4] = CONTENTS[BYTES_READ + 8];
            }
            else if(CONTENTS[BYTES_READ == 0x05])
            {
                BYTES_READ = BYTES_READ + 5;
                DEBUG("SETTING A 8-BIT VARIABLE...\r\n");
                uint32_t full_number = bytes_to_uint32_big_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                ALLOCATED_MEMORY[full_number] = 1;
                ALLOCATED_MEMORY[full_number + 1] = CONTENTS[BYTES_READ + 5];
            }
            else if(CONTENTS[BYTES_READ] == 0x04)
            {
                BYTES_READ = BYTES_READ + 4;
                DEBUG("PRINTING A VARIABLE...\r\n");
                uint32_t full_number_a = bytes_to_uint32_big_endian(CONTENTS[BYTES_READ + 1], CONTENTS[BYTES_READ + 2], CONTENTS[BYTES_READ + 3], CONTENTS[BYTES_READ + 4]);
                if(ALLOCATED_MEMORY[full_number_a] == 4)
                {
                    DEBUG("PRINTING A 32-BIT VARIABLE'S CONTENTS...\r\n");
                    uint32_t full_number_b = bytes_to_uint32_big_endian(ALLOCATED_MEMORY[full_number_a + 1], ALLOCATED_MEMORY[full_number_a + 2], ALLOCATED_MEMORY[full_number_a + 3], ALLOCATED_MEMORY[full_number_a + 4]);
                    printn(full_number_b);
                }
                else if(ALLOCATED_MEMORY[full_number_a] == 1)
                {
                    DEBUG("PRINTING A 8-BIT VARIABLE'S CONTENTS...\r\n");
                    uint8_t full_number_b = ALLOCATED_MEMORY[full_number_a + 1];
                    printn(full_number_b);
                }
            }
            BYTES_READ++;
        }
    }
    else
    {
        return 0x000000FE;
    }
}