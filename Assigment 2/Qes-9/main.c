#include <stdio.h>

int Swap (int number) {
    int reminader,result;
    reminader = number % 10 ;
    number /= 10;

    result = (reminader * 10) + number;
    return result;
}

int main()
{
    int number ;
    printf("Enter Number : ");
    scanf("%d",&number);

    printf("%d\n",Swap(number));

}
