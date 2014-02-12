#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern double int2double(unsigned long sign, unsigned long exp, unsigned long base);

int main(){
  uint sign, exp, base;
  //  scanf("%hu, %hu, %hu", &sign, &exp, &base);
  //  printf("%hu, %hu, %hu\n", sign, exp, base);
  printf("%lf\n", int2double(0, 1023, 2));
  printf("%lf\n", int2double(0, 1024, 2));
  printf("%lf\n", int2double(0, 1023, 1125899906842624l));      
  return 0;
}
