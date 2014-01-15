#include <stdlib.h>
#include <stdio.h>

char* first_char(char* s, char c){
  while(*s != '\0'){
    if(*s == c){
      return s;
    }
    s++;
  }
  return NULL;
}

int main(){
  char s[100];
  char* p;
  scanf("%s", s);
  p = first_char(s, 'a');
  if(p == NULL){
    printf("no\n");
  }else{
    printf("%s\n", p);
  }
  return 0;
}
