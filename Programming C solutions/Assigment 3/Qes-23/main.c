#include <stdio.h>

void PrintFrequncy(char *String) {

    char frequncy[256] = {0};

    for(int i = 0 ; String[i] != '\0' ; i++)
        frequncy[(String[i])]++;

    for(int i = 0 ; i < 256 ; i++) {


        if(frequncy[i] != 0)
            printf("%c   %d \n",i,frequncy[i]);

    }

}

int main()
{
    char str[100];

        gets(str); /* Get string from user */

        PrintFrequncy(str); /* Call the function and Pass string */
    return 0;
}
