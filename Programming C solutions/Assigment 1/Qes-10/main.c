#include <stdio.h>

int main()
{
    char operation;
    int num1,num2;

    printf("Enter (+ or – or * or /) : ");
    scanf("%c",&operation);
    printf("Enter number1 : ");
    scanf("%d",&num1);
    printf("Enter number2 : ");
    scanf("%d",&num2);

    switch (operation) {

    case '+' :
        printf("%d + %d = %d",num1,num2,num1+num2);
        break;

    case '-' :
        printf("%d - %d = %d",num1,num2,num1-num2);
        break;

    case '*' :
        printf("%d * %d = %d",num1,num2,num1*num2);
        break;

    case '/' :
        printf("%d / %d = %d",num1,num2,num1/num2);
        break;

    default :
        printf("Enter right operation");


    }
    printf("\n");
}
