#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern double inner(double *a, double *b);

int main(){
  double a[] = {.5, .5};
  double b[] = {3, 4};
  printf("%lf\n", inner(a, b));
  return 0;
}
