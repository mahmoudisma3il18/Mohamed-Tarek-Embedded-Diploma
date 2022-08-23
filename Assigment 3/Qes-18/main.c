#include "stdio.h"

int ConsecutiveOccurrence(int *numbers , int numbers_size,int number) {

    int count = 0,max_count = 0;

    for(int i = 0 ;i<numbers_size;i++) {

        if(number == numbers[i] ){
            count++;
            if (max_count < count)
                max_count = count;
        }
        else
           count = 0;

    }

    return max_count;
}

int main()
{

    int arr[17] = {1,1,2,2,3,3,3,3,4,4,4,4,3,3,3,3,3};

    printf("The consecutive of  3 is %d\t",  ConsecutiveOccurrence(arr,17,3));

    return 0;
}
