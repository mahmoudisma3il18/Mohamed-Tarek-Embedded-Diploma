#include <stdio.h>

int sizeOfString(char *String) {

    int size = 0  ;

    while(*String != '\0') {
        size++;
        String++;
    }

    return size;

}

int main()
{
    int size = sizeOfString("Mahmoud");
    printf("Size of \"Mahmoud\" is %d \n",size);
    return 0;
}
