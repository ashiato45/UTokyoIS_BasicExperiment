#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char* mystrcat(char* a, char* b);

int main(){
  char a[100] = "hoge";
  char b[100] = "piyo";
  printf("%s, %s\n", a, b);
  printf("%s\n", mystrcat(a, b));
  printf("%s\n", a);  
  return 0;
}
