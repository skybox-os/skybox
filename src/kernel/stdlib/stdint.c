#include "./stdint.h"
#include "./string.h"

void _itoa(int num, char *number)
{
    int dgcount = digit_count(num);
    int index = dgcount - 1;
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    }
    else
    {
        while(num != 0){
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

uint32_t digit_count(int num)
{
    uint32_t count = 0;
    if(num == 0)
        return 1;
        while(num > 0)
    {
        count++;
        num = num/10;
    }
    return count;
}

uint32_t bytes_to_uint32(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    uint8_t byte_array[4] = {a, b, c, d};
    uint32_t output = 0;
    memcpy(output, byte_array, 4);
    return output;
}