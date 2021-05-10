#include <stdio.h>
#include <stdlib.h>

static int visited[1000];
static int cnt;
int pre[1000];

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
  int w;
  link next;
};
// ...ATE AKI

typedef struct graph *Graph;

struct graph {
    int V;
    int E;
    link *adj;
};

static link NEWnode (int w, link next) { // G->adj[4] = next || 3 -> 2 // w = 3
  link a = malloc(sizeof(struct node));

  if(a==NULL)
    printf("TELA AZUL!\n");

  a->w = w; // guarda W...
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

// int GRAPHEdges(Edge a[], Graph G) {
//   int v, E = 0;
//   link t;

//   for(v=0; v<G->; v++) {
//     for(t=G->adj[v]; t!=NULL; t=t->next) {
//       if(v<t->w) a[E++] = EDGE(v, t->w);

//       return E;
//     }
//   }
// }

void GraphInsertEUni(Graph G, Edge e) { // Edge = aresta (v, w)

  int v = e.v;
  int w = e.w;

  // verifica se já está lá
  for(link a=G->adj[v]; a != NULL; a = a->next) {
    if(a->w == w) { // não é instrutivo, mas v está errado deveria ser w, mas isso foi erro da struct, mas funciona.
      return;
    }
  }

  G->adj[v] = NEWnode(w, G->adj[v]); // retorn a
  G->E++;
}

void GraphRemoveEUni(Graph G, Edge e) { // PERGUNTAR
  int v= e.v;
  int w = e.w;

  // faz a mesma coisa que o "verifica se"
  for(link a=G->adj[v]; a != NULL; a = a->next) {
    if(a->w == w) {
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
      if(v < t->w)
        a[E++] = EDGE(v,t->w);
    }
  }

  return E;
}

void GRAPHshow(Graph G) {

  // printa uma matriz preenchida com suas conexões
  for(int v=0; v<G->V; v++) {
    printf("%2d:", v);
    for(link listra = G->adj[v]; listra !=  NULL; listra=listra->next) {
        printf("%2d", listra->w);
    }
    printf("\n");
  }
}

static void reachR(Graph G, int v) {
  visited[v]=1;
  for(link a = G->adj[v]; a != NULL; a=a->next) {
    if(visited[a->w] == 0)
      reachR(G, a->w);
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

static void dfsR(Graph G, int v) {
  pre[v] = cnt++;

  for(link a=G->adj[v]; a != NULL; a=a->next) {
    int w = a->w;
    if(pre[w] == -1)
      dfsR(G, w);
  }
}

void GRAPHdfs(Graph G) {
  cnt = 0;

  for(int v=0; v<G->V; v++) {
    pre[v] = -1;
  }
  for(int v=0; v<G->V; v++) {
    if(pre[v] == -1);
    dfsR(G, v);
  }
}

// Main <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main() {

  printf("digite um número: ");

  int x;

  scanf("%d", &x);

  Graph matriz = GraphInit(x);

  GRAPHshow(matriz);

  Edge linha;
  int y = 5;
  int a, b;

  while(y--) {

  printf("digite 2 números: ");
  scanf("%d %d", &a, &b);
  linha.v = a;
  linha.w = b;

  GraphInsertEUni(matriz, linha);

  printf("\n");

  GRAPHshow(matriz);

  }

  int z=3;

  while(z--) {
    printf("digite 2 locais: ");
    scanf("%d %d", &a, &b);

    int real = GRAPHreach(matriz, a, b);

    printf("%d\n", real);
  }

  GRAPHdfs(matriz);

  printf("\n%d\n", cnt);

  for(int index=0; index<10; index++){
    printf("%d ", pre[index]);
    printf("\n");
  }

  return 0;
}