#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t; t = A; A = B; B = t; }

typedef int Item;

static Item *pq;
static Item *data;
static int N;

Item PQespiaMax()
{
    return pq[1];
}

// Fila priorizada em um heap.(A posição 0 do vetor não é usada.)
void PQinit(int maxN)
{
    pq = malloc(sizeof(Item) * (maxN + 1));
    N = 0;
}

int PQempty()
{

    return N == 0; // se N = 0, a fila está vazia.
}

void fixUp(int k)
{

    if (k > 1 && less(pq[k - 1], pq[k]))
    {
        exch(pq[k], pq[k-1]);
        k--;
        fixUp(k);
    }
    
}

void fixDown(int k, int N)
{
    int j;
    while (2 * k <= N)
    {
        j = 2 * k;
        if (j < N && less(pq[j], pq[j + 1]))
        {
            j++;
        }
        if (!less(pq[k], pq[j]))
        {
            break;
        }
        exch(pq[k], pq[j]);
        k = j;
    }
}

void PQinsert(int novo)
{
    pq[++N] = novo;
    fixUp(N);
}

int PQdelMax()
{
    printf("\n>>>1: %d <<<\n", pq[N]);
    exch(pq[1], pq[N]);
    printf("\n>>>2: %d <<<\n", pq[N]);
    fixDown(1, --N);
    printf("\n>>>3: %d <<<\n", pq[N]);
    return pq[N + 1];
}

void PQworkAroundMax(Item x)
{
    pq[1] = x;
    fixDown(1, N);
}

void imprimeHeap(int listar, int tam)
{

    if (PQempty() || listar == 0)
    {
        return;
    }

    int x = pq[tam--];
    if (listar == 1)
    {
        printf("%d\n", x);
    }
    else
    {
        printf("%d ", x);
    }
    listar--;
    imprimeHeap(listar, tam);
}

int main(void)
{

    PQinit(101);

    int placa;
    int listar;
    int x;
    int count = 0;
    while (scanf("%d", &x) != EOF)
    {

        if (x == 1)
        {
            if (count > 100)
            {
                scanf("%d", &placa);
                if (placa < PQespiaMax())
                {
                    PQworkAroundMax(placa);
                }
            }
            else
            {
                scanf("%d", &placa);
                PQinsert(placa);
                count++;
            }
        }
        else if (x == 2)
        {

            scanf("%d", &listar);

            imprimeHeap(listar, N);
        }
    }
}