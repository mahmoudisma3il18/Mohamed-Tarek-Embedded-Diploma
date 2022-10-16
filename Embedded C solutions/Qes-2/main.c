#include <stdio.h>

int sum = 0;

#define sumOfArray(Array,size) \
{ \
int i = 0 ; \
for(i;i<size;i++){ \
sum+= Array[i]; \
} \
    }
int main()
{
    int array[] = {1,2,3,4,5};
    sumOfArray(array,5);
    printf("Sum : %d \n",sum);

}
