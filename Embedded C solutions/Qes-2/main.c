#include <stdio.h>


#define CALCULATE_SUM(array,size,sum)\
{\
int i ;\
for(i = 0 ; i < size ; i++)\
{ \
   sum+= array[i];\
}\
}


int main()
{
    int array[5] = {1,2,3,4,5};
    int sum=0;
    CALCULATE_SUM(array,5,sum);

    printf("SUM OF ARRAY : %d\n ",sum);

}
