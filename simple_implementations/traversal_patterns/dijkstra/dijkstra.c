#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Vertice {
    char value;
    int estimate;
    bool explored;

    struct Vertice** connections;
    int connectionsLength;
    int *connectionsWeight; 
};

struct Graph {
    int amountOfNodes;
    struct Vertice** nodes;
};

struct Graph* createGraph(){
    struct Graph* grafo = malloc(sizeof(struct Graph));
    return grafo;
}
void addNodeToGraph(struct Graph* grafo, struct Vertice* nodo){

    int inseritonIdx = grafo->amountOfNodes;
    grafo->amountOfNodes++;

    if(!grafo->nodes){
        grafo->nodes = malloc(grafo->amountOfNodes * sizeof(struct Vertice*));
        (grafo->nodes)[inseritonIdx] = nodo; 
        return;
    }

    grafo->nodes = realloc(grafo->nodes, grafo->amountOfNodes * sizeof(struct Vertice*));
    (grafo->nodes)[inseritonIdx] = nodo;
}
struct Vertice* createNodeBegin(char value){
    struct Vertice* nodo = malloc (sizeof(struct Vertice));
    nodo->value = value;
    nodo->estimate = 0; 
    nodo->explored = false;
    nodo->connectionsLength = 0;

    return nodo;
}
struct Vertice* createNode(char value){
    struct Vertice* nodo = malloc (sizeof(struct Vertice));
    nodo->value = value;
    nodo->estimate = 10000;
    nodo->explored = false;

    nodo->connectionsLength = 0;
    return nodo;
}
void makeConnection (struct Vertice* a, struct Vertice* b, int weight){

    int actualAidx = a->connectionsLength;
    int actualBidx = b->connectionsLength;

    a->connectionsLength = a->connectionsLength + 1;
    b->connectionsLength++;

    if(!a->connections){
        a->connections = malloc(a->connectionsLength * sizeof(struct Vertice*));
        (a->connections)[actualAidx] = b;
        a->connectionsWeight = malloc(a->connectionsLength * sizeof(int));
        (a->connectionsWeight)[actualAidx] = weight;
    } else{
        a->connections = realloc(a->connections, a->connectionsLength * sizeof(struct Vertice*));
        (a->connections)[actualAidx] = b;
        a->connectionsWeight = realloc(a->connectionsWeight, a->connectionsLength * sizeof(int));
        (a->connectionsWeight)[actualAidx] = weight;

    }



    if(!b->connections){
        b->connections = malloc(b->connectionsLength * sizeof(struct Vertice*));
        *((b->connections)+actualBidx) = a;
        b->connectionsWeight = malloc(b->connectionsLength * sizeof(int));
        (b->connectionsWeight)[actualBidx] = weight;
    } else {
        b->connections = realloc(b->connections, b->connectionsLength * sizeof(struct Vertice*));
        *((b->connections)+actualBidx) = a;
        b->connectionsWeight = realloc(b->connectionsWeight, b->connectionsLength * sizeof(int));
        (b->connectionsWeight)[actualBidx] = weight;
    }
}



void dijkstra(struct Graph* grafo, struct Vertice** listaDeNodosConEstimate, int listaOpcionesSize, struct Vertice* nodoActual, struct Vertice* nodoMeta){
    
    if(nodoActual == nodoMeta){
        printf("chikiribaibai chikiribaibai chikiribaibai tu me pega con la mubi y tu pai pai");
        return;  
    }


    nodoActual->explored = true;
    for (int i = 0; i < nodoActual->connectionsLength; i++){
        if ((nodoActual->connections)[i]->explored == false){
            (nodoActual->connections)[i]->estimate = nodoActual->estimate + (nodoActual->connectionsWeight)[i];
            *(listaDeNodosConEstimate+listaOpcionesSize) = (nodoActual->connections)[i];  
            listaOpcionesSize++;
        }
    }

    struct Vertice* verticeMasChico = listaDeNodosConEstimate[0];
    for (int i = 0; i < listaOpcionesSize; i++){
        printf("perra");
        printf("%c\n", listaDeNodosConEstimate[i]->value);
        if(verticeMasChico->estimate > listaDeNodosConEstimate[i]->estimate){
            verticeMasChico = listaDeNodosConEstimate[i];
        }
    }

    printf("-----\n");
    printf("aja: %c\n", verticeMasChico->value);

    printf("\n\n\n\n");
    

    dijkstra (grafo, listaDeNodosConEstimate, listaOpcionesSize, verticeMasChico, nodoMeta);

}



int main(){


    struct Graph* grafo = createGraph();

    struct Vertice* A = createNodeBegin('A');
    struct Vertice* B = createNode('B');
    struct Vertice* C = createNode('C');
    struct Vertice* D = createNode('D');
    struct Vertice* E = createNode('E');
    struct Vertice* F = createNode('F');
    struct Vertice* G = createNode('G');

    addNodeToGraph(grafo, A);
    addNodeToGraph(grafo, B);
    addNodeToGraph(grafo, C);
    addNodeToGraph(grafo, D);
    addNodeToGraph(grafo, E);
    addNodeToGraph(grafo, F);
    addNodeToGraph(grafo, G);

    makeConnection(A, C, 3);
    makeConnection(A, D, 1);
    makeConnection(C, B, 2);
    makeConnection(B, G, 1);
    makeConnection(D, E, 8);
    makeConnection(E, F, 4);
    makeConnection(F, B, 5);

    // prueba rápida
    /*for (int i = 0; i < A->connectionsLength; i++) {
        printf("A conectado a %c con peso %d\n",
            A->connections[i]->value,
            A->connectionsWeight[i]);
    }*/


    struct Vertice** listaDeNodosConEstimate = malloc(grafo->amountOfNodes * sizeof(struct Vertice*)); 
    int listaOpcionesSize = 0;
    dijkstra(grafo, listaDeNodosConEstimate, listaOpcionesSize, A, B);



    return 0;

}