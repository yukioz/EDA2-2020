#include <stdio.h>
#include <stdlib.h>

typedef int Item;
static Item qp[100005];
static Item pq[100005];
static int N;
int *vetor;
// void fixDown(Item *pq, int k, int N);
// void fixUp(Item *pq, int k);

#define less(A,B) (vetor[A] > vetor[B])

// Swap function
void exch(int i, int j) {
    int t;
    t = qp[i];
    qp[i] = qp[j];
    qp[j] = t;
    pq[qp[i]] = i;
    pq[qp[j]] = j;
}

// init fila
void PQinit(int maxN) {
    N = 0;
}

int PQespiaMin() {
    return vetor[pq[1]];
}

void fixUp(Item *pq, int k) {
    while(k>1 && less(pq[k/2],pq[k])) {
        exch(pq[k],pq[k/2]);
        k=k/2;
    }
}

void fixDown(Item *pq, int k, int N) {
    int j;
    while(2*k <= N) {
        j=2*k;
        if(j<N && less(pq[j], pq[j+1])) {
            j++;
        }
        if(!less(pq[k],pq[j])) {
            break;
        }
        exch(pq[k],pq[j]);
        k = j;
    }
}

void PQchange(int k) {
    fixUp(pq, qp[k]);
    fixDown(pq, qp[k], N);
}

int PQempty(){
    return N==0; // se N = 0, a fila está vazia.
}

void PQinsert(Item k) {
    qp[k] = ++N;
    pq[N] = k;
    fixUp(pq, N);
}

int PQdelMin() {
    exch(pq[1], pq[N]);
    fixDown(pq, 1, N-1); // --N
    return pq[N--]; // N+1
}

void resolve(int n, int k, int *v) {

    int velho = 0;
    int nexti = k;
    vetor = v;
    PQinit(n);
    int i;
    for(i=0; i<k; i++) {
        PQinsert(i);
    }

    while(nexti<=n) {
        printf("%d", PQespiaMin());
        v[velho] = 0;
        PQchange(velho);
        PQdelMin();
        velho++;
        PQinsert(nexti);
        if(nexti < n)
            printf(" ");
        nexti++;
    }

    printf("\n");
}

int main (void) {

    int v[100005];
    int n,k;
    while(scanf("%d %d", &n, &k) == 2 && n != 0 && k != 0) {
        int i;
        for(i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        resolve(n,k,v);
    }
}