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

uint32_t bytes_to_uint32_lil_endian(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    uint8_t v4[4] = {a, b, c, d};
    uint32_t *allOfIt;
    allOfIt = (uint32_t*)v4;
    return *allOfIt;
}

uint32_t bytes_to_uint32_big_endian(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    uint8_t v4[4] = {d, c, b, a};
    uint32_t *allOfIt;
    allOfIt = (uint32_t*)v4;
    return *allOfIt;
}