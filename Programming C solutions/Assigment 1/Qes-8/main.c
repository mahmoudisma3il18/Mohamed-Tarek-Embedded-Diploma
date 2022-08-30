#include <stdio.h>
#include <math.h>

int main()
{
    int number,sqrtnumber;
    do {
        printf("please enter postive value : ");
        scanf("%d",&number);

    } while(number < 0);

    sqrtnumber = (int)sqrt(number);

    if(number == (sqrtnumber * sqrtnumber))
        printf("Its perfect sqaure\n");
    else
        printf("Its not perfect sqaure\n");
}
