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

/*
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

    // conexiones del caso tricky
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
*/

/*
struct Vertice {

    struct Vertice** connections;
    int connectionsLength;
    int *connectionsWeight; 
};

struct Graph {
    int amountOfNodes;
    struct Vertice** nodes;
};
*/

void dijkstraRecursion(int actualNode, int endNode, int *explored, int estimate){

    

}

void networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    
    int biggest = 0;
    for (int i = 0; i < timesSize; i++){
        for (int j = 0; j < (*(timesColSize)-1); j++){
            if(biggest < times[i][j]){
                biggest = times[i][j];
            }
        }        
    }

    //para accder a los datos del dos por ejemplo solo es explored 2-1
    
    // array compuesto de 0 y 1
    int *explored = malloc(biggest * sizeof(int));
    // estimados
    int *estimate = malloc(biggest * sizeof(int));

    // values it self
    int *values = malloc(biggest * sizeof(int));
    
    int **adyacents = malloc(biggest * sizeof(int*));
    // this array has the lenghts of each subarray representing the nieghbors in the array above - in a respective manner
    int *lengthByPosition = malloc (biggest*sizeof(int));

    // for to fill the values array with the values 
    // and also to fill the adyacents array 
    for (int i = 0; i < 4; i++){
        *(values+i) = (i+1);
        *(lengthByPosition+i) = 0;
        *(adyacents+i) = malloc(*(lengthByPosition+i) * sizeof(int));
    }


    printf("\n\n");

    // el largo es cero
    // crece el largo
    // e inserta en el largo -1
    
    int first = 0;
    int second = 0;
    for (int i = 0; i < timesSize; i++){
        first = times[i][0];
        second = times[i][1];
        printf("%d y %d \n", times[i][0], times[i][1]);

        *(lengthByPosition+(first-1)) = *(lengthByPosition+(first-1)) + 1;
        *(adyacents+(first-1)) = realloc(*(adyacents+(first-1)), sizeof(int)**(lengthByPosition+(first-1)));
        *(*(adyacents+(first-1))+(*(lengthByPosition+(first-1))-1)) = times[i][1];

        *(lengthByPosition+(second-1)) = *(lengthByPosition+(second-1)) + 1;
        *(adyacents+(second-1)) = realloc(*(adyacents+(second-1)), sizeof(int)**(lengthByPosition+(second-1)));
        *(*(adyacents+(second-1))+(*(lengthByPosition+(second-1))-1)) = times[i][0];
    }

    for (int i = 0; i < biggest; i++){
        for (int j = 0; j < *(lengthByPosition+i); j++){
            printf("%d ", *(*(adyacents+i)+j));
        }
        printf("\n\n");
    }




}
    

void main (){
    int k = 2;
    int n = 4;
    

    int timesColSize = 3;
    int e1[3] = {2,1,1};
    int e2[3] = {2,3,1};
    int e3[3] = {3,4,1};  
    
    int timesSize = 3;
    int* times[3] = {e1,e2,e3};

    networkDelayTime(times, timesSize, &timesColSize, n, k);


}