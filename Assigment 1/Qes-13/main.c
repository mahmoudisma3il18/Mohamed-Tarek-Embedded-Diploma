#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main()
{
    int EnteredNum;
    char PRIME_FLAG = TRUE;
    do {

        printf("Enter postiver number only : ");
        scanf("%d",&EnteredNum);

    } while(EnteredNum<0);

    if (EnteredNum == 1)
        PRIME_FLAG = FALSE;

    for (int i = 2 ;i<=(EnteredNum/2) ; i++)
    {
        if ((EnteredNum % i) == 0) {
            PRIME_FLAG = FALSE;
            break;
        }

    }

    if (PRIME_FLAG == FALSE)
        printf("Its not prime number\n");
    else
        printf("Its prime number\n");



}
