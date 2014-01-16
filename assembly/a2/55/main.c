#include <stdio.h>
#include <stdlib.h>
extern int mystrlen(char *str);

int main(){
  char a[100] = "Hello, world!";
  printf("%d\n", mystrlen(a));
  return 0;
}
