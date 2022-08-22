#include <stdio.h>
#include "math.h"

int GeomtricSeries(int term) {

    int result = pow(3,term-1);

    return result;
}

int main()
{
    int EnteredValue;
    printf("Enter the Term : ");
    scanf("%d",&EnteredValue);

    printf("The %dTh term eqauls = %d\n",EnteredValue,GeomtricSeries(EnteredValue));
    return 0;
}
