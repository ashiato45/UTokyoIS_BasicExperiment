#include <stdlib.h>
#include <stdio.h>

int main(){
  char s[100];
  int i = 0;
  int cnt = 0;
  scanf("%s", s);
  for(i=0; s[i] != '\0'; i++){
    if(s[i] == 'a'){
      cnt++;
    }
  }
      
  printf("%d\n", cnt);
  return 0;
}
