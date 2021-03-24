#include <stdio.h>
#include <stdlib.h>

// Separa divide um vetor escolhendo o ultimo elemento do vetor e coloca os números
// menores que ele a sua direita. por fim retorna o ídice da posição do número escolhido.

void swap(int *k, int *j){

    int temp = *k;
    *k = *j;
    *j = temp;
}

int separa3(int *v, int l, int r){

    int i=l-1, j=r, c = v[r];

    for(;;){

        while(v[++i] < c);

        while(c < v[--j]){
            if(j==l)
                break;
        }

        if(i>=j)
            break;

        swap(&v[i], &v[j]);

    }

    swap(&v[i], &v[r]);

    return i;
}

void quickSortM3(int *v, int l, int r){

    int j;

    if(r-l<=32)
        return;

    swap(&v[(l+r)/2], &v[r-1]);

    if(v[l] < v[r-1])
        swap(&v[l], &v[r-1]);

    if(v[l] < v[r])
        swap(&v[l], &v[r]);

    if(v[r-1] < v[r])
        swap(&v[r]-1, &v[r]);

    j=separa3(v, l+1, r-1);
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1,r);
}

void insertionSort(int *v, int l, int r){

    int i, j, aux;
    for(i=1; i<r; i++){
        
        j = i-1;
        aux = v[i];

        while(j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void quicksortM3insertion(int *v,int l,int r)
{
  quickSortM3(v,l,r);
  insertionSort(v,l,r);
}

int main() {

    int N, num;

    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);

    int j;

    for(j=0; j<N; j++){

        scanf("%d", &num);
        v[j] = num;
    }

    quicksortM3insertion(v, 0, N);

    int i;
    for(i=0; i<N; i++){

        if(i < N-1){
            printf("%d ", v[i]);
        }
        else{
            printf("%d", v[i]);
        }
    }

    printf("\n");

    return 0;
}