#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern double testdbl(double d);

int main(){
  printf("%lf\n", testdbl(0.5));
  return 0;
}
