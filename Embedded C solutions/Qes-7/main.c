#include <stdio.h>

int clearBit(int number,char postion){
    return (number & ~(1<<postion));
}

int main()
{
    int number = 3;
    int result = clearBit(number , 0);
    printf("New number : %d\n",result);
    return 0;
}
