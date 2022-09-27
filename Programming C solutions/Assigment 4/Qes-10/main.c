#include <stdio.h>

int swapPointers(int **ptr1 , int **ptr2) {

    int *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}


int main()
{
    int *ptr1,*ptr2,x=5,y=10;
    ptr1 = &x;
    ptr2=&y;
    swapPointers(&ptr1,&ptr2);
    printf("%d\n",*ptr1);

    return 0;
}
