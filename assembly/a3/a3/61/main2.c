#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern long int2double2(uint sign, uint exp, uint base);

int main(){
  uint sign, exp, base;
  char buf[1000];
  scanf("%d %d %d", &sign, &exp, &base);
  printf("%ld\n", int2double2(sign, exp, base));
  printf("%s\n", buf);  
  return 0;
}
