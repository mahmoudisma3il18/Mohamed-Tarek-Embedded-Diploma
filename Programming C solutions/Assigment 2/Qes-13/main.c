#include <stdio.h>

int floatFloor(float number1 , float number2) {
    int result;

    result = number1 + number2 ;

    return result;
}

int main()
{
    float number1,number2;

    printf("Enter number 1 : ");
    scanf("%f",&number1);
    printf("Enter number 2 : ");
    scanf("%f",&number2);

    printf("floor(%0.1f + %0.1f ) = %d \n",number1,number2,floatFloor(number1,number2));
}
