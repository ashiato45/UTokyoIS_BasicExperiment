#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *p;

    p = malloc(100);
    if (p == NULL) exit(1);
    printf("%p\n", p);
    printf("%p, %d\n", (char *) p + 1, sizeof(char));
    printf("%p, %d\n", (int *) p + 1, sizeof(int));
    printf("%p, %d\n", (int (*)[4]) p, sizeof(int[4]));
    printf("%p, %d\n", (int (*)[4]) p + 1, sizeof(int[4]));
    free(p);

    return 0;
}
