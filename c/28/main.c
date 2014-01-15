#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a_, const void* b_){
  int a = *(int*)(a_);
  int b = *(int*)(b_);
  if(a % 2 == b % 2){
    return a - b;
  }else{
    return a%2 - b%2;
  }
}

int main(){
  int a[5];
  scanf("%d %d %d %d %d", a, a+1, a+2, a+3, a+4);
  qsort(a, 5, sizeof(int), cmp);
  printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
  return 0;
}
