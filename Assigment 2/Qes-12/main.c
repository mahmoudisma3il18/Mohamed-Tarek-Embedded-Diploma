#include <stdio.h>

int HeatingTime (unsigned int temp) {

    if (temp >= 0  &&  temp <30)
        return 7;
    else if(temp >= 30  &&  temp < 60)
        return 5;
    else if(temp >= 60  && temp < 90)
        return 3;
    else if(temp>= 90  &&  temp <=100)
        return 1;
    else
        return 0;


}

int main()
{
    unsigned temp;

    printf("Enter temp : ");
    scanf("%d",&temp);

    printf("Heating time is : %d mins\n",HeatingTime(temp));
}
