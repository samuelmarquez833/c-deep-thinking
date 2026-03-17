#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Queue{
    int front;
    int back
    int* list;
}

struct Queue* initQueueWithAValue(int size){
    struct Queue* queue = malloc(sizeof(Queue));
    queue->frot = -1;
    queue->back= -1;
    queue->list = malloc(size * sizeof(int));
    return queue;
}


// Put an elemento at the back
void enqueue (struct Queue* queue, int n){
    // if its empty, initialize back and front
    if(queue->front == -1){
        queue->list[queue->front] = -1;
        queue->list[queue->back]= -1;
        return
    }
    // it its not empty just set the back to equal that element 
    queue->list[queue->back] = n;
}

// Get out the element of the front
void dequeue (struct Queue* queue, int n){
    // if there is only one element
    if (queue->list[queue->front] == queue->list[queue->back]){

    }
}


/*
Build adjacency list so neighbors can be accessed in O(degree)
instead of scanning the edges array each time.
*/
void buildAdj(int nodeCount, int** edges, int edgeCount, int*** adj, int** adjSize){
    *adj = malloc(nodeCount * sizeof(int*));
    *adjSize = calloc(nodeCount, sizeof(int));

    // count neighbors
    for(int i = 0; i < edgeCount; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        (*adjSize)[u]++;
        (*adjSize)[v]++;
    }

    // allocate lists
    for(int i = 0; i < nodeCount; i++){
        (*adj)[i] = malloc((*adjSize)[i] * sizeof(int));
        (*adjSize)[i] = 0;
    }

    // fill lists
    for(int i = 0; i < edgeCount; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        (*adj)[u][(*adjSize)[u]++] = v;
        (*adj)[v][(*adjSize)[v]++] = u;
    }
}



bool validPath1(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int** adj;
    int* adjSize;
    buildAdj(n, edges, edgesSize, &adj, &adjSize);

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    int currentNode;

    while(stack->top != -1){


    }
    
}








int main(){
    int nodeCount = 4;
    int edgeCount = 4;
    int edgesColSize = 2;

    int e0[2] = {0,1};
    int e1[2] = {0,2};
    int e2[2] = {1,3};
    int e3[2] = {2,3};
    int* edges[4] = {e0, e1, e2, e3};

    int source = 0;
    int destination = 3;

    bool out = validPath2(nodeCount, edges, edgeCount, &edgesColSize, source, destination);
}
