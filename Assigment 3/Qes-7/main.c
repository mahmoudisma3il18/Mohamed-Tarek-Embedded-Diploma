#include <stdio.h>

int ArthemticSeries(int term) {


    int result = 1 + (2)*(term - 1);

    return result;

}

int main()
{
    printf("the 100th term = %d\n",ArthemticSeries(100));
    return 0;
}
