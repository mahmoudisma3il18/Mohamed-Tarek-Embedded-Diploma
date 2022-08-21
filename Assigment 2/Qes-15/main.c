#include <stdio.h>

int numberOfOnes(unsigned int number) {

    int count = 0 ;

    for (int i = 1; i <= 32; i++) {

        if(!(number % 2 == 0))
            count ++;
        number >>=1;
    }

    return count;
}

int main()
{
    unsigned int EnteredNumber , Result ;
    printf("Enter number : ");
    scanf("%d",&EnteredNumber);
    Result = numberOfOnes(EnteredNumber);
    printf("Number of ones in %d is %d\n",EnteredNumber,Result);
}
