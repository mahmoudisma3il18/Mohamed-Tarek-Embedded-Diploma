#include <stdio.h>

void swap(int* x , int* y) {

    int temp = *x;
    *x = *y;
    *y = temp;

}

void BubbleSort(int numbers[],int numbers_size) {

    for(int i = 0 ; i < numbers_size - 1 ; i++)
        for(int j = 0 ; j < numbers_size - i - 1 ; j++)
            if(numbers[j] > numbers[j+1])
                swap(&numbers[j],&numbers[j+1]);
}

int main()
{
    int numbers[3] = {3,1,2};
    BubbleSort(numbers,3);
    for(int i = 0 ; i<3;i++ )
        printf("%d \t",numbers[i]);

    printf("\n");
}
