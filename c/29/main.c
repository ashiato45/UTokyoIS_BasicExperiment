#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define R (RAND_MAX/2)
#define POINTS 1000000
#define SQ(x) ((x)*(x))

int main(){
  int r = RAND_MAX/2;
  int i;
  int x, y;
  int cnt = 0;
  srand((unsigned int)time(NULL));
  for(i = 0; i < POINTS; i++){
    x = rand();
    y = rand();
    if(SQ(x - R) + SQ(y - R) <= SQ(R)){
      cnt++;
    }
  }

  printf("%d, %lf\n", cnt, (double)cnt/(double)POINTS*4);
      
  
  
  return 0;
}


  
