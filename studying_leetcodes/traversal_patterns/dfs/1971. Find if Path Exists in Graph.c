
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uthash.h"
#include <stdbool.h>




/*Uso una minima implementaicon de stack para poder menejar la estrcutra de exploracion necesaria para dfs */

struct Stack{
    int top;
    int* list;
};

struct Stack* initStack(int largo){
    struct Stack *stack = malloc (sizeof(struct Stack));
    stack->top = -1;
    stack->list = malloc(largo * sizeof(int) * 2000);
    return stack;
}

// manejaria los casos borde pero la logica de validPath 
// ya controla que no me vaya a overflow ni a underflow
void push(struct Stack *stack, int n){
    stack->top++;
    *((stack->list)+(stack->top)) = n;
}

void pop(struct Stack *stack){
    stack->top--;
}

void free(struct Stack *stack){
    free(stack);
}



/*Esto es para poder acceder a los vecinos, se sale del scope del area, enotnces use algo generico*/
void buildAdj(int n, int** edges, int edgesSize, int*** adj, int** adjSize){

    *adj = malloc(n * sizeof(int*));
    *adjSize = calloc(n, sizeof(int));

    for(int i = 0; i < edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        (*adjSize)[u]++;
        (*adjSize)[v]++;
    }

    for(int i = 0; i < n; i++){
        (*adj)[i] = malloc((*adjSize)[i] * sizeof(int));
        (*adjSize)[i] = 0;
    }

    for(int i = 0; i < edgesSize; i++){

        int u = edges[i][0];
        int v = edges[i][1];

        (*adj)[u][(*adjSize)[u]++] = v;
        (*adj)[v][(*adjSize)[v]++] = u;
    }
}



/*  funcion  */


bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {


    // esto usamos para los vecinos
    int** adj;
    int* adjSize;
    buildAdj(n, edges, edgesSize, &adj, &adjSize);

    // creamos la estructura de exploracion para dfs
    struct Stack *stack = initStack(n);
    push(stack, source);


    // visited no puede ser declarao con malloc ya que malloc inicializa con basura los arrays, entonces tienes que limpiar
    int visited[n] = {};

    int topeActual;
    while(stack->top != -1){
        // accedemos bien a lo que hay en el tope
        topeActual = *((stack->list)+(stack->top));
        if(visited[topeActual] != 0){
            pop(stack);
        } else{
            visited[topeActual] = 1;
            if (topeActual == destination){
                printf("lo encontramos, es el: %d\n", topeActual);
                return true;
            }
            // asi tal cual como esta, recorres el array por cada consulta - no es solo llegar a O(n^2) - sino que no jala, no funcionara en leetcode
            /*for (int i = 0; i < edgesSize; i++) {
                if (edges[i][0] == topeActual) {
                    int neighbor = edges[i][1];
                    // ok, tiene sentido el evaluar antes de hacer push, lo dejamos, eso esta bien
                    push(stack, neighbor);
                }

                if (edges[i][1] == topeActual) {
                    int neighbor = edges[i][0];
                    push(stack, neighbor);
                }
            }*/
            
            // solo usamos la lista de adyacencia
            for(int i = 0; i < adjSize[topeActual]; i++){
                int neighbor = adj[topeActual][i];
                if(!visited[neighbor]){
                    push(stack, neighbor);
                }
            }

        }
    }

    printf("nada\n");
    return false;

}






void main (){
    int n = 3;

    int edgesSize = 3;
    int edgesColSize = 2;
    
    // necesitas que edges sea int**
    // o sea un puntero a punteros de tipo int
    // o sea un array de arrays de ints
    

    //la mejor manera de hacer esto aqui es asi
    // por que en una sola linea no se puede
    // necesitas tener cada array por separado y lueog haces el array de arrays de ints
    
    int e0[2] = {0,1};
    int e1[2] = {1,2};
    int e2[2] = {2,0};
    int* edges[3] = {e0, e1, e2};
    
    int source = 0;
    int destination = 2;

    validPath(n, edges, edgesSize, &edgesColSize, source, destination);

}