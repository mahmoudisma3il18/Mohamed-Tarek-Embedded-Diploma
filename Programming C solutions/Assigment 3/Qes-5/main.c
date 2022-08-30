#include <stdio.h>

int LinearSearch(int numbers[] , int numbers_size , int number) {

    int index = -1;

    for(int i = 0 ; i < numbers_size ; i++) {
        if(numbers[i] == number){
            index = i ;
            break;
        }
    }

    return index;
}

int main()
{
   int numbers[] =  {1,2,3,4,4,4} ;
   printf("index = %d \n",LinearSearch(numbers,6,4));

}
