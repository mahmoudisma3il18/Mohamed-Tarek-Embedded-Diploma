#include <stdio.h>

int main()
{
    int EnteredNum,counter = 0 ;

    printf("Enter Number : ");
    scanf("%d",&EnteredNum);

    while (EnteredNum > 0) {

        counter ++;

        EnteredNum /= 10;

    }

    printf("Number of digits is %d \n",counter);
}
