#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Minimal stack implementation used to control DFS exploration.
Stores only node ids.
*/
struct Stack{
    int top;
    int* list;
};

struct Stack* initStack(int size){
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = -1;

    /*
    DFS invariant:
    stack size ≤ V (number of vertices)
    */
    stack->list = malloc(size * sizeof(int));
    return stack;
}

/*
Overflow/underflow are not checked here.
The DFS logic guarantees the stack never exceeds V
and pop is called only when the stack is non-empty.
*/
void push(struct Stack *stack, int n){
    stack->top++;
    stack->list[stack->top] = n;
}

void pop(struct Stack *stack){
    stack->top--;
}

void freeStack(struct Stack *stack){
    free(stack->list);
    free(stack);
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

/*
visited-on-pop
    ✔ correct
    ✘ stack can grow up to O(E)

visited-on-push
    ✔ correct
    ✔ stack size ≤ O(V)
*/


// visited on pop 
bool validPath1(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int** adj;
    int* adjSize;
    buildAdj(n, edges, edgesSize, &adj, &adjSize);

    struct Stack *stack = initStack(n);
    push(stack, source);

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    int currentNode;

    while(stack->top != -1){

        currentNode = stack->list[stack->top];
        
        pop(stack);
        
        if(currentNode == destination){
            freeStack(stack);
            for(int i = 0; i < n; i++) free(adj[i]);
            free(adj);
            free(adjSize);
            printf("Found, there is a path to: %d\n", currentNode);
            return true;
        }

        if(visited[currentNode] == 0){
            for(int i = 0; i < adjSize[currentNode]; i++){
                int neighbor = adj[currentNode][i];
                if(visited[neighbor] == 0){
                    // A node may be pushed multiple times because it might already be in the stack
                    // but not yet marked as visited.
                    push(stack, neighbor);
                }
            }
        }

        visited[currentNode] = 1;
    }

    freeStack(stack);
    for(int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    printf("No path");
    return false;
}


// visited on push
bool validPath2(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int** adj;
    int* adjSize;
    buildAdj(n, edges, edgesSize, &adj, &adjSize);

    struct Stack *stack = initStack(n);
    push(stack, source);

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    
    visited[source] = 1;
    int currentNode;

    while(stack->top != -1){

        currentNode = stack->list[stack->top];

        printf("Quitamos a: %d\n", currentNode);
        pop(stack);
        
        if(currentNode == destination){
            freeStack(stack);
            for(int i = 0; i < n; i++) free(adj[i]);
            free(adj);
            free(adjSize);
            printf("Found, there is a path to: %d\n", currentNode);
            return true;
        }

        for(int i = 0; i < adjSize[currentNode]; i++){
            int neighbor = adj[currentNode][i];
            if(visited[neighbor] == 0){
                visited[neighbor] = 1;
                printf("Aniadimos un vecino a stack: %d\n", neighbor);
                push(stack, neighbor);
            }
        }
    
    }

    freeStack(stack);
    for(int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    printf("No path");
    return false;
}


int main(){
    int nodeCount = 4;
    int edgeCount = 4;
    int edgesColSize = 2;

    /*
    edges is int** because each edge is a pair [u, v].
    In C we represent this as an array of pointers to int[2].
    */
    int e0[2] = {0,1};
    int e1[2] = {0,2};
    int e2[2] = {1,3};
    int e3[2] = {2,3};
    int* edges[4] = {e0, e1, e2, e3};

    int source = 0;
    int destination = 3;

    bool out = validPath2(nodeCount, edges, edgeCount, &edgesColSize, source, destination);
}
