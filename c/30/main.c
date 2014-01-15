#include <stdio.h>

int main()
{
    char s[100];
    int c;
    int i = 0;

    c = getchar();
    while ((c != EOF) && (i < 100)) {
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';

    printf("%s", s);

    return 0;
}
