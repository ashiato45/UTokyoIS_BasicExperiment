#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern void add128(unsigned long long int*, unsigned long long int*, unsigned long long int*);

int main(){
  unsigned long long int a[2] = {0x0ull, 0xf000000000000001ULL};
  unsigned long long int b[2] = {0x0ull, 0xe000000000000002ULL};
  unsigned long long int c[2];
  add128(a, b, c);
  printf("%llx %llx\n", a[0], a[1]);
  printf("%llx %llx\n", b[0], b[1]);  
  printf("%llx %llx\n", c[0], c[1]);
  return 0;
}
