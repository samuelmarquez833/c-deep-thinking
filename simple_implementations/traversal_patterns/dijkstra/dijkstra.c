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
    nodo->estimate = 100000;
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
    printf("Nodo actual %c \n", nodoActual->value);

    for (int i = 0; i < nodoActual->connectionsLength; i++){
        if ((nodoActual->connections)[i]->explored == false){
            printf("conexion valida numero %d: %c \n", i, (nodoActual->connections)[i]->value);
            /*
                recorrer lista de nodos con estimate 
                si el nodo hijo esta, preugntate si es su valor gaurdado es mejor al calcualdo
                    si es mejor-> actualiza
                    si no es-> siguiente nodo
                si no esta aniadelo -> siguiente nodo
                en base a cada caso, lista deOpcionesSizes++
            */    
            int a = 0;
            for (int j = 0; j < listaOpcionesSize; j++){
                if (listaDeNodosConEstimate[j] == (nodoActual->connections)[i]){
                    a = 1;
                }
            }
            if (a == 1){
                if(nodoActual->estimate + (nodoActual->connectionsWeight)[i] < (nodoActual->connections)[i]->estimate){
                    (nodoActual->connections)[i]->estimate = nodoActual->estimate + (nodoActual->connectionsWeight)[i];
                    // no crece el tmanaio de la lista
                } else{
                    // no hagas nadaz
                }
            } else if (a == 0) {
                    (nodoActual->connections)[i]->estimate = nodoActual->estimate + (nodoActual->connectionsWeight)[i];
                    *(listaDeNodosConEstimate+listaOpcionesSize) = (nodoActual->connections)[i];  
                    listaOpcionesSize++;
            }   

        }        
    }



    struct Vertice* verticeMasChico = listaDeNodosConEstimate[0];
    int idxMasChico = 0;

    printf("listaOpcionesSize: %d\n", listaOpcionesSize);
    for (int i = 0; i < listaOpcionesSize; i++){
        printf("listaDeNodosConEstimate[%d]: %c\n", i, listaDeNodosConEstimate[i]->value);
        if(verticeMasChico->estimate > listaDeNodosConEstimate[i]->estimate){
            verticeMasChico = listaDeNodosConEstimate[i];
            idxMasChico = i; 
        }
    }

    if(idxMasChico == listaOpcionesSize-1){     
        // asi dejo de tomar en cuenta el ultimo elemento 
        // digmaos qeu size es dos
        //despues de esto, o sea despues de quitar el ultimo elemenot 
        // size es uno, el larog dle array es uno y si insetro un nueov elemento sera en la posicion uno, lo cual veo bien
        listaOpcionesSize--;
    } else if(idxMasChico != listaOpcionesSize-1){
      *(listaDeNodosConEstimate+idxMasChico) = *(listaDeNodosConEstimate+(listaOpcionesSize-1));    
        listaOpcionesSize--;
    }


    
    printf("\n\n\n\n");

    dijkstra (grafo, listaDeNodosConEstimate, listaOpcionesSize, verticeMasChico, nodoMeta);

}


/*
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
    for (int i = 0; i < A->connectionsLength; i++) {
        printf("A conectado a %c con peso %d\n",
            A->connections[i]->value,
            A->connectionsWeight[i]);
    }


    struct Vertice** listaDeNodosConEstimate = malloc(grafo->amountOfNodes * sizeof(struct Vertice*)); 
    int listaOpcionesSize = 0;
    dijkstra(grafo, listaDeNodosConEstimate, listaOpcionesSize, A, F);


    printf("\n\n----\n\n");
    printf("A: %d\n", A->estimate);
    printf("C: %d\n", C->estimate);
    printf("D: %d\n", D->estimate);
    
    printf("B: %d\n", B->estimate);

    printf("E: %d\n", E->estimate);
    printf("F: %d\n", F->estimate);
    printf("G: %d\n", G->estimate);


    return 0;

}
*/


int main(){

    struct Graph* grafo = createGraph();

    struct Vertice* A = createNodeBegin('A');
    struct Vertice* B = createNode('B');
    struct Vertice* C = createNode('C');
    struct Vertice* D = createNode('D');
    struct Vertice* E = createNode('E');

    addNodeToGraph(grafo, A);
    addNodeToGraph(grafo, B);
    addNodeToGraph(grafo, C);
    addNodeToGraph(grafo, D);
    addNodeToGraph(grafo, E);


    makeConnection(A, B, 10);
    makeConnection(A, C, 1);
    makeConnection(C, D, 1);
    makeConnection(D, B, 1);
    makeConnection(B, E, 1);
    makeConnection(C, E, 100);

    struct Vertice** listaDeNodosConEstimate = malloc(grafo->amountOfNodes * sizeof(struct Vertice*)); 
    int listaOpcionesSize = 0;

    dijkstra(grafo, listaDeNodosConEstimate, listaOpcionesSize, A, E);

    printf("\n\n---- RESULTADOS ----\n\n");
    printf("A: %d\n", A->estimate);
    printf("B: %d\n", B->estimate);
    printf("C: %d\n", C->estimate);
    printf("D: %d\n", D->estimate);
    printf("E: %d\n", E->estimate);

    return 0;
}

