#include <stdio.h>

int StringLenght(char* String) {

    int count = 0 ;
    while(String[count] != '\0')
        count++;

    return count;

}

int main()
{
    printf("The Lenght of \"Mahmoud\" is %d ",StringLenght("Mahmoud"));
    return 0;
}
