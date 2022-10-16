#include <stdio.h>

int RisingEdgCounter(unsigned char pinState){

    static int counter = 0;
    static char perviuosState = 1;

    if((pinState == 1) && (perviuosState == 0))
        counter++;

    perviuosState = pinState;

    return counter;
}

int main()
{
    unsigned char count = 0;

        count = RisingEdgCounter(1);

        count = RisingEdgCounter(0);

        /* raising edge the count should be equal 1 */
        count = RisingEdgCounter(1);

        count = RisingEdgCounter(1);

        count = RisingEdgCounter(0);

        /* raising edge the count should be equal 2 */
        count = RisingEdgCounter(1);

        count = RisingEdgCounter(0);

        /* raising edge the count should be equal 3 */
        count = RisingEdgCounter(1);

        count = RisingEdgCounter(0);

        /* raising edge the count should be equal 4 */
        count = RisingEdgCounter(1);

        printf("count = %d\n",count);

        return 0;
}
