#include <stdio.h>

#define square(x) (x) * (x)

int main()
{
    printf("%d\n", square(square(1 + 2)));

    return 0;
}
