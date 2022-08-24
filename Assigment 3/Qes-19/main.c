#include <stdio.h>

int Compare (int numbers_size,int *number1,int *number2) {

    for(int i = 0 ; i < numbers_size ; i++) {

        if(number1[i] != number2[i])
            return 1;
    }

    return 0;
}

int main()
{
    int numbers1[] = {1,4,3};
    int numbers2[] = {1,2,3};

    printf("%d\n",Compare(3,numbers1,numbers2));
    return 0;
}
