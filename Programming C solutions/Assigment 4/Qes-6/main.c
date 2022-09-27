#include <stdio.h>

#define SIZE_OF_ARRAY     5

int main()
{
    int array[SIZE_OF_ARRAY] = {1,2,3,4,10};
    int i,MAX,*ptrArray[SIZE_OF_ARRAY];

    for(i = 0 ; i < SIZE_OF_ARRAY ; i++)
        ptrArray[i] = &array[i];

    for(i = 0 ; i < SIZE_OF_ARRAY ; i++)
        printf("*ptrArray[%d] = %d \n",i,*ptrArray[i]);

    MAX = *ptrArray[0];
    for(i = 0 ; i < SIZE_OF_ARRAY ; i++) {

        if(*ptrArray[i] >= MAX)
            MAX = *ptrArray[i];
    }

    printf("Max of Array is %d \n",MAX);


}


