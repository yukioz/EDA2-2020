#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A)  < (B))
// #define exch(A,B) { Item t; t=A; A=B; B=t; }

typedef int Item;

static Item *pq;
static Item *data;
static int N;

void exch(int i, int j) {
    int t;
    t = qp[i];
    qp[i] = qp[j];
    qp[j] = t;
    pq[qp[i]] = i;
    pq[qp[j]] = j;
}

typedef struct pq_ist {
    int N;
    int *pq; // fila de prioridadde, que armazena os índices de um conjunto de Items.
    int *qp; // mantem a posição da heap para o elemento de índice k do conjunto de Item.
} pq_ist;

// Fila priorizada em um heap.(A posição 0 do vetor não é usada.)
void PQinit(Item *pq, int maxN) {
    pq = malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

int PQempty(pq_ist *pq){
    return !pq->N; // se N = 0, a fila está vazia.
}

void fixUp(pq_ist *pq, int k) {
    while(k>1 && less(pq->qp[k/2], pq->qp[k])) {
        exch(pq[k], pq[k/2]);
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

void PQinsert(pq_ist *pq, int k) {
    pq->qp[k] = ++pq->N;
    pq->pq[pq->N] = k;
    fixUP(pq->pq, pq->N);
}

int PQdelMax(Item *pq) {
    exch(pq[1], pq[N]);
    fixDown(pq, 1, --N);
    return pq[N+1];
}

void PQchange(pq_ist *pq, int k) {
    fixUP(pq->pq, qp[k]);
    fixDown(pq->pq, qp[k], pq->N);
}