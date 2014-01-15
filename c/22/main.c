#include <stdio.h>
#include <stdlib.h>

void sort(int* a, int* b){
  int temp;
  if(*a > *b){
    temp = *a;
    *a = *b;
    *b = temp;
  }
  return;
}
    

void sort3(int* p1, int* p2, int* p3){
  sort(p1, p2);
  sort(p1, p3);
  sort(p2, p3);
  
  return;
}

int main(){
  int a[3];
  scanf("%d %d %d", a, a+1, a+2);
  sort3(a, a+1, a+2);
  printf("%d\n%d\n%d\n", a[0], a[1], a[2]);
  return 0;
}
