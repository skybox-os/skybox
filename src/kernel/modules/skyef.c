#include "./skyef.h"
#include <stdbool.h>    /*  THE FILE stdbool.h HASN'T BEEN IMPLEMENTED INTO OUR OPERATING SYSTEM YET, SO WE JUST IMPORT IT FROM
                            THE COMPILER. DON'T WORRY, AS WE CAN STILL USE LIBRARIES LIKE THIS WHILE CREATING A KERNEL.             */
#include "./process.h"

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
        
    }
    else
    {
        return 0x000000FE;
    }
}