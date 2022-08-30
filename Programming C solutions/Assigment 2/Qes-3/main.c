#include <stdio.h>

#define POSITIVE  1
#define NEGETIVE 0

int isPositiveorNegtive (int number) {

    if(number >= 0)
        return POSITIVE;
    else
        return NEGETIVE;
}

int main()
{
    int Number;
    printf("Enter number : ");
    scanf("%d",&Number);

    if(isPositiveorNegtive(Number) == POSITIVE)
        printf("ITS POSITIVE NUMBER");
    else
        printf("ITS NEGITIVE NUMBER");

    printf("\n");
    return 0;
}
