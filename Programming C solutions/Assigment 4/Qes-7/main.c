#include <stdio.h>

void Swap(int *ptr1 , int *ptr2) {

    *ptr1 = *ptr1 ^ *ptr2 ;
    *ptr2 = *ptr1 ^ *ptr2 ;
    *ptr1 = *ptr1 ^ *ptr2;


}

int main()
{
    int x = 5 , y = 10;
    void (*swap)(int*,int*);
    swap = Swap;
    (*swap)(&x,&y);
    printf("X = %d \n",x);

    return 0;
}
