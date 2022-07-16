#include <stdio.h>

int SuperPower(int number) {

    int result = sqrt(number);

    if(number == (result * result))
        return 1;
    else
        return 0;

}

int main()
{
    printf("%d\n",SuperPower(4));
}
