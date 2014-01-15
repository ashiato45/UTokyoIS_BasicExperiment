#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_TABLE 1050
#define MAX_STRING 100
#define BEEP(n) printf("BEEP(%d)\n", n);
#define DEBUG 0

struct dict{
  char* table[SIZE_TABLE];
  int size;
} typedef dict;

struct list{
  int table[SIZE_TABLE];
  int size;
} typedef list;

void init_dict(dict *d){
  d->size = 0;
}

void free_dict(dict *d){
  int i = 0;
  for(i=0; i < d->size; i++){
    free(d->table[i]);
  }
}

void dump_dict(dict *d){
  int i = 0;
  for(i=0; i < d->size; i++){
    printf("%d: %s\n", i, d->table[i]);
  }
}

int find_dict(char* name, dict *d){
  int i = 0;
  for(i=0; i < d->size; i++){
    if(strcmp(name, d->table[i]) == 0){
      return i;
    }
  }
  return -1;
}

int append_dict(char *name, dict *d){
  int find = find_dict(name, d);
  if(find != -1){
    return find;
  }
  d->table[d->size] = malloc(sizeof(char)*MAX_STRING);
  strcpy(d->table[d->size], name);
  return d->size++;
}

void init_list(list *l){
  l->size = 0;
}

void free_list(list *l){
}

void dump_list(list *l){
  int i = 0;
  for(i=0; i < l->size; i++){
    printf("%d,", l->table[i]);
  }
  printf("\n");
}

void push_list(int i, list *l){
  l->table[l->size] = i;
  l->size++;
}

int pop_list(list *l){
  return l->table[--(l->size)];
}

int last_list(list *l){
  return l->table[(l->size) - 1];
}

int find_list(int n, list *l){
  int i = 0;
  for(i=0; i < l->size; i++){
    if(l->table[i] == n){
      return 1;
    }
  }
  return 0;
}
 
void process_input(dict *d, int ***graph, int *out_start, int *out_dest){
  char temp1[MAX_STRING];
  char temp2[MAX_STRING];
  int read1, read2;
  int i = 0;
  int dist = 0;
  int start = 0;
  int dest = 0;
  scanf("%s", temp1);
  start = append_dict(temp1, d);
  scanf("%s", temp1);
  dest = append_dict(temp1, d);
  while(scanf("%s %s %d", temp1, temp2, &dist) != EOF){
    read1 = append_dict(temp1, d);
    read2 = append_dict(temp2, d);
    (*graph)[read1][read2] = dist;
    (*graph)[read2][read1] = dist;
  }

  for(i=0; i < d->size; i++){
    (*graph)[i][i] = 0;
  }

  (*out_start) = start;
  (*out_dest) = dest;
}

void dump_graph(dict *d, int ***graph){
  int i, j;
  for(i=0; i < d->size; i++){
    for(j=0; j < d->size; j++){
      printf("%d ", (*graph)[i][j]);
    }
    printf("\n");
  }
}

int calc_route(int ***graph, list *route){
  int i = 0;
  int sum = 0;
  if(route->size < 2){
    return -1;
  }
  for(i=0; i < route->size - 1; i++){
    sum += (*graph)[route->table[i]][route->table[i+1]];
  }
  return sum;
}

void copy_list(list *copied, list *copying){
  int i = 0;
  for(i=0; i < copying->size; i++){
    copied->table[i] = copying->table[i];
  }
  copied->size = copying->size;
}

void dfs_nearpoint_helper(dict *d, int ***graph, list *stack, list *nearroute, int dest){
#if DEBUG
  dump_list(stack);
#endif
  int last = last_list(stack);
  int i = 0;
  int calc = 0;
  int near = calc_route(graph, nearroute);
  for(i=0; i < d->size; i++){
    if((*graph)[i][last] != -1 && find_list(i, stack) == 0){
      push_list(i, stack);
      if(i == dest){
	calc = calc_route(graph, stack);
	if(near == -1 || calc < near){
	  near = calc;
	  copy_list(nearroute, stack);
	}
      }else{
	dfs_nearpoint_helper(d, graph, stack, nearroute, dest);
      }
      pop_list(stack);
    }
  }
}

void dfs_nearpoint(dict *d, int ***graph, int start, int dest, list* out){
  list stack;
  list nearroute;
  int result = 0;
  init_list(&stack);
  init_list(&nearroute);

  push_list(start, &stack);
  push_list(start, &nearroute);

  dfs_nearpoint_helper(d, graph, &stack, &nearroute, dest);
#if DEBUG
  dump_list(&nearroute);
#endif
  copy_list(out, &nearroute);
  
  free_list(&stack);
  free_list(&nearroute);
}
 
void test1(dict *d){
  init_dict(d);
  append_dict("Apple", d);
  append_dict("Orange", d);
  dump_dict(d);
  printf("%d\n", find_dict("Apple", d));
  free_dict(d);
}

void test2(dict *d, int ***graph){
  int start, dest;
  list l;
  init_dict(d);
  process_input(d, graph, &start, &dest);
  dump_dict(d);
  dump_graph(d, graph);
  printf("start: %s, end: %s\n", d->table[start], d->table[dest]);
  free_dict(d);

  init_list(&l);
  push_list(20, &l);
  push_list(23, &l);
  dump_list(&l);
  pop_list(&l);
  dump_list(&l);
  printf("U:%d, F:%d\n", last_list(&l), find_list(20, &l));
  free_list(&l);
}

void test3(dict *d, int ***graph){
  int start, dest;
  int r = 0;
  list l;
  init_dict(d);
  process_input(d, graph, &start, &dest);
  dump_dict(d);
  dump_graph(d, graph);
  printf("start: %s, end: %s\n", d->table[start], d->table[dest]);

  dfs_nearpoint(d, graph, start, dest, &l);
  dump_list(&l);

  free_dict(d);
}

int main(){
  int i, j;
  dict d;
  int** graph;
  int start, dest;
  list route;
  char dummy[100];
  
  graph = malloc(sizeof(int*)*SIZE_TABLE);  
  for(i=0; i < SIZE_TABLE; i++){
    graph[i] = malloc(sizeof(int)*SIZE_TABLE);
    for(j=0; j < SIZE_TABLE; j++){
      graph[i][j] = -1;
    }
  }
  //  scanf("%s", dummy);

  ///  test3(&d, &graph);
  #if DEBUG
  #endif
  init_dict(&d);
  process_input(&d, &graph, &start, &dest);
  dfs_nearpoint(&d, &graph, start, dest, &route);
  if(route.size > 1){
    for(i=0; i < route.size; i++){
      printf("%s\n", d.table[route.table[i]]);
    }
  }else{
    printf("(no route)\n");
  }
  free_dict(&d);
  
  for(i=0; i < SIZE_TABLE; i++){
    free(graph[i]);
  }
  free(graph);
  return 0;
}
