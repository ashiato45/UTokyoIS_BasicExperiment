#include <stdio.h>
extern int maxof3(int x, int y, int z);
int main(){
  printf("%d\n", maxof3(3, 5, 2));
  printf("%d\n", maxof3(2, -2, -9));
  printf("%d\n", maxof3(2, 2, 7));  
  return 0;
}
