#include <stdio.h>
#include <stdlib.h>

int main(){
  char s[100];
  int i = 0;
  int cnt = 0;
  
  scanf("%s", s);
  printf("%s\n", s);

  while(*(s+i) != '\0'){
    if(*(s+i) == 'a'){
      cnt++;
    }
    i++;
  }

  printf("%d\n", cnt);
  
  return 0;
}
