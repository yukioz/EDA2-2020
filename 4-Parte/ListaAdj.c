#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int v;
  link next;
};

typedef struct Edge {
    int v;
    int w;
} Edge;

Edge EDGE(int, int);

typedef struct graph {
    int V;
    int E;
    link *adj;
} graph;

typedef struct graph *Graph;

link New (int v, link next) {
  link x = malloc(sizeof(*x));

  if(x==NULL)
    printf("TELA AZUL!\n");

  x->v = v;
  x->next = next;

  return x;
}

Graph GraphInit(int V) {

  int v;

  // Alocar struct tio grafo
  Graph G = malloc(sizeof(*G));

  // setar os valores
  G->V = V;
  G->E = 0;
  G->adj = malloc(V*sizeof(link));

  for(v=0; v<V; v++) {
    G->adj[v] = NULL;
  }

  return G;
}

void GraphInsertE(Graph G, Edge e) {

    int v= e.v;
    int w = e.w;

    G->adj[v] = New(w, G->adj[v]);
    G->adj[w] = New(v, G->adj[w]);
    
    G->E++;
}

void GraphRemoveE(Graph G, Edge e) {

    int v= e.v;
    int w = e.w;

    if(G->adj[v] == 1)
      G->E--;

    G->adj[v] = 0;
    G->adj[w] = 0;
}

int GraphEdges(Graph G, Edge a[]) {
  int v;
  link t;
  int E=0;

  for(v=0; v < G->V; v++) {
    for(t=G->adj[v]; t != NULL; t=t->next) {
      if(v < t->v)
        a[E++] = EDGE(v,t->v);
    }
  }

  return E;
}


void dfsR(Graph G, Edge e) {

  int t;
  int w = e.w;
}