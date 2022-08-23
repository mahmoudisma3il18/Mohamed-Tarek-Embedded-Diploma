#include <stdio.h>

void ReverseArray (int* numbers , int numbers_size) {

    int j = numbers_size - 1;
    int temp;

    for(int i = 0 ; i<j ; i++,j--) {

        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

}

int main()
{
   int numbers[5] = {1,2,3,4,5};
   ReverseArray(numbers,5);
   for(int i = 0 ; i < 5; i++)
       printf("%d\t",numbers[i]);
   printf("\n");
    return 0;
}
