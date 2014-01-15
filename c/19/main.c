#include <stdio.h>
#include <stdlib.h>

int main(){
  char s[100];
  int i = 0;

  scanf("%s", s);

  while(s[i] != '\0'){
    i++;
  }
  i--;

  for(; i >= 0; i--){
    printf("%c", s[i]);
  }
  printf("\n");
  
  return 0;
}
  
