#include <stdio.h>


#define Error  0
#define Succes 1

int removeDuplicates(int arr_old[], int n_old, int arr_new[], int *n_new) {

    *n_new = 0;
    arr_new[0] = 0;

    if(n_old == 0)
        return Error;

    for(int i = 0 ; i<n_old;i++){

        for ( int j = 0 ; j<= (*n_new) ; j++) {
            if(arr_new[j] == arr_old[i])
                break;
            else {
                arr_new[*n_new] = arr_old[i];
                (*n_new)++;
            }
        }

    }

    return Succes;
}



int main()
{
    int arr1[11] = {1,2,3,3,3,4,4,5,5,5,3};
        int arr2[11];
        int arr2_usedSize = 0;
        int ret,i;

        /* the function shall remove the repeated numbers in arr1 and create a new array arr2 with size equals to arr2_usedSize */
        ret = removeDuplicates(arr1,11,arr2,&arr2_usedSize);

        if(ret == Succes)
        {
            for(i=0;i<arr2_usedSize;i++)
            {
                printf("%d \t",arr2[i]);
            }
        }
}
