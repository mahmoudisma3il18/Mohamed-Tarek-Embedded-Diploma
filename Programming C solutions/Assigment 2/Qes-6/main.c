#include <stdio.h>

char LowerCaseToUpperCase(char x) {

    return (x - 32);

}

int main()
{
    char X;
    printf("Enter Char : ");
    scanf("%c",&X);
    printf("%c",LowerCaseToUpperCase(X));
    printf("\n");
}
