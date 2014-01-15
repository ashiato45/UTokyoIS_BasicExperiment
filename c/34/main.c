#include <stdio.h>

int main()
{
    int x = 1;
    float y = 1;

    y = x = 1.0 / 2.0;
    printf("x: %d\ny: %f\n", x, y);

    return 0;
}
