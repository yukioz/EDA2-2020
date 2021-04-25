#include <stdio.h>
#include <stdlib.h>

void swap(int *k, int *j){

    int temp = *k;
    *k = *j;
    *j = temp;
}

int separa3(int *v, int l, int r){

    int aux=v[r];
    int j=l;

    for(int k=l; k<r; k++) {
        if(v[k] < aux){
            swap(&v[k], &v[j]);
            j++;
        }
    }

    swap(&v[j], &v[r]);

    return j;
}

void insertionSort(int *v, int l, int r){

    int i;
    for(i=r; i>l; i--){
        if(v[i-1]>v[i]) {
            swap(&v[i], &v[i-1]);

        }
    }

    for(i=l+2; i<=r; i++) {
        int j=i; int aux = v[j];

        while(aux < v[j-1]) {
            v[j]=v[j-1];
            j--;
        }

        v[j] = aux;
    }
}

void quickSortM3(int *v, int l, int r){

    int j;

    if(r-l<=32){
        return;
    }
    swap(&v[(l+r)/2], &v[r-1]);
    if(v[l] < v[r-1]){
        swap(&v[l], &v[r-1]);

        if(v[l] < v[r]){
            swap(&v[l], &v[r]); // l ou r no primeiro?

            if(v[r-1] < v[r])
                swap(&v[r-1], &v[r]);
        }
    }

    j=separa3(v, l+1, r-1);
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1,r);
}

void quicksortM3insertion(int *v,int l,int r)
{
  quickSortM3(v,l,r);
  insertionSort(v,l,r);
}

int quickSelect(int *v, int l, int r, int pos){

    int j = separa3(v, l, r);

    if(j > pos){
        return quickSelect(v, l, j-1, pos);
    }
    else if(j<pos)
        return quickSelect(v, j+1, r, pos);

    return j;
}

int main() {

    int N, P, X, num;

    scanf("%d", &N); // numero de produtos

    scanf("%d %d", &P, &X); // Página a ser lida e produtos por página

    int *v = malloc(sizeof(int) * N);

    int j;

    for(j=0; j<N; j++){

        scanf("%d", &num);
        v[j] = num;
    }

    int inicio = P * X;
    int fim = inicio + X;

    if(fim > N-1)
        fim = N-1;

    quickSelect(v, 0, N-1, inicio);
    quickSelect(v, inicio+1, N-1, fim);

    quicksortM3insertion(v, inicio, fim);

    // // teste de print
    // int i = P * X;

    // for(i=0; i<N; i++) {

    //     printf("%d ", v[i]);
    // }

    if(fim == N-1){
        for(inicio; inicio <= fim; inicio++){
            printf("%d\n", v[inicio]);
        }
      }
      else{
        for(inicio; inicio < fim; inicio++){
            printf("%d\n", v[inicio]);
        }
      }

    return 0;
}