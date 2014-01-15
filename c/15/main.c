#include <stdio.h>
#include <stdlib.h>
#define diff(x, y) ( (x > y) ? ((x)-(y)) : ((y)-(x)) )

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", diff(a, b));
  
  return 0;
}
