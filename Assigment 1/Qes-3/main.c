#include <stdio.h>

int main()
{
    float Celusis,Fehr;
    printf("Enter Temp in Celsius : ");
    scanf("%f",&Celusis);
    Fehr = (Celusis * (9.0/5.0)) + 32 ;
    printf("Temp = %f \n",Fehr);
}
