#include <stdio.h>
extern int maxof3(int x, int y);
int main(){
  printf("%d\n", maxof3(3, 5));
  printf("%d\n", maxof3(2, -2));
  printf("%d\n", maxof3(2, 2));  
  return 0;
}