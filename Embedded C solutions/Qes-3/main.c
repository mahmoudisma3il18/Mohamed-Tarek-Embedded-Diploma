#include <stdio.h>

int main()
{
    int number,result;
    printf("Enter number : ");
    scanf("%d",&number);
    result = (number & 0b1000) >> 3;
    printf("Value of 4th : %d \n",result);
    return 0;
}
