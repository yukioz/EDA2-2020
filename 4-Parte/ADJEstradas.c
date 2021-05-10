#include <stdio.h>
#include <stdlib.h>

static int visited[1000];

typedef struct Edge {
    int v;
    int w;
} Edge;

Edge EDGE(int v, int w){

  Edge x;

  x.v = v;
  x.w = w;

  return x;
}

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
}graph;

typedef struct graph *Graph;

static link NEWnode (int v, link next) {
  link a = malloc(sizeof(struct node));

  if(a==NULL)
    printf("TELA AZUL!\n");

  a->v = v;
  a->next = next;

  return a;
};

Graph GraphInit(int V) {

  // Alocar struct tio grafo
  Graph G = malloc(sizeof(*G));

  // setar os valores
  G->V = V;
  G->E = 0;
  G->adj = malloc(V*sizeof(link)); // lista de tamanha V.

  return G;
};

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

void GraphInsertEUni(Graph G, Edge e) {

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
};

void GraphRemoveEUni(Graph G, Edge e) { // PERGUNTAR
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
  
  G->E--;
};

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

void GRAPHshow(Graph G) {

  // printa uma matriz preenchida com suas conexões
  for(int v=0; v<G->V; v++) {
    printf("%2d:", v);
    for(link listra = G->adj[v]; listra !=  NULL; listra=listra->next) {
        printf(" %2d", G->adj[v]->v);
    }
    printf("\n");
  }
}

static void reachR(Graph G, int v) {
  visited[v]=1;
  for(link a = G->adj[v]; a != NULL; a=a->next) {
    if(visited[a->v] == 0)
      reachR(G, a->v);
  }
}

int GRAPHreach( Graph G, int s, int t) {
  for(int v=0; v<G->V; v++)
    visited[v]=0;

  reachR(G, s);

  if(visited[t] == 0) {
    return 0;
  }
  
  return 1;
}

int main() {

  int V;
  scanf("%d", &V);

  Graph matriz = GraphInit(V);

  Edge linha;
  int v, w, d;
  
  // scanf("%d %d %d", &v, &w, &d);

  while(1) {

    scanf("%d %d %d", &v, &w, &d);

    if(v == 0 && w == 0 && d == 0 )
      break;

    linha.v = v;
    linha.w = w;

    if(d == 1) {
      GraphInsertEUni(matriz, linha);
    } else {
      GraphInsertE(matriz, linha);
    }
  }

  int localA, localB;

  int inda, volta;

  while(scanf("%d %d", &localA, &localB) == 2) {

    if(GRAPHreach(matriz, localA, localB) &&  GRAPHreach(matriz, localB, localA)) {
      printf("Ida e volta\n");
    } else if(GRAPHreach(matriz, localA, localB)) {
      printf("Apenas Ida\n");
    } else if(GRAPHreach(matriz, localB, localA)) {
      printf("Apenas Volta\n");
    } else {
      printf("Impossibru\n");
    }

  }

  return 0;
}
