#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void rev_intarray(int a[], int k){
  int i;
  for(i=0; i < k/2; i++){
    swap(a+i, a+k-1-i);
  }
  return;
}
  

int main(){
  int a[5];
  scanf("%d %d %d %d %d", a, a+1, a+2, a+3, a+4);
  rev_intarray(a, 5);
  printf("%d\n%d\n%d\n%d\n%d\n", a[0], a[1], a[2], a[3], a[4]);
  
  return 0;
}
