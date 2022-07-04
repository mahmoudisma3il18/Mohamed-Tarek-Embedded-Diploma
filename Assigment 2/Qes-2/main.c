#include <stdio.h>

#define TRUE 1
#define FALSE 0

int  isAlphabet(char x) {

    if((x>=65 && x<= 90) || (x>= 97 && x<= 122) )
        return TRUE;
    else
        return FALSE;

}

int main()
{
    char x;
    printf("Enter char : ");
    scanf("%c",&x);

    if((isAlphabet(x) == TRUE))
        printf("Its alphapet\n");
    else
        printf("Its not alphapet\n");

}
