#include <stdio.h>

int  LinearSearch(int *numbers, int numbers_size , int number) {

    int index = -1;

    for(int i = numbers_size - 1 ; i >= 0 ; i--){
        if(number == numbers[i]){
            index = i;
            break;
        }
    }

    return index;
}

int main()
{
    int numbers[] =  {1,2,3,4,4,4} ;
    printf("Index = %d \n",LinearSearch(numbers,6,6));
    return 0;
}
