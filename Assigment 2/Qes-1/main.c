#include <stdio.h>

void CubeNum (int Number) {

    printf("%d\n",Number * Number * Number);

}

int main()
{
    int EnteredNum;
    printf("Enter Num : ");
    scanf("%d",&EnteredNum);
    CubeNum(EnteredNum);
}
