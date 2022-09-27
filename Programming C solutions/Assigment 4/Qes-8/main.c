#include <stdio.h>

#define SIZE_OF_ARRAY  5

void Swap (int *ptr1,int *ptr2) {

    int temp = 0 ;

    for(int i = 0  ; i < SIZE_OF_ARRAY ; i++ ){
       temp = *(ptr1 + i);
       *(ptr1 +i) = *(ptr2 + i);
       *(ptr2 +i) = temp;
    }


}

int main()
{
    int Array1[] = {1,2,3,4,5};
    int Array2[] = {0,2,6,5,8};

    Swap(Array1,Array2);
    for(int i = 0 ; i < SIZE_OF_ARRAY ; i++)
        printf("Array2[%d] = %d \n",i,Array2[i]);


    return 0;
}
