#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A)  < (B))
#define exch(A,B) { Item t; t=A; A=B; B=t; }

typedef int Item;

static Item *pq;
static Item *data;
static int N;

// Fila priorizada em um heap.(A posição 0 do vetor não é usada.)
void PQinit(Item *pq, int maxN) {
    pq = malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

int PQempty(){
    return N==0; // se N = 0, a fila está vazia.
}

void fixUp(Item *v, int k) {
    while(k>1 && less(v[k/2], v[k])) {
        exch(v[k], v[k/2]);
        k = k/2;
    }
}

void fixDown(Item *v, int k, int N) {
    int j;
    while(2*k <= N) {
        j=2*k;
        if(j<N && less(v[j], v[j+1])) {
            j++;
        }
        if(!less(v[k],v[j])) {
            break;
        }
        exch(v[k],v[j]);
        k = j;
    }
}

void PQinsert(Item *pq, Item novo) {
    pq[++N] = novo;
    fixUP(pq, N);
}

int PQdelMax(Item *pq) {
    exch(pq[1], pq[N]);
    fixDown(pq, 1, --N);
    return pq[N+1];
}

