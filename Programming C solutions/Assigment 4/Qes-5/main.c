#include <stdio.h>

void copyArray(int *ptr1,int*ptr2,int size) {

    int temp = 0 ;

    for(int i = 0 ; i  < size ; i++,ptr1++,ptr2++){

        *ptr2 = *ptr1;
    }


}

int main()
{
    int Array1[3] = {1,2,3};
    int Array2[3] = {0,0,0};
    copyArray(Array1,Array2,3);
    for(int i = 0 ; i < 3 ; i++)
    printf("Array[%d] = %d \n",i,Array2[i]);
    return 0;
}
