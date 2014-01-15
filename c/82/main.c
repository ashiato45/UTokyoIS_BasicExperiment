#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

lnode *list_last(lnode *l){
  lnode *p = l;
  while(p->next != NULL){
    p = p->next;
  }
  return p;
}

lnode *list_append(lnode *l1, lnode *l2)
{
  list_last(l1)->next = l2;
  return l1;
}

void test_list_append(){
  lnode *l, *l2;
  printf("TEST_LIST_APPEND START\n");
  l = list_empty();
  l = list_cons("First line.", l);
  l = list_cons("2nd line.", l);
  l = list_cons("Last line.", l);
  l = list_reverse(l);
  l2 = list_empty();
  l2 = list_cons("First line2.", l2);
  l2 = list_cons("2nd line2.", l2);
  l2 = list_cons("Last line2.", l2);
  l2 = list_reverse(l2);
  l = list_append(l, l2);
  list_putl(l);  
  list_free(l);
  printf("TEST_LIST_APPEND END\n");  
}

lnode *list_sort(lnode *l)
{
  lnode *min_prev = NULL;
  lnode *min_current = l;
  lnode *new_list = NULL;
  lnode *p, *prev;
  while(l != NULL){
    min_prev = NULL;
    min_current = l;
    prev = NULL;
    p = l;
    while(p != NULL){
      if(strcmp(min_current->data, p->data) < 0){
	min_prev = prev;
	min_current = p;
      }
      prev = p;
      p = p->next;
    }
    if(min_prev != NULL){
      min_prev->next = min_current->next;
    }else{
      l = min_current->next;
    }
    min_current->next = new_list;      
    new_list = min_current;

    /* printf("--\n");     */
    /* list_putl(l); */
    /* printf("--\n"); */
    /* list_putl(new_list); */
    /* printf("--\n");     */
  }
  return new_list;
}

lnode *list_cut_tail(lnode *l){
  lnode *prev = NULL;
  lnode *current = l;

  while(current != NULL){
    prev = current;
    current = current->next;
  }

  list_free(current);
  if(prev != NULL){
    prev->next = NULL;
  }

  return l;
}

void test_list_sort(){
  lnode *l;
  printf("TEST_LIST_SORT START\n");
  l = NULL;
  l = list_cons("First line.", l);
  l = list_cons("2nd line.", l);
  l = list_cons("Last line.", l);
  list_putl(l);
  l = list_sort(l);
  list_putl(l);  
  list_free(l);
  printf("TEST_LIST_SORT END\n");  
}



int main(int argc, char *argv[])
{
  lnode *l;
  char buf[100] = "";

  //  test_list_sort();

  l = NULL;

  while(scanf("%99s", buf) != EOF){
    l = list_cons(buf, l);
    scanf(" ");
    buf[0] = '\0';
  }

  //  l = list_reverse(l);
  l = list_sort(l);
  list_putl(l);

  list_free(l);

  return 0;
}
