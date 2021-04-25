#include <stdio.h>
#include <stdlib.h>

/* Este módulo implementa uma fila priorizada em um heap. O heap é armazenado num vetor pq[1..N] de vértices. (A posição 0 do vetor não é usada.) */
#define vertex int

static vertex *pq; 
static int N;
/* As prioridades são dadas em um vetor prty[] indexado por vértices: o vértice na posição k de pq[] tem prioridade prty[pq[k]]. O heap é caracterizado pela propriedade prty[pq[k/2]] <= prty[pq[k]] para k = 2,...,N. Portanto, o vértice pq[1] tem prioridade mínima. */
#define greater( i, j) (prty[pq[i]] > prty[pq[j]] ? 1 : 0)
/* O vetor qp[0..N-1] é o "inverso" de pq[]: para cada vértice v, qp[v] é o único índice tal que pq[qp[v]] == v. É claro que qp[pq[i]] == i para todo i. */
static int *qp; 

void PQinit( int maxN) { 
   pq = malloc( (maxN+1) * sizeof (vertex));
   qp = malloc( maxN * sizeof (int));
   N = 0; 
}
/* Supõe-se que teremos sempre N <= maxN. */
int PQempty( void) { 
   return N == 0; 
}

void PQinsert( vertex v, int prty[]) {
   qp[v] = ++N; 
   pq[N] = v; 
   fixUp( N, prty); 
}
/* Retira da fila um vértice v que minimiza prty[v] e devolve v. */
vertex PQdelmin( int prty[]) { 
   exch( 1, N); 
   --N; 
   fixDown( 1, prty); 
   return pq[N+1]; 
}
/* Rearranja a fila depois que a prioridade prty[w] do vértice w diminuiu (e portanto w deve ser deslocada em direção ao início da fila). */
void PQdec( vertex w, int prty[]) { 
   fixUp( qp[w], prty); 
}

static void exch( int i, int j) {
   vertex t;
   t = pq[i]; pq[i] = pq[j]; pq[j] = t;
   qp[pq[i]] = i;
   qp[pq[j]] = j;
}

static void fixUp( int k, int prty[]) {
   while (k > 1 && greater( k/2, k)) {
      exch( k/2, k);
      k = k/2;
   }
}

static void fixDown( int k, int prty[]) { 
   int j;
   while (2*k <= N) { 
      j = 2*k;
      if (j < N && greater( j, j+1)) j++;
      if (!greater( k, j)) break;
      exch( k, j); 
      k = j;
   }
}

void PQfree( ) { 
   free( pq);
   free( qp);
}

int main (void) {

    PQinit(102);
    int i;
    int num;

    for(i=0; i<100; i++) {

        scanf("%d", &num);

        PQinsert(pq, num);
    }

    while(scanf("%d", &num) == 1){
        PQinsert(pq, num);
        PQdelmin
    }

}