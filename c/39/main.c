#include <stdio.h>

int main()
{
    char *x[4] = {"enter", "new", "point", "first"};
    char **xp[4];
    char ***xpp;
    int i;

    for (i = 0; i < 4; i++)
        xp[i] = x + (3 - i);
    xpp = xp;

    printf("%s", **++xpp);
    printf("%s ", *--*++xpp+3);
    printf("%s", *xpp[-2]+3);
    printf("%s\n", *--xpp[-1]+1);

    return 0;
}
