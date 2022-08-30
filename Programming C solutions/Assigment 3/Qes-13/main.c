#include <stdio.h>

void RemoveAllExceptChar(char *String) {

    for(int i = 0 ; String[i] != '\0' ; i++) {

        while(!((String[i] >= 97 && String[i] <= 122) || (String[i] >= 65  && String[i] <= 90)) &&  String[i] !='\0' ) {

            for(int j = i ; String[j] != '\0' ; j++ ) {
                String[j] = String[j+1];
            }

        }
    }

}

int main()
{

    char x[]="ma50hhmoud ";
    RemoveAllExceptChar(x);
    printf("%s\n",x);
    return 0;
}
