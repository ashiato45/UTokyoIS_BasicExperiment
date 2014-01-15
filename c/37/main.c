#include <stdlib.h>
#include <stdio.h>

typedef struct _even_box even_box;
typedef struct _odd_box odd_box;

struct _even_box {
    int number;
    odd_box *next;
};

struct _odd_box {
    int number;
    even_box *next;
};

int main(){
  return 0;
}


として、予め内容はともかくeven_boxやodd_boxの定義を与えておく。
