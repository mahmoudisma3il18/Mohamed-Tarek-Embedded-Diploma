#include <stdio.h>

typedef enum {
    False = 0,
    True  = 1
}bool;

bool isStringDistinct(char* String) {

    for ( int i = 0 ; String[i] != '\0' ; i++) {

        for(int j = i + 1 ; String[j] != '\0' ; j++)
            if (String[i] == String[j] )
                return False;
    }

    return True;


}

int main()
{
    char* String = "mahmoud";

    if(isStringDistinct(String) == True)
        printf("Its Distinct \n");
    else
        printf("Its not Distinct\n");
}
