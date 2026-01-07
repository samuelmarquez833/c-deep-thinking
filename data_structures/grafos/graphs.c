#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int **adj;
} Graph;

Graph* graph_create(int n) {
    Graph *g = malloc(sizeof(Graph));
    if (!g) return NULL;

    g->n = n;
    g->adj = malloc(n * sizeof(int*));
    if (!g->adj) { free(g); return NULL; }

    for (int i = 0; i < n; i++) {
        g->adj[i] = calloc(n, sizeof(int)); // todo en 0
        if (!g->adj[i]) {
            // rollback
            for (int k = 0; k < i; k++) free(g->adj[k]);
            free(g->adj);
            free(g);
            return NULL;
        }
    }
    return g;
}

void graph_add_edge(Graph *g, int u, int v) {
    // dirigido: u -> v
    g->adj[u][v] = 1;
}

void graph_add_undirected_edge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void graph_free(Graph *g) {
    if (!g) return;
    for (int i = 0; i < g->n; i++) free(g->adj[i]);
    free(g->adj);
    free(g);
}
