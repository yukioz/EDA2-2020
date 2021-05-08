#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int v;
    int w;
} Edge;

Edge EDGE(int, int);

typedef struct graph {
    int V;
    int E;
    int **adj;
} graph;

typedef struct graph *Graph;

Graph GraphInit(int V) {

    // Alocar struct tio grafo
    Graph G = malloc(sizeof(*G));

    // setar os valores
    G->V = V;
    G->E = 0;
    G->adj = MATRIXInit(V,V,0);

    return G;
}

void GraphInsertE(Graph G, Edge e) {

    int v= e.v;
    int w = e.w;

    if(G->adj[v][w] == 0)
        G->E++;

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void GraphRemoveE(Graph G, Edge e) {

    int v= e.v;
    int w = e.w;

    if(G->adj[v][w] == 1)
      G->E--;

    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GraphEdges(Graph G, Edge a[]) {
  int v;
  int w;
  int E=0;

  for(v=0; v < G->V; v++) {
    for(w=0; w < G->V; w++) {
      if(G->adj[v][w] == 1)
        a[E++] = EDGE(v,w);
    }
  }

  return E;
}

