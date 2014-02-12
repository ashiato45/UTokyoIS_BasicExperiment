#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int fib(int n);

int main(){
  int i;
  for(i=0; i < 10; i++){
    printf("%d\n", fib(i));
  }
  return 0;
}
