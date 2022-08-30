#include <stdio.h>

#define GET_BIT(REG,BIT)  (( REG & (1<<BIT) ) >> BIT)

int main()
{

    unsigned char reg = 0x0f;

    printf("BIT2 Value %d\n",GET_BIT(reg,2));
    printf("BIT5 Value %d\n",GET_BIT(reg,5));


    return 0;
}
