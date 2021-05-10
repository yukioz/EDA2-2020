#include <stdlib.h>
#include <stdio.h>

static int cnt, pre[5000], joao, maiorConexo, cont, achou, JoaoConexo;

typedef struct  {
    int v, w;
}Edge;

Edge edge (int i, int v){
    Edge e;
    e.v = i;
    e.w = v;
    return e;
}

typedef struct graph *Graph;

typedef struct graph {
    int V; // qntd de vértices
    int E; // qntd de arestas
    int **adj; // matriz
}graph;

int **matrizInit (int l, int c, int valor){
    int **m;
    m = malloc (l * sizeof(int *));
    for (int i=0; i<l; i++)
        m[i] = malloc (c * sizeof(int));
    for (int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            m[i][j] = 0;
    return m;
    free (m);
}

Graph GRAPHInit (int v){                // Quantidade de vértices
    Graph G = malloc (sizeof(*G));
    G->V = v;
    G->E = 0;
    G->adj = matrizInit (v, v, 0);
    return G;
}

void GRAPHInsertE (Graph G, Edge e){    // Iserir arestas conectando os vértices
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0) G->E++;          // +1 na qntd de arestas da matriz
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void GRAPHRemoveE (Graph G, Edge e){        // Remove arestas
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 1) G->E--;          // -1 na qntd de arestas da matriz
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GRAPHEdges (Edge a[], Graph G){         // Devolve qntd de arestas ou todas as arestas do grafo g
    int v, w, E = 0;
    for(v = 0;v < G->V; v++)
        for(w = v+1;w < G->V; w++)
            if(G->adj[v][w] == 1)
                a[E++] = edge(v,w);  
    return E;  
}

void dfsR (Graph G, Edge e){
    int t, w = e.w;
    pre[w] = cnt++;
    Edge are;
    for(t=0; t < G->V; t++)
        if(G->adj[w][t] != 0)
            if(pre[t] == -1){
                are = edge(w,t);
                dfsR(G, are);
                cont++;
                if(joao == t){
                    achou = 1;
                }
            }
}

int GRAPHSearch (Graph G){
    int v, conexos = 0, x, maiorqntd = 0, posicao;
    cnt = 0;
    Edge e;
    for (v=0; v <G->V; v++) pre[v] = -1;
    for (v=0; v < G->V; v++)
        if (pre[v] == -1){
            e = edge(v,v);
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
    G = GRAPHInit(n);
    while (scanf("%d%d", &x, &w) != EOF)
    {
        e = edge(x, w);
        GRAPHInsertE(G, e);
    }
    GRAPHSearch(G);
}