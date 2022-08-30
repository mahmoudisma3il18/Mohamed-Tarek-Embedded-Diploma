#include <stdio.h>


void swap(int *x , int *y) {

    int temp = *x;
    *x = *y ;
    *y = temp;
}

void SelectionSort(int numbers[],int numbers_size) {

    int min_index;

    for(int i = 0 ; i < numbers_size - 1 ; i++) {

        min_index = i ;

        for(int j = i + 1 ; j < numbers_size ; j++)
            if(numbers[min_index] > numbers[j])
                swap(&numbers[j],&numbers[min_index]);
    }

}

int main()
{
    int numbers[] = {4,2,1,3};
    SelectionSort(numbers,4);

    for(int i = 0 ; i < 4 ; i++ )
        printf("%d\t",numbers[i]);

    printf("\n");
    return 0;
}
