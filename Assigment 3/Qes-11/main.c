#include <stdio.h>

int CharFrequncy(char* String, char character) {

    int i = 0 , frequncy = 0;

    while(String[i] != '\0') {

        if(String[i] == character)
            frequncy++;

        i++;
    }

    return frequncy;
}

int main()
{
    char String[] = "mahmoud";

    printf("The Frequncy of %c is %d\n",'m',CharFrequncy(String,'m'));
    return 0;
}
