#include <stdio.h>
#define TRUE  1
#define FALSE 0

int isFirstMultipleOfSecond (int number1 , int number2) {

    if(number1 % number2 == 0)
        return TRUE;
    else
        return FALSE;
}

int main()
{
    int number1,number2;

    printf("Enter First Number : ");
    scanf("%d",&number1);
    printf("Enter Multiple Number : ");
    scanf("%d",&number2);

    if(isFirstMultipleOfSecond(number1,number2) == TRUE)
        printf("%d is multiple of %d",number1,number2);
    else
        printf("%d is not multiple of %d",number1,number2);

    printf("\n");
}
