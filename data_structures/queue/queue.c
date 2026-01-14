/*



BFS usando queue
*/


struct Node{
    int val;
    struct Node *pointsTo;
};

struct Queue{
    struct Node *front;
    struct Node *back;
    int amountOfNodes;
}



Queue* createQueue(){
    struct Queue *cola = malloc(siszeof(struct Queue));
    cola->amountOfNodes = 0;
    cola->front = NULL;
    cola->back = NULL;

    return cola;
}


Node* createNode(int value){
    
    struct Node *nodo = malloc(siszeof(struct Node));
    nodo->val = value
    return nodo;
}

bool isEmpty(struct Queue *cola){
    if (cola->front == NULL) return true;
    return false
}

/*
Entra por el BACK
Sale por el FRONT

*/


void encolar(struct Queue *cola, struct Node *nodo){
    
    if (cola->amountOfNodes == 0){
        cola->front = nodo;
        cola->back = nodo;
        
    } else {
        (cola->back)->pointsTo = nodo;
        cola->back = nodo;
        nodo->pointsTo = NULL;

        cola->amountOfNodes++;
    }   
}

Node *desencolar(struct Queue *cola){
    

    if (cola->amountOfNodes == 0){
        printf("nada que hacer, no tiene elementos la cola");        
        // si se peude hacer un return aunuqe el tipo sea void
        return NULL;
    } 
    
    
    struct Node *desencolado = cola->front;

    if(cola->amountOfNodes == 1){
        cola->front = NULL;
        cola->back = NULL;
    } else{
        cola->front = desencolado->pointsTo;
    }
    
    cola->amountOfNodes--;

    return desencolado;


}


Node *peek (struct Queue *cola){
    if (cola->amountOfNodes == 0){
        return NULL;
    }
    return cola->front;
}









// que tal esta funcion?
void freeQueue(struct Queue *cola){
    int largo_cola = cola->amountOfNodes;

    Struct Node *nodoActual = cola->front;

    for (int i - 0; i < largo_cola-1; i++){
        Struct Node *nodoProximo = nodoActual->front;
        free(nodoActual);
        nodoActual = nodoProximo;
    }

    free(cola);
}





int main (){

    struct Queue *cola = createQueue();
    cola->amountOfNodes = 0;

    struct Node *elementoUno = createNode(1);
    struct Node *elementoDos = createNode(2);
    struct Node *elementoTres = createNode(3);
    struct Node *elementoCuatro = createNode(4);
    struct Node *elementoCinco = createNode(5);
    struct Node *elementoSeis = createNode(6);
    struct Node *elementoSiete = createNode(7);


    encolar(cola, elementoUno);


    return 0;
}