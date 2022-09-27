#include <stdio.h>

int SmallestArray(int *Array,int sizeOfArray) {

    int smallest = *(Array);

    for(int i = 0 ; i < sizeOfArray ; i++,Array++)
    {
        if(smallest>= *(Array))
            smallest = *(Array);
    }

    return smallest;

}

int main()
{
    int Array[5] = {5,4,2,0,3};
    printf("Smallest Number in Array is  : %d\n",SmallestArray(Array,5));
    return 0;
}
