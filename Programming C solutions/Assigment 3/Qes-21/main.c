#include <stdio.h>

int OutputArray[256] = {0};

int* PrintInclusize(int LowerValue,int UpperValue,int *Array_Size) {

    *Array_Size = 0 ;

    if(LowerValue > UpperValue) {
        OutputArray[0] = 0xFF;
        OutputArray[1] = 0xFF;
        *Array_Size = 2 ;
    }

    else {

        for(int i = UpperValue ; i>= LowerValue ; i--) {

            OutputArray[*Array_Size] = i ;
            (*Array_Size)++;
        }
    }

    return OutputArray;

}

int main()
{
    int count;
        int n1 = 5,n2=10;
        int *ptr;
        int arr_size_used = 0;

        ptr = PrintInclusize(n1,n2,&arr_size_used);

        printf("Output Array = ");

        /* start looping from 0 to the last used element in the array */
        for(count=0;count<arr_size_used;count++)
        {
            /* access the global array using the ptr */
            printf("%d ",ptr[count]);
        }
        printf("\nOutput Array Size = %d",arr_size_used);
    return 0;
}
