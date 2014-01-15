#include <stdio.h>
#include <stdlib.h>


void input_matrix(int rows, int columns, int** target){
  int r, c;
  for(r=0; r < rows; r++){

  }
}

/* void print_matrix(int rows, int columns, int** target){ */
/*   int r, c; */
/*   for(r=0; r < rows; r++){ */
/*     for(c=0; c < columns; c++){ */
/*       printf("%d */
/*     } */
/*   } */
/*   return; */
/* } */

int main(){
  int a[2][3];
  int b[3][2];
  int result[2][2];
  int temp[3];
  int r, c;

  for(r=0; r < 2; r++){
    scanf("%d %d %d", temp, temp+1, temp+2);
    a[r][0] = temp[0];
    a[r][1] = temp[1];
    a[r][2] = temp[2];
  }

  for(r=0; r < 3; r++){
    scanf("%d %d", temp, temp+1);
    b[r][0] = temp[0];
    b[r][1] = temp[1];
  }

  for(r=0; r < 2; r++){
    for(c=0; c < 2; c++){
      result[r][c] = a[r][0]*b[0][c] + a[r][1]*b[1][c] + a[r][2]*b[2][c];
    }
  }

  printf("%d %d\n%d %d\n", result[0][0], result[0][1], result[1][0], result[1][1]);
  return 0;
}
    
