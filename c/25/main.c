#include <stdlib.h>
#include <stdio.h>
#define BIAS ('a' - 'A')

char conv(char c){
  if('a' <= c && c <= 'z'){
    return c - BIAS;
  }
  if('A' <= c && c <= 'Z'){
    return c + BIAS;
  }
  return c;
}

int main(){
  FILE *fpin;
  FILE *fpout;
  char c;

  if((fpin = fopen("input.txt", "r")) == NULL){
    return 1;
  }

  if((fpout = fopen("output.txt", "w")) == NULL){
    return 2;
  }

  while((c = getc(fpin)) != EOF){
    putc(conv(c), fpout);
  }

  fclose(fpin);
  fclose(fpout);
  
  return 0;
}
