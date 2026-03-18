#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Queue{
    int front;
    int back;
    int* list;
};

struct Queue* initQueue(int size){
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->back= 0;

    queue->list = malloc(size * sizeof(int));
    return queue;
}


/*
sacas de front - haces crecer solo front 
metes en back - haces crecer solo back

*/



// Put an elemento at the back
void enqueue (struct Queue* queue, int n){
    queue->list[queue->back]= n;
    queue->back += 1;        
}

// Get out the element of the front
int dequeue (struct Queue* queue){
    if (queue->front == queue->back){
        return -1;
    }
    int out = queue->list[queue->front];        
    queue->front += 1;        
    return out;    
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







// I am implementing enqueue on pop since it is more careful at the time of filling the queue (its less probable of getting duplicates there)

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int** adj;
    int* adjSize;
    buildAdj(n, edges, edgesSize, &adj, &adjSize);

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    struct Queue* queue = initQueue(n); 
    enqueue(queue, source);
    visited[source] = 1;

    int currentNode;
    

    
    while(queue->front != queue->back){

        currentNode = dequeue(queue);
        printf("curr: %d\n", currentNode);
        printf("front: %d\n", queue->front);
        printf("back: %d\n", queue->back);
        
        if (currentNode == destination){
            printf("We have found a valid way from source to destination");
            return true;
        }

        for(int i = 0; i < adjSize[currentNode]; i++){
            int neighbor = adj[currentNode][i];
            if (visited[neighbor] == 0){
                printf("aniadimos un vecino: %d\n", neighbor);
                visited[neighbor] = 1;
                enqueue(queue, neighbor);
            }
        } 
    
    }
    
    printf("We have not found a valid way from source to destination");
    return false;



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

    bool out = validPath(nodeCount, edges, edgeCount, &edgesColSize, source, destination);
}
