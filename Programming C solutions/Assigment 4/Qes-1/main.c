#include <stdio.h>



int main()
{
    int ArrayOfNumbers[5];
    int *ptrToArray;
    int sum = 0;

    for(int i = 0 ; i < 5 ; i++) {
        printf("Enter Array[%d] : ",i);
        scanf("%d",&ArrayOfNumbers[i]);
    }

    ptrToArray = ArrayOfNumbers;

   for(int i = 0 ; i < 5 ; i++,ptrToArray++)
       sum += (*ptrToArray);

   printf("Sum of array is %d \n",sum);


    return 0;
}
