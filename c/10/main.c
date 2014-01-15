#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1[5] = {};
    int a2[5];
    int i;

    for (i = 0; i < 5; i++)
        scanf("%d", &a1[i]);

    /* ‚±‚±‚ð–„‚ß‚éB */
    for(i=0; i < 5; i++){
      a2[i] = a1[5-i-1];
    }

    for (i = 0; i < 5; i++)
        printf("%d\n", a2[i]);

    return 0;
}
