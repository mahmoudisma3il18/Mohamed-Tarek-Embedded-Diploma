#include <stdio.h>

int main()
{
    int number  = 0xFFFFAAAA,temp1,temp2;

    temp1 = ((number) & 0xFFFF) << 16;
    temp2 = (number & 0xFFFF0000) >>16;
    number = temp1 | temp2;
    printf("%X\n",number);
    return 0;
}
