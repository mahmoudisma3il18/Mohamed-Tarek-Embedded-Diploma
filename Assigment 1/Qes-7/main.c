#include <stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Enter number1 : ");
    scanf("%d",&num1);
    printf("Enter number2 : ");
    scanf("%d",&num2);
    printf("Enter number2 : ");
    scanf("%d",&num3);

    if(num1>num2) {

        if(num1 > num3)
            printf("Greatest number is %d",num1);
        else
            printf("Greatest number is %d",num3);

    }

    else {
        if (num2 > num3)
            printf("Greatest number is %d",num2);
        else
            printf("Greatest number is %d",num3);
    }

    printf("\n");
}
