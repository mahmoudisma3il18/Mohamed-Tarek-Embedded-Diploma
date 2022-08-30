#include <stdio.h>

struct Distances {

    double inch;
    double feet;

};

int main()
{

    struct Distances distance1 = {22.0,0.3} ;
    struct Distances distance2 = {11.0,0.1};


    printf("Distance : %0.3f inchs  , %0.3f feet \n",(distance1.inch+distance2.inch),(distance1.feet+distance2.feet));


    return 0;
}
