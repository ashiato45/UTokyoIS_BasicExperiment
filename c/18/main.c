#include <stdio.h>

int main()
{
    char s1[100] = "";
    char s2[100];
    int i;

    scanf("%99s", s1);

    /* ‚±‚±‚ğ–„‚ß‚éB */
    for(i=0; i < 100; i++){
      s2[i] = s1[i];
    }

    printf("%s\n", s2);

    return 0;
}
