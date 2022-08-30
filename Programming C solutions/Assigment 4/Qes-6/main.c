#include <stdio.h>
#include <string.h>

union family_name {

    char first_name[30];
    char second_name[30];
};

int main()
{
   union family_name fam;
   strcpy(fam.first_name,"Mahmoud");
   printf("%s\n",fam.second_name);
   printf("Size of union : %d\n",sizeof(fam));

    return 0;
}
