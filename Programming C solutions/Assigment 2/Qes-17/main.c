#include <stdio.h>

int MaxXor(int EnteredL,int EnteredR) {
    int MaxValue = 0 ;

    for (  EnteredL; EnteredL <= EnteredR; EnteredL ++ ) {

        for(int i = EnteredL;i<= EnteredR;i++) {
            if((EnteredL ^ i) > MaxValue)
                MaxValue = EnteredL ^ i;
        }
    }

    return MaxValue;

}



int main()
{


    printf("Max Value is : %d\n",MaxXor(10,15));
}
