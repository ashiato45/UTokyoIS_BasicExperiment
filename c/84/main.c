#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tnode{
  char *key;
  char *value;
  struct tnode *left;
  struct tnode *right;
} tnode;

tnode *btree_empty()
{
  tnode *t;
  t = malloc(sizeof(tnode));
  t->key = malloc(sizeof(char)*100);
  t->value = malloc(sizeof(char)*100);
  t->left = NULL;
  t->right = NULL;
  return t;
}

tnode *btree_insert_helper(tnode *parent, char *key, char *val, tnode *t)
{
  int cmp = 0;
  tnode *node = NULL;

  if(t == NULL){
    node = btree_empty();
    strcpy(node->key, key);
    strcpy(node->value, val);
    if(parent != NULL){
      if(parent->left == NULL){
	parent->left = node;
      }else{
	parent->right = node;
      }
    }
  }else{
    cmp = strcmp(t->key, key);
    if(cmp == 0){
      strcpy(t->value, val);
      node = t;
    }else if(cmp < 0){
      node = btree_insert_helper(t, key, val, t->left);
    }else{
      node = btree_insert_helper(t, key, val, t->right);
    }
  }
  return node;
}

tnode *btree_insert(char *key, char *val, tnode *t)
{
  btree_insert_helper(NULL, key, val, t);
}

tnode *btree_delete_helper(tnode *parent, char *key, tnode *t)
{
  tnode *node = NULL;
  int cmp = 0;
  tnode *left_last = NULL;
  tnode *p = NULL;
  tnode *prev = NULL;
  
  if(t == NULL){
    node = NULL;
  }else{
    cmp = strcmp(t->key, key);
    if(cmp == 0){
      if(t->left == NULL){
	//connect right to parent directly
	node = t->right;
      }else{
	prev = NULL;
	p = t->left;
	while(p != NULL){
	  prev = p;
	  p = p->right;
	}
	if(prev->left == NULL){
	  prev->left = t->right;
	}else{
	  prev->right = t->right;
	}
	node = t->left;
      }

      //connect
      if(parent == NULL){
      }else if(parent->left == t){
	parent->left = node;
      }else{
	parent->right = node;
      }
    }else if(cmp < 0){
      node = btree_delete_helper(t, key, t->left);
    }else{
      node = btree_delete_helper(t, key, t->right);
    }
  }

  return node;
}

tnode *btree_delete(char *key, tnode *t)
{
  return btree_delete_helper(NULL, key, t);
}

tnode *btree_search(char *key, tnode *t){
  int cmp = 0;
  tnode *result = NULL;
  
  if(t == NULL){
    result = NULL;
  }else{
    cmp = strcmp(t->key, key);
    if(cmp == 0){
      result = t;
    }else if(cmp < 0){
      result = btree_search(key, t->left);
    }else{
      result = btree_search(key, t->right);
    }
  }

  return result;
}

void *btree_destroy(tnode *t)
{
  if(t == NULL){
  }else{
    btree_destroy(t->left);
    btree_destroy(t->right);
    free(t->key);
    free(t->value);
    free(t);
  }
  return;
}

int main(){
  char command[100];
  char word[100];
  char tango[100];
  tnode *tree = NULL;
  tnode *temp = NULL;

  while(1){
    scanf("%s", command);
    if(strcmp(command, "insert") == 0){
      scanf("%s %s", word, tango);
      temp = btree_insert(word, tango, tree);
      if(tree == NULL){
	tree = temp;
      }
    }else if(strcmp(command, "delete") == 0){
      scanf("%s", word);
      temp = btree_delete(word, tree);
      if(temp == tree->left){
	tree = tree->left;
      }else if(temp == tree->right){
	tree = tree->right;
      }
      
	
    }else if(strcmp(command, "search") == 0){
      scanf("%s", word);
      temp = btree_search(word, tree);
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

  btree_destroy(tree);
  return 0;
}
