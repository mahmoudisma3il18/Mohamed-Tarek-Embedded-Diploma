#include <stdio.h>

int main()
{
    int EnteredNum,EnteredPow,result = 1;

    printf("Enter Number : ");
    scanf("%d",&EnteredNum);
    printf("Enter Power : ");
    scanf("%d",&EnteredPow);

    for(int i = EnteredPow ; i>0 ; i--)
        result *= EnteredNum;

    printf("%d power %d is : %d\n",EnteredNum,EnteredPow,result);




}
