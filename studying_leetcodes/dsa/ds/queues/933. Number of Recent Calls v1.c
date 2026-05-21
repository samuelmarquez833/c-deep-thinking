


typedef struct Node {
  int val;
  struct Node* next;
} Node;

typedef struct RecentCounter{
  Node* head; 
  Node* tail;  
int size; 

} RecentCounter;






RecentCounter* recentCounterCreate() {
  RecentCounter* aja = malloc(sizeof(RecentCounter)); 
  aja->head = NULL;
  aja->tail= NULL;
    aja->size = 0;
  return aja;
}



int recentCounterPing(RecentCounter* obj, int t) {
  
  Node* ping = malloc(sizeof(Node));
  ping->next = NULL;
  ping->val = t;
  
obj->size += 1;

  if(obj->head == NULL){
    obj->head = ping;
    obj->tail = ping;
  } else{
    Node* ultimoNodo = obj->tail;
    ultimoNodo->next = ping;
    obj->tail = ping;
  }



  int inicioDelRango = t-3000;

  Node* nodo = obj->head;


  while(nodo->val < inicioDelRango){
    obj->head = nodo->next;
    nodo = nodo->next;
        obj->size -= 1;

  }

    return obj->size;

}


void recentCounterFree(RecentCounter* obj) {
    
  free(obj);
}

