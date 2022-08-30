#include <stdio.h>
#include "string.h"

void Reserve(char *String) {

   unsigned int j = strlen(String) - 1;
   char temp;

    for(unsigned int i = 0 ; i < j ; i++,j--) {

        temp = String[i];
        String[i] = String[j];
        String[j] = temp;

    }

}

int main()
{

    char mahmoud[] = "mahmoudx";
    Reserve(mahmoud);
    printf("%s\n",mahmoud);
    return 0;
}
