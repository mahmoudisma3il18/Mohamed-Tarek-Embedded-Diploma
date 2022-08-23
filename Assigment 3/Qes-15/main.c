#include <stdio.h>

void Concatenate(char* StringA,char* StringB) {

    int i,j;

    for(i = 0 ; StringA[i] != '\0' ; i++);

    for( j = 0 ; StringB[j]!='\0' ; j++,i++) {
        StringA[i] = StringB[j];
    }

    StringA[i] = '\0';

}

int main()
{

    char s1[100], s2[50];
       printf("\nEnter first string: ");
       gets(s1);
       printf("\nEnter second string: ");
       gets(s2);

       Concatenate(s1,s2);
       printf("\nOutput: %s\n",s1);


    return 0;
}
