#include <stdio.h>

int FallingEdgCounter(unsigned char pinReading){
    static int counter = 0;
    static char previousState = 0;

    if((pinReading == 0) && (previousState == 1))
        counter++;
    previousState = pinReading;

    return counter;
}

int main()
{
    unsigned char count = 0;

        count = FallingEdgCounter(1);

        count = FallingEdgCounter(1);

        /* falling edge the count should be equal 1 */
        count = FallingEdgCounter(0);

        count = FallingEdgCounter(1);

        /* falling edge the count should be equal 2 */
        count = FallingEdgCounter(0);

        count = FallingEdgCounter(0);

        count = FallingEdgCounter(1);

        /* falling edge the count should be equal 3 */
        count = FallingEdgCounter(0);

        printf("count = %d",count);
}
