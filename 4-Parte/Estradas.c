#include <stdio.h>
#include <stdlib.h>

static int visited[1000];

// Pode ser substituido por "v" e "w", precisa mudar os parametros! ex: (graph G, int v, int w) -> DAKI... 
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
// ...ATE AKI.

typedef struct graph {
    int V;
    int E;
    int **adj;
} graph;
typedef struct graph *Graph;

// MATRIXint
static int **MATRIXint(int r, int c, int val) {
  int **m = malloc(sizeof(int*)*r); // aloca espaço para um vetor de tamanho r.

  for(int i=0; i<r; i++) {
    m[i] = malloc(sizeof(int)*c); // alocar r vezes um vetor de tamanho c.
  }

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      m[i][j] = val; // Passa por todas as posições do vetor e coloca o valor val, no caso, é 0.
    }
  }

  return m; // retorna um a matriz m.
}

Graph GraphInit(int V) {

    // Alocar struct tio grafo
    Graph G = malloc(sizeof(*G));

    // setar os valores
    G->V = V; // quantidade de elementos da matriz
    G->E = 0; // quantidade de conexões da matriz
    G->adj = MATRIXint(V,V,0); // A matrix quadrada com tudo zero.

    return G; // retorna G, que possui quantos pontos tem em "G", quantas arestas em "E" e disponibiliza a matriz "adj".
}

void GraphInsertE(Graph G, Edge e) {

    int v = e.v; // Pega os valores de e
    int w = e.w;

    if(G->adj[v][w] == 0) // verifica se na matriz dentro de G, na posição v/w é igual a zero, se sim adiciona uma conexão.
        G->E++;

    G->adj[v][w] = 1; // Como é um grafo que conecta ambas as direções setar para 1 tanto v/w como w/v.
    G->adj[w][v] = 1;
}

void GraphInsertEUni(Graph G, Edge e) {

    int v = e.v; // Pega os valores de e
    int w = e.w;

    if(G->adj[v][w] == 0) // verifica se na matriz dentro de G, na posição v/w é igual a zero, se sim adiciona uma conexão.
        G->E++;

    G->adj[v][w] = 1; // Como é um grafo que conecta apenas uma direção.
}

void GraphRemoveE(Graph G, Edge e) {

    int v= e.v;
    int w = e.w;

    if(G->adj[v][w] == 1)
      G->E--;

    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

void GraphRemoveEUni(Graph G, Edge e) {

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
        a[E++] = EDGE(v,w); // No geral captura todas as conexões e armazena dentro do vetor a, você pode passar ele vazio e ele será preenchido talvez?
    }
  }

  return E; // retorna a quantidade de conexões. Conta tanto ida com a volta (2x).
}

void GRAPHshow(Graph G) {

  // printa uma matriz preenchida com suas conexões
  for(int v=0; v<G->V; v++) {
    printf("%2d:", v);
    for(int w=0; w<G->V; w++) {
      if(G->adj[v][w] != 234)
        printf(" %2d", G->adj[v][w]);
    }
    printf("\n");
  }
}

static void reachR(Graph G, int v) {
  visited[v] = 1;
  for(int w=0; w<G->V; w++) {
    if(G->adj[v][w] == 1 && visited[w] == 0)
      reachR(G, w);
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
