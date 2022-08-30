#include <stdio.h>
#include <math.h>

int isCube (int number) {

    int CubicNumber =cbrt(number);
    int CubeNumber = pow(CubicNumber,3);

    if(number == CubeNumber)
        return 0;
    else
        return 1;

}

int main()
{
    printf("%d\n",isCube(1));
}
