#include <stdio.h>
#include <stdlib.h>

// static --------------------------------------------------------------------------------------------------------------
static int cnt;
int pre[1000];

// Structs -------------------------------------------------------------------------------------------------------------
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

// Iniciando funcões ----------------------------------------------------------------------------------------------
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

// remove e insert ---------------------------------------------------------------------------------------
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

// DFSR ---------------------------------------------------------------------------------------------------------
void dfsR(Graph G, Edge e) {
  int t;
  int w = e.w;
  link l;
  pre[w]=cnt++;

  for(l = G->adj[w]; l!=NULL; l=l->next) {
    t=l->v;
    if(pre[t]==-1)
      dfsR(G,EDGE(w,t));
  }

  
}

// Search --------------------------------------------------------------------------------------------------
void GraphSearch (Graph G) {
  int v;
  cnt=0;
  int conexos=0;
  for(v=0; G->V; v++) {
    pre[v]=-1;
  }
  for(v=0; G->V; v++) {
    if(pre[v] == -1) {
      dfsR(G, EDGE(v,v));
      conexos++;
    }
  }
}

void GRAPHbfs( Graph G, Edge e) {
  int v, w;
}

int main() {

  return 0;
}