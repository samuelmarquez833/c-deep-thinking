#include <stdio.h>
#include <stdlib.h>


/*
asi como enl la lista enlazada no solo tienes a los nodos, sino que tiene s variables HEAD y TAIL
aqui necesitas una estructura de grafo aparte de los nodos

*/

struct Node {
    int value;
    struct Node **apunta;
    int lenghtOfApunta;
};

// usualmentelas demas cosas que se aniaden al la definicon del grafo con conveniencia
// lo que defini aqui abajo es lo basico minimo, pero no estandar
struct Graph {
    int amountOfNodes;
    struct Node *begins;
};



struct Node *createNode(int val){
    struct Node *node = malloc(sizeof(struct Node ));
    if (node == NULL){
        return NULL;
    }

    node->value = val;
    node->apunta = NULL;
    node->lenghtOfApunta = 0;
    return node;

}

void makeConnection(struct Node *nodeA, struct Node *nodeB){
    
    nodeA->lenghtOfApunta++;


    if (nodeA->apunta == NULL){
        nodeA->apunta = malloc((nodeA->lenghtOfApunta) * sizeof(struct Node*));
    } else {
        nodeA->apunta = realloc(nodeA->apunta, (nodeA->lenghtOfApunta) * sizeof(struct Node*));
    }

    
    // intentar poner el nodo a lo ultimo 
    
    // ya creci el largo arriba
    // quiero meter la direccion del nodo (que claro es tipo struct Node) 
    // al final del vector, pero quiero hacerlo con artimetica de puntos
    // explica no des codigo
    *(nodeA->apunta+nodeA->lenghtOfApunta) = nodeB;
}


int main (){

    struct Graph *grafo = malloc(sizeof(struct Graph));
    struct Node *nodeA = createNode(5);
    grafo->begins = nodeA;
    struct Node *nodeB = createNode(6);
    struct Node *nodeC = createNode(7);
    makeConnection(nodeA, nodeB);
    makeConnection(nodeA, nodeC);


    int largo = nodeA->lenghtOfApunta;
    printf("%d\n", largo);


    struct Node *punteroActual;
    for (int i = 0; i <= largo; i++){
        punteroActual = *(nodeA->apunta+i);
        printf("%p\n", punteroActual);
    }

    printf("porno\n");

    //OJO recuerda el -> ya hace un primer *

    printf("%p\n", nodeA->apunta);
    printf("%p\n", nodeB);
    printf("%p\n", nodeC);


}


