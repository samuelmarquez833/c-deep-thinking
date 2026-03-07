#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node **apunta;
    int lenghtOfApunta;
};

struct Graph {
    int amountOfNodes;
    struct Node *begins;
    struct Node **directions;
};


struct Queue{
    struct Node *front;
    struct Node *back;
    int amountOfNodes;
};


void recorrerConBFS(struct Graph *grafo){

    
    int cantidad_de_nodo = grafo->amountOfNodes;
    
    struct Node **visited = malloc(cantidad_de_nodo * sizeof(struct Node*));
    struct Node **cola  = malloc(cantidad_de_nodo * sizeof(struct Node*));
    // x pero esta bien inicializar
    for (int i = 0; i < cantidad_de_nodo; i++) visited[i] = NULL;
    for (int i = 0; i < cantidad_de_nodo; i++) cola[i] = NULL;



    struct Node *primero = grafo->begins;


    visited[0] = primero;
    int visited_writtingIDX_largo = 1;

    cola[0] = primero;
    // de aqui sacas
    int cola_read = 0;
    // aqui metes
    int cola_write_largo = 1;
    

    while(cola_read < cola_write_largo){

        struct Node *nodoActual = cola[cola_read];
        cola[cola_read] = NULL;

        struct Node **listaDeNodosDelNodoActual = nodoActual->apunta;
        int listaDeNodosDelNodoActual_largo = nodoActual->lenghtOfApunta;


        for (int i = 0; i < listaDeNodosDelNodoActual_largo; i++){

            int yaVisitado = 0;

            for (int j = 0; j < visited_writtingIDX_largo; j++){
                if(visited[j] == listaDeNodosDelNodoActual[i]){
                    //printf("El nodo ya fue visitado\n");
                    yaVisitado = 1;
                    break;
                } 
            }  

            if (yaVisitado) {
                continue; 
            }

            //digamso que B no ha sido visitado entonces
            visited[visited_writtingIDX_largo]= listaDeNodosDelNodoActual[i];
            visited_writtingIDX_largo++;
            
            cola[cola_write_largo]= listaDeNodosDelNodoActual[i];
            cola_write_largo++;
        }
        cola_read++;
    }


    printf("\n\n\n");

    for (int i = 0; i < cola_write_largo; i++){
        printf("%p\n", *(visited+i));
    }

    free(visited);
    free(cola);


}



















int funcionRecursiva(

    struct Node *nodo,
    int idx, 
    int *vectorDeEstados,
    struct Node **arrayDeDireccionesDeTodosLosNodosDelGrafo,
    int cantidadDeNodosEnTodoElGrafo){



    int cantidadDeNodosQuePoseeElNodoActual =  nodo->lenghtOfApunta;
    
    *(vectorDeEstados+idx) = 1;

    int retorno = 0;

    for(int i = 0; i < cantidadDeNodosQuePoseeElNodoActual; i++){
        struct Node *subNodo = *(nodo->apunta+i);
        for(int k = 0; k < cantidadDeNodosEnTodoElGrafo; k++){
            if(subNodo == *(arrayDeDireccionesDeTodosLosNodosDelGrafo+k)){
                if (*(vectorDeEstados+k) == 1){
                    return 1;
                } else if (*(vectorDeEstados+k) == 0){
                    retorno = funcionRecursiva(subNodo, k, vectorDeEstados, arrayDeDireccionesDeTodosLosNodosDelGrafo, cantidadDeNodosEnTodoElGrafo);
                    // claro, pones el return pq, si lo encontro, lo encontro, entoces, ya que? con eso ya estuvo, la reaccion en cadena hace qeu todos valgan uno, y se devuelva en todos, hasta llegar a la funcion original de abajo
                    if (retorno == 1) return 1;
                }
            }
        }
    }


    *(vectorDeEstados+idx) = 2;

    return 0; 

}


void minimoUnCiclo(struct Graph *grafo){

    int cantidadDeNodosEnTodoElGrafo = grafo->amountOfNodes;
    struct Node **arrayDeDireccionesDeTodosLosNodosDelGrafo = grafo->directions; 

    int *vectorDeEstados = malloc(cantidadDeNodosEnTodoElGrafo * sizeof(int));
    for(int i = 0; i < cantidadDeNodosEnTodoElGrafo; i++){
        *(vectorDeEstados+i) = 0;
    }


    struct Node *nodoActual = NULL;
    for(int i = 0; i < cantidadDeNodosEnTodoElGrafo; i++){
        nodoActual = *(grafo->directions+i);
        int output = 0;
            if (vectorDeEstados[i] == 0) {
                    output = funcionRecursiva(
                    nodoActual,  
                    i, 
                    vectorDeEstados, 
                    arrayDeDireccionesDeTodosLosNodosDelGrafo, 
                    cantidadDeNodosEnTodoElGrafo);        
            }
        if (output == 1){
            return;
        }

        
    }

    free(vectorDeEstados);
}




// hacer la con una sola funcion
// encontrar todos los ciclos



struct Node *createNode(struct Graph *grafo, int val){
    struct Node *node = malloc(sizeof(struct Node ));

    

    if (node == NULL){
        return NULL;
    }

    
    if (grafo->directions == NULL){
        grafo->directions = malloc(sizeof(struct Node*));
    } else{
        grafo->directions = realloc(grafo->directions, ((grafo->amountOfNodes) + 1) * sizeof(struct Node*));
    }
    

    node->value = val;
    node->apunta = NULL;
    node->lenghtOfApunta = 0;



    *(grafo->directions+grafo->amountOfNodes) = node;
    grafo->amountOfNodes++;


    return node;


}

void makeConnection(struct Node *nodeA, struct Node *nodeB){
    
    if (nodeA->apunta == NULL){
        nodeA->apunta = malloc(sizeof(struct Node*));
    } else {
        nodeA->apunta = realloc(nodeA->apunta, ((nodeA->lenghtOfApunta) + 1) * sizeof(struct Node*));
    }

    
    // intentar poner el nodo a lo ultimo 
    
    // ya creci el largo arriba
    // quiero meter la direccion del nodo (que claro es tipo struct Node) 
    // al final del vector, pero quiero hacerlo con artimetica de puntos
    // explica no des codigo
    *(nodeA->apunta+nodeA->lenghtOfApunta) = nodeB;
    nodeA->lenghtOfApunta++;

}

void matriz (struct Graph *grafo){
    int n = grafo->amountOfNodes;

    int matriz[n][n]= {};

    for (int i = 0; i < n; i++){
        struct Node *nodoDelMomento = *(grafo->directions+i);

        for (int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if (nodoDelMomento->apunta == NULL){
                 
            } else {
                for (int k = 0; k < nodoDelMomento->lenghtOfApunta; k++){
                    if (*(grafo->directions+j) == *(nodoDelMomento->apunta+k)){
                        matriz[i][j] = 1;
                    }
                    
                }
            }            
        }
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }
}



//Dado un grafo y un nodo inicial, quiero visitar todos los nodos alcanzables, en orden por cercanía.
void bfs(){

}



int main (){

    struct Graph *grafo = malloc(sizeof(struct Graph));
    grafo->directions = NULL;
    grafo->amountOfNodes = 0;
    


    struct Node *nodeA = createNode(grafo, 1);
    struct Node *nodeB = createNode(grafo, 2);
    struct Node *nodeC = createNode(grafo, 3);
    struct Node *nodeD = createNode(grafo, 4);
    struct Node *nodeE = createNode(grafo, 5);
    struct Node *nodeF = createNode(grafo, 6);
    struct Node *nodeG = createNode(grafo, 7);
    struct Node *nodeH = createNode(grafo, 8);
    struct Node *nodeI = createNode(grafo, 9);
    grafo->begins = nodeA;

    makeConnection(nodeA, nodeB);
    makeConnection(nodeA, nodeC);
    makeConnection(nodeD, nodeA);
    makeConnection(nodeC, nodeG);
    makeConnection(nodeC, nodeH);
    makeConnection(nodeG, nodeB);
    makeConnection(nodeB, nodeE);
    makeConnection(nodeB, nodeF);
    makeConnection(nodeF, nodeE);
    makeConnection(nodeE, nodeD);
    makeConnection(nodeH, nodeI);
    makeConnection(nodeI, nodeA);
    


    //  imprimimos la direccion de cada nodo
    printf("A: %p\n", nodeA);
    printf("B: %p\n", nodeB);
    printf("C: %p\n", nodeC);
    printf("D: %p\n", nodeD);
    printf("E: %p\n", nodeE);
    printf("F: %p\n", nodeF);
    printf("G: %p\n", nodeG);
    printf("H: %p\n", nodeH);
    printf("I: %p\n", nodeI);
    printf("pausaaaaa \n");



    recorrerConBFS(grafo);


    return 0;

}

