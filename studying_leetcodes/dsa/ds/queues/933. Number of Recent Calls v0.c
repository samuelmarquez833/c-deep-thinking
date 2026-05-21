#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>




typedef struct Node {
  int val;
  struct Node* next;
} Node;

typedef struct RecentCounter{
  Node* head; 
  Node* tail;  
} RecentCounter;






RecentCounter* recentCounterCreate() {
  RecentCounter* aja = malloc(sizeof(RecentCounter)); 
  aja->head = NULL;
  aja->tail= NULL;
  return aja;
}


int recentCounterPing(RecentCounter* obj, int t) {
  
  Node* ping = malloc(sizeof(Node));
  ping->next = NULL;
  ping->val = t;
  
  if(obj->head == NULL){
    obj->head = ping;
    obj->tail = ping;
  } else{
    Node* ultimoNodo = obj->tail;
    ultimoNodo->next = ping;
    obj->tail = ping;
  }



  int inicioDelRango = t-3000;
  int finDelRango = t;
  Node* nodo = obj->head;
  int count = 0;
  while(nodo != NULL){
    printf("%d\n", nodo->val);
    if (nodo->val < inicioDelRango){
      obj->head = nodo->next;
      printf("cambiamos el head\n");
    }else{
      count++;
      printf("aumentamos\n");
    }
    nodo = nodo->next;
  } 

  printf("count: %d\n", count);
  printf("/////////////////\n");

}


void recentCounterFree(RecentCounter* obj) {
    
  free(obj);
}









void main(){
  RecentCounter* obj = recentCounterCreate();
  int param; 
  
  param = recentCounterPing(obj, 1);

  param = recentCounterPing(obj, 1000);
  param = recentCounterPing(obj, 3001);
  param = recentCounterPing(obj, 3002);


  recentCounterFree(obj);


}


