#include <stdio.h>
#define PI 3.141592654

int main()
{

    double raduis,area,circumfrance;
    printf("Enter raduis : ");
    scanf("%lf",&raduis);
    area = PI*raduis*raduis;
    circumfrance = 2 * PI * raduis;
    printf("The area  = %lf and Circ = %lf \n",area,circumfrance);

}
