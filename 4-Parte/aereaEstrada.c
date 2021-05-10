#include <stdio.h>
#include <stdlib.h>

#define vertex int

// Declarações para outras funções:
static int cnt;
static int joao, maiorConexo, cont, achou, JoaoConexo;
int visited[10000];
int pre[10000];
int pa[10000];
int nucleos = 0;


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

// Matrix de adjacência
struct graph
{
  int V;
  int E;
  int **adj;
};

typedef struct graph *Graph;

// Inicializa a Matriz de adj
static int **MatrizInit(int r, int c, int val) {
  int **m = malloc(sizeof(int*)*r); // aloca espaço para um vetor de tamanho r.

  for(vertex i=0; i<r; i++) {
    m[i] = malloc(sizeof(int)*c); // alocar r vezes um vetor de tamanho c.
  }

  for(vertex i=0; i<r; i++) {
    for(vertex j=0; j<c; j++) {
      m[i][j] = val; // Passa por todas as posições do vetor e coloca o valor val, no caso, é 0.
    }
  }

  return m;
}

Graph GraphInit(int V) {
  Graph G = malloc(sizeof*G);
  G->V=V;
  G->E=0;
  G->adj = MatrizInit(V,V,0);

  return G;
}

void GraphInsertBi(Graph G, Edge E) {
  int v = E.v;
  int w = E.w;

  if(G->adj[v][w] == 0) {
    G->E++;
  }

  G->adj[v][w] = 1;
  G->adj[w][v] = 1;
}

void GraphInsertUni(Graph G, Edge E) {
  vertex v = E.v;
  vertex w = E.w;

  if(G->adj[v][w] == 0) {
    G->E++;
  }
  
  G->adj[v][w] = 1;
}

void GraphRemoveBi(Graph G, Edge E) {
  vertex v = E.v;
  vertex w = E.w;

  if(G->adj[v][w] == 1) {
    G->E--;
  }

  G->adj[v][w] = 0;
  G->adj[w][v] = 0;
}

void GraphRemoveUni(Graph G, Edge E) {
  vertex v = E.v;
  vertex w = E.w;

  if(G->adj[v][w] == 1) {
    G->E--;
  }

  G->adj[v][w] = 0;
}

int GraphEdges(Edge arestas[], Graph G) {
  int v;
  int w;
  int e=0;

  for(v=0; v< G->V; v++) {
    for(w = v+1; w<G->V; w++) {
      if(G->adj[v][w] == 1)
        arestas[e++] = EDGE(v, w);
    }
  }
  return e;
}

// printa uma matriz preenchida com suas conexões
void GraphShow(Graph G) {

  for(vertex v=0; v<G->V; v++) {
    printf("%2d:", v);
    for(vertex w=0; w<G->V; w++) {
      if(G->adj[v][w] != 234)
        printf(" %2d", G->adj[v][w]);
    }
    printf("\n");
  }
}

void GraphDestroy(Graph G) {
  vertex tam = G->V;

  for(vertex i=0; i<tam; i++) {
    free(G->adj[i]);
  }

  free(G->adj);
  free(G);
}

static void Reach(Graph G, int v) {
  visited[v] = 1;
  for(int w=0; w<G->V; w++) {
    if(G->adj[v][w] == 1 && visited[w] == 0)
      Reach(G, w);
  }
}

int GraphReach( Graph G, int s, int t) {
  for(int v=0; v<G->V; v++)
    visited[v]=0;

  Reach(G, s);

  if(visited[t] == 0) {
    return 0;
  }

  return 1;
}

void dfsR (Graph G, Edge e){
    int t, w = e.w;
    pre[w] = cnt++;
    Edge are;
    for(t=0; t < G->V; t++)
        if(G->adj[w][t] != 0)
            if(pre[t] == -1){
                are = EDGE(w,t);
                dfsR(G, are);
                cont++;
                if(joao == t){
                    achou = 1;
                }
            }
}

int GRAPHSearch (Graph G){
    int v; // index do laço
    int conexos = 0;
    int maiorqntd = 0;
    int posicao;
    cnt = 0;
    Edge e;
    
    for (v=0; v <G->V; v++){
      pre[v] = -1;
    }

    for (v=0; v < G->V; v++)
        if (pre[v] == -1){
            e = EDGE(v,v);
            cont = 0;
            dfsR(G, e);
            conexos++;
            if (achou == 1)
                JoaoConexo = conexos;           // saber qual conexo joão está (primeiro, segundo...)
            if (cont >= maiorqntd){
                if (cont == maiorqntd){
                    if (achou == 1){
                        maiorqntd = cont;
                        maiorConexo = conexos;
                        posicao = v;
                    }
                }
                else{
                    maiorqntd = cont;
                    maiorConexo = conexos;
                    posicao = v;
                }
            }
            achou = 0;
        }
    if(maiorConexo == JoaoConexo){
        if(maiorqntd >= 1)
            printf("Bora pra estrada\n");
        else
            printf("Fique em casa\n");
    }
    else if(conexos == 1 || posicao == joao)
        printf("Bora pra estrada\n");
    else
        printf("Vamos para %d\n", posicao);
}

int main(){
    int n, x, v, w, j;
    scanf("%d%d", &n, &j);
    joao = j;
    maiorConexo = 0;
    achou = 0;
    JoaoConexo = 0;
    Edge e;
    Graph G;
    G = GraphInit(n);
    while (scanf("%d%d", &x, &w) != EOF)
    {
        e = EDGE(x, w);
        GraphInsertBi(G, e);
    }
    GRAPHSearch(G);
}