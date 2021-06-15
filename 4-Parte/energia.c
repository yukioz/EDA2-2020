#include <stdio.h>
#include <stdlib.h>

static int pre[100], cnt, menor;

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

struct graph {
    int V; // qntd de vértices
    int E; // qntd de arestas
    int **adj; // matriz
    int **tc;
};

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


Graph GRAPHInit (int v){                        // Quantidade de vértices
    Graph G = malloc (sizeof(*G));
    G->V = v;
    G->E = 0;
    G->adj = matrizInit (v, v, 0);
    return G;
}

void GRAPHInsertE (Graph G, Edge e){            // Iserir arestas conectando os vértices
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0) G->E++;              // +1 na qntd de arestas da matriz
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void GRAPHRemoveE (Graph G, Edge e){            // remove arestas
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 1) G->E--;              // -1 na qntd de arestas da matriz
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GRAPHEdges (Edge a[], Graph G){             // Devolve qntd de arestas ou todas as arestas do grafo g
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
    for(t=0; t < G->V; t++)
        if(G->adj[w][t] != 0)
            if(pre[t] == -1)
                dfsR(G, edge(w,t));
}


void GRAPHSearch (Graph G){
    int v, conexos = 0;
    cnt = 0;
    for (v=0; v <G->V; v++) pre[v] = -1;
    for (v=0; v < G->V; v++)
        if (pre[v] == -1){
            dfsR(G, edge(v,v));
            conexos++;
        }
}

void GRAPHtc (Graph G){
    int i, s, t;
    G->tc = matrizInit(G->V, G->V, 0);
    for (s=1; s < G->V; s++)
        for (t=1; t < G->V; t++)
            G->tc[s][t] = G->adj[s][t];
    for (s=1; s < G->V; s++) G->tc[s][s] = 1;
    for (i=1; i < G->V; i++)
        for (s=1; s < G->V; s++)
            if (G->tc[s][i] == 1)
                for (t=1; t < G->V; t++)
                    if (G->tc[i][t] == 1)
                        G->tc[s][t] = 1;
}

int GRAPHReach (Graph G, int s, int t){             // Saber se vértice s possui caminho ao vértice t
    return G->tc[s][t];
}

int main(){
    int e, l, teste = 0, x = -1, y = -1, i, j; 
    menor = __INT_MAX__;
    scanf("%d%d", &e, &l);
    Edge aresta;
    while (e != 0 || l != 0){
        Graph G = GRAPHInit(e+1);
        for (int cont=0; cont<l; cont++){
            scanf("%d%d", &x, &y);
            aresta = edge(x, y);
            GRAPHInsertE(G, aresta);
        }
        GRAPHtc(G);
        int resp = 1;
        teste++;
        i = 1;
        for(int i=1; i<G->V && resp == 1; i++){
            for(j = i; j<G->V && resp == 1; j++){
                resp = GRAPHReach(G, i, j);
            }
        }
        if(resp == 1)
            printf("Teste %d\nnormal\n\n", teste);
        else
            printf("Teste %d\nfalha\n\n", teste);
        for(int cont=1; cont<G->V; cont++){
            for(j = cont; j<G->V; j++){
                GRAPHRemoveE(G, edge(cont, j));
        }
    }
    scanf("%d%d", &e, &l);
    }
}