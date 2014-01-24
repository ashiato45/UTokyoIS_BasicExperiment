#include <stdio.h>
#include <stdlib.h>
extern int mystrlen(char *str, char *str2);

int main(){
  char a[100] = "Hello, world!";
  char b[100] = "Hello, world!";
  char c[100] = "Hello, beautiful world!";
  printf("%d\n", mystrcmp2(a, b));
  printf("%d\n", mystrcmp2(b, a));  
  printf("%d\n", mystrcmp2(b, c));
  printf("%d\n", mystrcmp2(c, b));  
  printf("%d\n", mystrcmp2(c, a));
  printf("%d\n", mystrcmp2(a, c));      
  return 0;
}
