#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vertex int

// Declarações para outras funções:
static int cnt;
int visited[10000];
int pre[10000];
int pa[10000];
int nucleos = 0;

typedef struct Edge
{
  int v;
  int w;
} Edge;

Edge EDGE(int v, int w)
{

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
static int **MatrizInit(int r, int c, int val)
{
  int **m = malloc(sizeof(int *) * r); // aloca espaço para um vetor de tamanho r.

  for (vertex i = 0; i < r; i++)
  {
    m[i] = malloc(sizeof(int) * c); // alocar r vezes um vetor de tamanho c.
  }

  for (vertex i = 0; i < r; i++)
  {
    for (vertex j = 0; j < c; j++)
    {
      m[i][j] = val; // Passa por todas as posições do vetor e coloca o valor val, no caso, é 0.
    }
  }

  return m;
}

Graph GraphInit(int V)
{
  Graph G = malloc(sizeof *G);
  G->V = V;
  G->E = 0;
  G->adj = MatrizInit(V, V, 0);

  return G;
}

void GraphInsertBi(Graph G, Edge E)
{
  int v = E.v;
  int w = E.w;

  if (G->adj[v][w] == 0)
  {
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
    G->E++;
  }
}

void GraphInsertUni(Graph G, Edge E)
{
  vertex v = E.v;
  vertex w = E.w;

  if (G->adj[v][w] == 0)
  {
    G->adj[v][w] = 1;
    G->E++;
  }
}

void GraphRemoveBi(Graph G, Edge E)
{
  vertex v = E.v;
  vertex w = E.w;

  if (G->adj[v][w] == 1)
  {
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
    G->E -= 2;
  }
}

void GraphRemoveUni(Graph G, Edge E)
{
  vertex v = E.v;
  vertex w = E.w;

  if (G->adj[v][w] == 1)
  {
    G->adj[v][w] = 0;
    G->E--;
  }
}

int GraphEdges(Edge arestas[], Graph G)
{
  int v;
  int w;
  int e = 0;

  for (v = 0; v < G->V; v++)
  {
    for (w = v + 1; w < G->V; w++)
    {
      if (G->adj[v][w] == 1)
        arestas[e++] = EDGE(v, w);
    }
  }
  return e;
}

// printa uma matriz preenchida com suas conexões
void GraphShow(Graph G)
{

  for (vertex v = 0; v < G->V; v++)
  {
    printf("%2d:", v);
    for (vertex w = 0; w < G->V; w++)
    {
      if (G->adj[v][w] != 234)
        printf(" %2d", G->adj[v][w]);
    }
    printf("\n");
  }
}

static void Reach(Graph G, int v)
{
  visited[v] = 1;
  for (int w = 0; w < G->V; w++)
  {
    if (G->adj[v][w] == 1 && visited[w] == 0)
      Reach(G, w);
  }
}

int GraphReach(Graph G, int s, int t)
{
  for (int v = 0; v < G->V; v++)
    visited[v] = 0;

  Reach(G, s);

  if (visited[t] == 0)
  {
    return 0;
  }

  return 1;
}

static void dfs(Graph G, vertex v)
{
  pre[v] = cnt++;

  for (int a = 0; a < G->V; a++)
  {
    if (G->adj[v][a] != 0)
    {
      if (pre[a] == -1)
        dfs(G, a);
    }
  }
}

void GraphDFS(Graph G)
{
  cnt = 0;

  for (vertex v = 0; v < G->V; v++)
  {
    pre[v] = -1;
  }
  for (vertex v = 0; v < G->V; v++)
  {
    if (pre[v] == -1)
    {
      dfs(G, v);
      nucleos++;
    }
  }
}

void GraphClean(Graph G) {
  vertex tam = G->V;

  for(vertex i=0; i<tam; i++) {
    free(G->adj[i]);
  }

  free(G->adj);
  free(G);
}

int main()
{

  int matrix[42][42] = {};
  int estations;
  int x, y;
  int ix, iy;
  int flag = 1;
  Graph grafo;
  Edge linha;

  scanf("%d", &estations);

  while (estations)
  {
    grafo = GraphInit(42);

    for (int i = 0; i < estations; i++)
    {

      scanf("%d", &x);
      scanf("%d", &y);
      x = x + 20;
      y = y + 20;

      if (flag)
      {
        ix = x;
        iy = y;
        flag = 0;
      }

      matrix[x][y] = 1;

      if (!flag)
      {
        if (matrix[x - 1][y] == 1)
        {
          linha = EDGE(x, x - 1);
          GraphInsertBi(grafo, linha);
        }

        if (matrix[x + 1][y] == 1)
        {
          linha = EDGE(x, x + 1);
          GraphInsertBi(grafo, linha);
        }

        if (matrix[x][y - 1] == 1)
        {
          linha = EDGE(y, y - 1);
          GraphInsertBi(grafo, linha);
        }

        if (matrix[x][y + 1] == 1)
        {
          linha = EDGE(y, y + 1);
          GraphInsertBi(grafo, linha);
        }
      }
    }

    GraphDFS(grafo);

    printf("%d", nucleos);

    if(nucleos == 1) {
      printf("All stations are reachable\n");
    } else {
      printf("There are stations that are unreachable\n");
    }

    GraphClean(grafo);
    memset(matrix, 0, sizeof(matrix[0][0]) * 42 * 42);
    flag = 1;
    nucleos = 0;
  }
}