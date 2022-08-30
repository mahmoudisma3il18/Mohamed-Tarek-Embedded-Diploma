#include <stdio.h>

int main()
{
    int grade;
    printf("Enter your grade : ");
    scanf("%d",&grade);

    if(grade >= 85)
        printf("Excellent \n");
    else if(grade >=75)
        printf("Very Good \n");
    else if (grade >= 65)
        printf("Good \n");
    else if (grade >= 50)
        printf("Pass \n");
    else
        printf("Fail \n");




}
