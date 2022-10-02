#include <stdio.h>

int zeros_max(unsigned int num){

    int counter = 0,max_occurence=0;

    while(num>0){

        if(num%2 == 0){
            counter++;

            if(counter >= max_occurence)
                max_occurence = counter;
        }
        else
            counter = 0;

        num >>=1;
    }


    return max_occurence;
}

int main()
{
    printf("number of zeros : %d\n",zeros_max(145));
}
