#include <stdio.h>

int main()
{
    int num1,num2;
    printf("Enter number1 : ");
    scanf("%d",&num1);
    printf("Enter number2 : ");
    scanf("%d",&num2);

    if(num1 == num2 )
        printf("Both numbers are eqaul\n");

     else {
            if(num1 > num2)
                printf("%d is greater than %d\n",num1,num2);
            else
                printf("%d is greater than %d\n",num2,num1);
        }
}
