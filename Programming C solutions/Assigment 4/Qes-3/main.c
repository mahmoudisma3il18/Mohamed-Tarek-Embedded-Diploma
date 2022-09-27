#include <stdio.h>

void RevreseArray(int *Array) {

    int temp = 0;

    for(int i = 0,j=9; i<j ; i++,j--) {

        temp = *(Array + i);
        *(Array + i) = *(Array + j);
        *(Array + j) = temp;

    }


}

int main()
{
   int Array[10] = {1,2,3,4,5,6,7,8,9,10};
   RevreseArray(Array);
   for(int i = 0 ; i <10 ; i++)
       printf("%d\t",Array[i]);
    return 0;
}
