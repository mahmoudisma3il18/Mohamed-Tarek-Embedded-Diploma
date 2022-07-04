#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

int isPowerOfTwo(int number) {

    int flag = FALSE;

    for( int i = 0 ; i < number;i++) {
        if(number == pow(2,i))
        {
            flag = TRUE;
            break;
        }
    }

    return flag;
}

int main()
{
    int number ;
    printf("Enter number : ");
    scanf("%d",&number);

    if(isPowerOfTwo(number) == TRUE)
        printf("%d is power of two \n",number);
    else
        printf("Its not power of two\n");
}
