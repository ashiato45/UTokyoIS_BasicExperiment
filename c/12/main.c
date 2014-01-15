#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
  return x > y ? y : x;
}

int min3(int x, int y, int z){
  return min(x, min(y, z));
}

int main(){
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  printf("%d\n", min3(x, y, z));
  return 0;
}
