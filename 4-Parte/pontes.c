#include <stdio.h>
#include <stdlib.h>

static int visited[1000];
static int cnt;
int pre[1000];
// int pa[];
int INT_MAX = 100000002;

typedef struct Edge {
    int v;
    int w;
    int c;
} Edge;

Edge EDGE(int v, int w, int c){

  Edge x;

  x.v = v;
  x.w = w;
  x.c = c;

  return x;
}

// LINK AKI...
typedef struct node *link;

struct node {
  int w;
  int c;
  link next;
};
// ...ATE AKI

typedef struct graph *Graph;

struct graph {
    int V;
    int E;
    link *adj;
};

static link NEWnode (int w, link next, int c) { // G->adj[4] = next || 3 -> 2 // w = 3
  link a = malloc(sizeof*a);

  if(a==NULL)
    printf("TELA AZUL!\n");

  a->w = w; // guarda W...
  a->c = c;
  a->next = next;

  return a;
};

Graph GraphInit(int V) {

  int w;
  // Alocar struct tio grafo
  Graph G = malloc(sizeof(*G));

  // setar os valores
  G->V = V;
  G->E = 0;
  G->adj = malloc(V*sizeof(link)); // lista de tamanha V.

  for(w=0; w<V; w++)
    G->adj[w] = NULL;

  return G;
};

void GraphInsert(Graph G, Edge e) { // Edge = aresta (v, w)

  int v = e.v;
  int w = e.w;
  int c = e.c;

  // verifica se já está lá, prof. não usou

  // for(link a=G->adj[v]; a != NULL; a = a->next) {
  //   if(a->w == w) { // não é instrutivo, mas v está errado deveria ser w, mas isso foi erro da struct, mas funciona.
  //     return;
  //   }
  // }

  G->adj[v] = NEWnode(w, G->adj[v], c); // return a, coloca no início pois é mais barato
  G->adj[w] = NEWnode(v, G->adj[w], c);
  G->E++;
}

int GraphEdges(Edge a[], Graph G) {
  int v, E=0;
  link linha;

  for(v=0; v<G->V; v++)
    for(linha=G->adj[v]; linha != NULL; linha=linha->next)
      if(v<linha->w)
        a[E++] = EDGE(v, linha->w, linha->c);

  return E;
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

void GraphcptD1( Graph G, int s, int *pa, int *dist) {
  int mature[10002]={};

  // Reinicia o Dijsktra
  for(int v=0; v < G->V; v++) {
    pa[v] = -1;
    mature[v] = 0;
    dist[v] = INT_MAX; // coloca falta de tábuas em tudo
  }

  pa[s] = s;
  dist[s] = 0;

  while(1) {
    int min = INT_MAX;
    int y;

    for(int z=0; z<G->V; z++) {
      if(mature[z])
        continue;

      if(dist[z] < min) {
        min = dist[z];
        y = z;
      }
    }

    if(min == INT_MAX)
      break;

    for(link a = G->adj[y]; a != NULL; a = a->next) {
      if(mature[a->w])
        continue;

      if(dist[y] + a->c < dist[a->w]) {
        dist[a->w] = dist[y] +a->c;
        pa[a->w] = y;
      }
    }
    mature[y] = 1;
  }
}

int main() {

  int N, M;
  int v, w, c;
  int pa[10002]={};
  int dist[10002];
  int index;

  scanf("%d %d", &N, &M);

  // acrescentar +2 para ser o ponto de saida e o acampamento.
  int T = N + 2;

  Graph matriz = GraphInit(T);

  // printf("\n%d\n", M);

  while(M--) {
    scanf("%d %d %d", &v, &w, &c);

    Edge ponte = EDGE(v, w, c);

    // printf("%d\n", ponte.c);

    GraphInsert(matriz, ponte);
  }

  // printf("passou aki");

  GraphcptD1(matriz, 0, pa, dist); // guarda as distância do vértice zero para cara vértive no array dist

  // if(M == 0)
  printf("%d\n", dist[T-1]); // distância do vértice zero para o acampamento é T-1;

}