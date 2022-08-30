#include <stdio.h>

int main()
{
    int EnteredNum,ReversedNum = 0,remainder = 0;

    printf("Enter Number : ");
    scanf("%d",&EnteredNum);

    while(EnteredNum > 0) {

        remainder = EnteredNum % 10 ;

        ReversedNum = (ReversedNum * 10 ) + remainder ;

        EnteredNum /= 10 ;

    }

    printf("Reversed Number is : %d\n",ReversedNum);




}
