#include <stdio.h>
extern int maxof2(int x, int y);
int main(){
  printf("%d\n", maxof2(3, 5));
  printf("%d\n", maxof2(2, -2));
  printf("%d\n", maxof2(2, 2));  
  return 0;
}
