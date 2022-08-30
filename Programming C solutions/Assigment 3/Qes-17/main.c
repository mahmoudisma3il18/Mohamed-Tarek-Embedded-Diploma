#include <stdio.h>

void Swap(int Number1_Size,int* Number1,int Number2_Size,int* Number2) {

    int temp;

    for(int i = 0 ; i  < Number2_Size ; i++) {

        temp = Number1[i];
        Number1[i] = Number2[i];
        Number2[i] = temp;
    }

}


int main()
{

    int i;
        int array1[5] = { 1, 2, 3, 4, 5};
        int array2[5] = { 6, 7, 8, 9, 10};

        Swap(5,array1,5,array2);


        printf("Array1 after the Swap : ");
            /* Print the array1 after call the swap function */
            for(i=0;i<5;i++)
            {
                printf("%d ",array1[i]);
            }
            printf("\n");

    return 0;
}
