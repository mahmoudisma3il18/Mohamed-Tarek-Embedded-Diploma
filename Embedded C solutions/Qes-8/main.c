#include <stdio.h>

/*
 * if number is enterded binary without 0b
 */
void revrse8bit(unsigned int x){
    if(x>0){
        printf("%d",x%10);
        revrse8bit(x/10);
    }
}

void reversebit(unsigned char *revrsedNumber,unsigned char num){
    int noOfBits = sizeof(num) * 8 ;

    for(int i = 0 ; i<noOfBits ; i++){
        if(num & (1<<i))
            *revrsedNumber |= 1<<(noOfBits - 1 -i);
    }
}

int main()
{
    unsigned char x = 0b10001101;
    unsigned char y = 0;
    unsigned  char *ptoy = &y;
    reversebit(&y,x);
    printf("%d\n",y);
    return 0;
}
