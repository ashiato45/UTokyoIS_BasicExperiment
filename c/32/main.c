#include <stdio.h>
#include <stdlib.h>

char *getstr()
{
  char* buf;
  buf = malloc(100);
  int x;
  
  x = scanf("%99s", buf);

  return (x == EOF) ? NULL : buf;
}

int main()
{
    char *s[3];
    int i;

    for (i = 0; i < 3; i++) {
        s[i] = getstr();
    }

    for (i = 2; 0 <= i; i--) {
        if (s[i] != NULL)
            printf("%s\n", s[i]);
	free(s[i]);
    }

    return 0;
}
