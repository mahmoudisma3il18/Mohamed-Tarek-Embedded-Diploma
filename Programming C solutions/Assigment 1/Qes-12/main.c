#include <stdio.h>

int main()
{
    int EnteredNum,FactNum = 1;
    printf("Enter the number : ");
    scanf("%d",&EnteredNum);

    for(int i = EnteredNum ;i>0;i--) {

        FactNum *= i ;
    }

    printf("Factorial %d is : %d\n",EnteredNum,FactNum);

}
