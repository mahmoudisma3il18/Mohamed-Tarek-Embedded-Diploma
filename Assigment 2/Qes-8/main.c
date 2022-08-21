#include <stdio.h>

#define Prime    1
#define NotPrime 0


void PrimeNumbers (int number1,int number2) {

    int PrimeFlag = Prime;

    for(int i = number1 ; i <= number2 ; i++) {

           for (int j = 2 ; j <= (number2/2) ; j++)
           {
               if((i % j) == 0) {
                  PrimeFlag = NotPrime;
                 break;
              }
           }

           if(PrimeFlag)
               printf("%d\t",i);
           else
               PrimeFlag = Prime;
       }
    printf("\n");
    }


int main()
{
    int number1,number2;
    printf("Enter First Number : ");
    scanf("%d",&number1);
    printf("Enter Second Number : ");
    scanf("%d",&number2);

    PrimeNumbers(number1,number2);
}
