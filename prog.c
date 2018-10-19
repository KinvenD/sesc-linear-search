#include <stdio.h>
#include <stdlib.h>
struct node{
  int value;
  struct node* next;
};

void add(struct node *noode, int value){
  if(noode->next==NULL){
    struct node *last = NULL;
    last = malloc(sizeof(struct node));
    last->value = value;
    last->next = NULL;
    noode->next = last;
  }else{
    add(noode->next, value);
  }
}

struct node* get(struct node *noode, int i){
  if(i==0){
    return noode;
  }else{
    return get(noode->next,i-1);
  }
}

int main() {
  int i;
  int N;
  int K;
  int min = -1;
  int max = -1;
  int t;
  scanf("%d", &N);
  scanf("%d", &K);
  scanf("%d", &i);
  struct node *header = NULL;
  header = malloc(sizeof(struct node));
  header->value = i;

  if(i==K){
      max = 0;
    }
  if(i==K && min == -1){
    min = 0;
  }
  
  for(int i = 0; i < N-1;i++){
    scanf("%d", &t);
    add(header,t);
    if(t==K){
      max = i+1;
    }
    if(t==K && min == -1){
      min = i+1;
    }
  }
  printf("%d  %d", min, max);
}
