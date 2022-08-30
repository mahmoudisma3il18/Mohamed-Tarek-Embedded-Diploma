#include <stdio.h>

struct Complex {


    int i;
    int j;

};


struct Complex addComplex(struct Complex c1,struct Complex c2){

    struct Complex result ;
    result.i = c1.i + c2.i;
    result.j = c1.j + c2.j;

    return (result);

}

int main()
{

    struct Complex result;
    struct Complex c1 = {10,5};
    struct Complex c2 = {5,5};
    result = addComplex(c1,c2);

    printf("%d i + %d j \n",result.i,result.j);


    return 0;
}
