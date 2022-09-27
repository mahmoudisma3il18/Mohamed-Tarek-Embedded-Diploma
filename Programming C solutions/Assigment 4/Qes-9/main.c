#include <stdio.h>


int main()
{
    char *String = "bat";
    char x[3];
    while(*String != '\0') {

        x[0] = *String;
        x[1] = ' ';
        x[2] = *(String - 1);

        String++;
    }

    for(int i = 0 ; i <3 ; i++)
        printf("%c",x[i]);
    return 0;
}
