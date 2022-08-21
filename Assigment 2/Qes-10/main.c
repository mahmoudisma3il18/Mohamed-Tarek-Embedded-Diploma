#include <stdio.h>

int countHoles(int number) {

    int remiander,holes = 0;

    while(number>0) {
        remiander = number % 10 ;
        number/=10;

        if((remiander == 0) || (remiander == 4) || (remiander == 6) || (remiander == 9))
            holes += 1;
        else if (remiander == 8)
            holes +=2;
        else
            holes +=0;

    }

    return holes;
}

int main()
{
    int number ;
    printf("Enter Number : ");
    scanf("%d",&number);
    printf("Number of holes is %d \n",countHoles(number));
}
