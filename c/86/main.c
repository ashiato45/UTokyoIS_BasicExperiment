#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_TABLE 30
n#define MAX_STRING 100
#define BEEP(n) printf("BEEP(%d)\n", n);
#define DEBUG 0

struct node{
  struct node *next;
  struct node *prev;
  char *key;
  char *value;
} typedef node;

void init_table(node *table[]){
  int i;
  for(i=0; i < SIZE_TABLE; i++){
    table[i] = NULL;
  }
}

node *gen_node(node *next, node *prev, char *key, char *value){
  node *result = malloc(sizeof(node));
  result->next = next;
  result->prev = prev;
  result->key = malloc(sizeof(char)*MAX_STRING);
  result->value = malloc(sizeof(char)*MAX_STRING);    
  if(key){
    strcpy(result->key, key);
  }
  if(value){
    strcpy(result->value, value);
  }
  return result;
}

int make_hash_string(char *s){
  return s[0] % SIZE_TABLE;
}

int make_hash_node(node *n){
  int result = 0;
  return make_hash_string(n->key);
}

node *find_node(char *key, node *start){
  node *p = start;
  while(p != NULL){
    if(strcmp(key, p->key) == 0){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

node *find_table(char *key, node *table[]){
  return find_node(key, table[make_hash_string(key)]);
}

node *free_node(node *p){
  node *next = p->next;
  free(p->key);
  free(p->value);
  free(p);
  return next;
}

node *free_list(node *start){
  node *p = start;
  while(p != NULL){
    p = free_node(p);
  }
}

node *free_table(node *table[]){
  int i;
  for(i=0; i < SIZE_TABLE; i++){
    free_list(table[i]);
  }
}

node *join_node(node *joining, node *joined){
  node *find = find_node(joining->key, joined);
  if(find){
    strcpy(find->value,joining->value);
    free_node(joining);
  }else{
    joining->next = joined;
    if(joined){
      joined->prev = joining;
    }
    joined = joining;
  }
  return joined;
}

node *append_table(node *appending, node *table[]){
  int i = 0;
  int hash = make_hash_node(appending);
  table[hash] = join_node(appending, table[hash]);
  return table[hash];
}

void print_node(node *n){
  if(n){
    printf("key: %s, value: %d, next: %p, prev: %p\n", n->key, n->value, n->next, n->prev);
  }else{
    printf("(null)\n");
  }
}
void remove_key(char* key, node *table[]){
  node *find = find_table(key, table);
#if(DEBUG)
  print_node(find);
#endif
  if(!find){
    return;
  }
  if(find->prev){
    find->prev->next = find->next;
  }else{
    table[make_hash_string(key)] = find->next;
  }    
  if(find->next){
    find->next->prev = find->prev;
  }

  free_node(find);
}


void dump_table(node *table[]){
  node *p;
  int i = 0;
  for(i=0; i < SIZE_TABLE; i++){
    printf("*table[%d]\n", i);
    p = table[i];
    while(p != NULL){
      print_node(p);
      p = p->next;
    }
  }
}



void test1(node *table[]){
  //  table[0] = gen_node(NULL, NULL, "apple", "RINGO");
  //  table[0] = join_node(gen_node(NULL, NULL, "orange", "DAIDAI"), table[0]);
  append_table(gen_node(NULL, NULL, "grape", "BUDO"), table);
  append_table(gen_node(NULL, NULL, "grpand", "DEKAI"), table);
  dump_table(table);
  print_node(find_table("grand", table));
  print_node(find_table("happy", table));
  append_table(gen_node(NULL, NULL, "grape", "KYOHO"), table);
  dump_table(table);
  remove_key("grand", table);
  dump_table(table);
}
  

int main(){
  char command[100];
  char word[100];
  char tango[100];
  node *table[SIZE_TABLE];
  node *temp;
  init_table(table);
  //  test1(table);
  while(1){
    scanf("%s", command);
    if(strcmp(command, "insert") == 0){
      scanf("%s %s", word, tango);
      append_table(gen_node(NULL, NULL, word, tango), table);
    }else if(strcmp(command, "delete") == 0){
      scanf("%s", word);
      remove_key(word, table);
    }else if(strcmp(command, "search") == 0){
      scanf("%s", word);
      temp = find_table(word, table);
      if(temp == NULL){
	printf("(not found)\n");
      }else{
	printf("%s\n", temp->value);
      }
    }else if(strcmp(command, "quit") == 0){
      break;
    }else{
      printf("ERROR\n");
    }    
  }

  free_table(table);
  return 0;
}
