#include <stdio.h>
#include <stdlib.h>

static int cnt;
int pre[1000];

typedef struct Edge {
    int v;
    int w;
} Edge;

Edge EDGE(int, int);

// LINK AKI...
typedef struct node *link;

struct node {
  int v;
  link next;
};
// ...ATE AKI

typedef struct graph {
    int V;
    int E;
    link *adj;
};

typedef struct graph *Graph;

static link NEWnode (int v, link next) {
  link a = malloc(sizeof(struct node));

  if(a==NULL)
    printf("TELA AZUL!\n");

  a->v = v;
  a->next = next;

  return a;
}

Graph GraphInit(int V) {

  // Alocar struct tio grafo
  Graph G = malloc(sizeof(*G));

  // setar os valores
  G->V = V;
  G->E = 0;
  G->adj = malloc(V*sizeof(link));

  // Verifica se
  for(int v=0; v<V; v++) {
    G->adj[v] = NULL;
  }

  return G;
}

void GraphInsertE(Graph G, Edge e) {

  int v= e.v;
  int w = e.w;

  // faz a mesma coisa que o "verifica se"
  for(link a=G->adj[v]; a != NULL; a = a->next) {
    if(a->v == w) {
      return;
    }
  }

  // Porque 2x? ida e volta? e se for só ida?
  G->adj[v] = NEWnode(w, G->adj[v]);
  G->adj[w] = NEWnode(v, G->adj[w]);
  
  G->E++;
}

void GraphRemoveE(Graph G, Edge e) { // PERGUNTAR
  int v= e.v;
  int w = e.w;

  // faz a mesma coisa que o "verifica se"
  for(link a=G->adj[v]; a != NULL; a = a->next) {
    if(a->v == w) {
      return;
    }
  }

  // Porque 2x? ida e volta? e se for só ida?
  G->adj[v] = 0;
  G->adj[w] = 0;
  
  G->E--;
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

void dfsR(Graph G, int v) {

  pre[v] = cnt++;
  for(link a = G->adj[v]; a!=NULL; a=a->next){
    int v = a->v;
    if(pre[v] == -1)
      dsfR(G, v);
  }
}

void GRAPHdfs(Graph G) {
  cnt = 0;
  for(int v=0; v<G->V; v++)
    pre[v] = -1;

  for(int v=0; v<G->V; v++){
    if(pre[v] == -1){
      dfsR(G, v);
    }
  }
}

int main() {

  return 0;
}