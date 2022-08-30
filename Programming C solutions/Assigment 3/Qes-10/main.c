#include <stdio.h>

void UppercaseToLowercase(char *String) {

    int i = 0 ;

    while(String[i] != '\0'){

        if(String[i] >= 65  &&  String[i] <= 90)
            String[i] += 0x20;
      i++;
    }
}

int main()
{
    char String[] = "Hello World!" ;
    UppercaseToLowercase(String);
    printf("%s\n",String);
    return 0;
}
