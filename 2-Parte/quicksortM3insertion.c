#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void quickSortM3(int *v, int l, int r){

    int j;

    if(r-l<=32){
        return;
    }

    if(v[(l+r)/2] < v[r]){ // 1ª vez ele compara 40 e 7
        swap(&v[(l+r)/2], &v[r]);

        if(v[l] < v[(l+r)/2]){ // 1ª vez compara 90 e 40
            swap(&v[r], &v[(l+r)/2]);

            if(v[r] < v[(l+r)/2]) // 1ª vez ele compara 7 e 40
                swap(&v[r], &v[(l+r)/2]); // troca 40 com 7 {90,80,30,20,100,50,7,1,2,3,4,5,6,40}
        }
    }

    j=separa3(v, l, r); // 9
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1,r);
}

void quicksortM3insertion(int *v,int l,int r)
{
  quickSortM3(v,l,r);
  insertionSort(v,l,r);
}

int main() {

    int v[14]= {90,80,30,20,100,50,40,1,2,3,4,5,6,7}; // 14 elementos, índice de 0 a 13

    quicksortM3insertion(v, 0, 14); // <- passa 13

    int n=14;
    int i=0;

    while(n--){

        printf("%d ", v[i]);
        i++;
    }

    printf("\n");


    return 0;
}