#include <stdio.h>
#include <stdlib.h>

typedef struct lnode {
  char *data;
  struct lnode *next;
}lnode;

lnode *list_empty()
{
  lnode *p;
  p = malloc(sizeof(lnode));
  //  p->data = malloc(sizeof(char)*100);
  p->data = NULL;
  //p->data[0] = '\0';
  p->next = NULL;
  return p;
}

lnode *list_cons(char *s, lnode *l)
{
  int i = 0;
  lnode *p = list_empty();
  p->next = l;
  p->data = malloc(sizeof(char)*100);
  for(i=0; i < 100; i++){
    p->data[i] = s[i];
  }

  return p;
  
}

lnode *list_reverse(lnode *l)
{
  lnode *first;
  lnode *second;
  lnode *next;
  first = NULL;
  second = l;
  while(second != NULL){
    next = second->next;
    second->next = first;
    first = second;
    second = next;
  }
  return first;
}

void list_putl(lnode *l)
{
  lnode *p = l;
  while(p != NULL){
    if(p->data != NULL){
      printf("%s\n", p->data);
    }
    p = p->next;
  }
}

void list_free(lnode *l)
{
  lnode *p = l;
  lnode *next = NULL;
  while(p != NULL){
    next = p->next;
    free(p->data);
    free(p);
    p = next;
  }
}

int main(int argc, char *argv[])
{
  lnode *l;
  char buf[100] = "";

  l = list_empty();

  while(scanf("%99s", buf) != EOF){
    l = list_cons(buf, l);
    scanf(" ");
    buf[0] = '\0';
  }

  l = list_reverse(l);
  list_putl(l);

  list_free(l);

  return 0;
}
