#include <stdio.h>

int Calculator(int number1,int number2,char operation) {

    switch (operation) {
    case '+':
        return (number1 + number2);
        break;
    case '-':
        return (number1 - number2);
        break;
    case '*':
        return (number1 * number2);
        break;
    case '/':
        return (number1 / number2);
        break;

    }
}

int main()
{

    int number1,number2,result;
    char operation;
    printf("Enter number1 : ");
    scanf("%d",&number1);
    printf("Enter number2 : ");
    scanf("%d",&number2);


    printf("Enter operation : ");
    scanf("\n");
    scanf("%c",&operation);

    result =  Calculator(number1,number2,operation);

    printf("(%d) %c (%d) = %d\n",number1,operation,number2,result);


}
