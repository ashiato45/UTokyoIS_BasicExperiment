#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int mystrcmp(char *a, char *b);

int main(){
  char a[100] = "car";
  char b[100] = "carnation";
  char c[100] = "car";
  char d[100] = "rose";

  printf("%d, %d\n", strcmp(a, b), mystrcmp(a, b));
  printf("%d, %d\n", strcmp(b, c), mystrcmp(b, c));
  printf("%d, %d\n", strcmp(c, d), mystrcmp(c, d));
  printf("%d, %d\n", strcmp(d, a), mystrcmp(d, a));
  printf("%d, %d\n", strcmp(a, c), mystrcmp(a, c));
  printf("%d, %d\n", strcmp(d, b), mystrcmp(d, b));      
  return 0;
}
