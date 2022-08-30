#include <stdio.h>

struct Time {

    int seconds;
    int minutes;
    int hours;
};

struct Time timeDiffernce(struct Time t1,struct Time t2) {

    struct Time result;
    result.seconds = t1.seconds - t2.seconds;
    result.minutes = t1.minutes - t2.minutes;
    result.hours   = t1.hours   - t2.hours;

    return (result);

}

int main()
{

    struct Time result ;
    struct Time t1 = {60,50,30};
    struct Time t2 = {50,40,30};

    result = timeDiffernce(t1,t2);

    printf("%d seconds : %d mins : %d hrs \n",result.seconds,result.minutes,result.hours);


    return 0;
}
