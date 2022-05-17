#include "./keyboard.h"
#include "./../../arch/x86/ports.h"

/*
 *  THIS C FILE IS FOR RECIEVING INPUT FROM THE KEYBOARD, USING
 *  THE I/O PORT FUNCTIONS THAT ARE LOCATED IN THE arch/x86 FOLDER.
 *  WHEN INPUT IS RECIEVED, IT DOESN'T MEAN THAT IT IS PRINTED OUT
 *  TO THE SCREEN. SO WE WILL HAVE TO LATER IMPLEMENT A FUNCTION
 *  THAT PRINTS WHAT IS TYPED TO THE TERMINAL WHEN RECIEVING
 *  INPUT.
 */

/*
 *  THIS FUNCTION RETURNS THE KEYCODE OF THE KEY PRESSED IN THE
 *  KEYBOARD.
 */
char input_keycode()
{
    char ch = 0;
    while((ch = inb(0x60)) != 0)
    {
        if(ch > 0)
        return ch;
    }
    return ch;
}