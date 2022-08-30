#include <stdio.h>

#define EVEN 0
#define ODD  1

int isEvenOrOdd(int number) {

    if((number % 2 ) == 0)
        return EVEN;
    else
        return ODD;
}

int main()
{
    int Number;
    printf("Enter number : ");
    scanf("%d",&Number);

    if(isEvenOrOdd(Number) == EVEN)
        printf("Its even number");
    else
        printf("Its odd number");

    printf("\n");

}
