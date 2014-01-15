#include <stdio.h>
#include <stdlib.h>

int main(){
  char c;
  int i = 0;
  while((c=getchar()) != EOF){
    if(c == 'a'){
      i++;
    }
  }
  printf("%d\n", i);
  return 0;
}
