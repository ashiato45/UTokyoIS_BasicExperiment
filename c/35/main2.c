#include <stdio.h>
#include <stdlib.h>

struct container {
    int number;
    char string[100];
};

int main()
{
    struct container *c;

    c = malloc(sizeof(struct container));
    if (c == NULL) exit(1);

    scanf("%d", &c->number);
    scanf("%s", c->string);

    printf("%d:%s\n", c->number, c->string);

    free(c);

    return 0;
}
