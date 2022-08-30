#include <stdio.h>


enum fan_level {
    Level1,
    Level2,
    Level3
};

int main()
{
    enum fan_level fan1 = Level2;
    printf("%d\n",fan1);
    return 0;
}
