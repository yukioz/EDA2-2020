#include <stdio.h>
#include <stdlib.h>

// Separa divide um vetor escolhendo o ultimo elemento do vetor e coloca os números
// menores que ele a sua direita. por fim retorna o ídice da posição do número escolhido.

void swap(int *k, int *j){

    int temp = *k;
    *k = *j;
    *j = temp;
}

int separa (int *v,  int l, int r) {

    int pivo = v[r], i=l, j;

    for(j=l; j <=r-1; j++) {
        if(v[j] <= pivo) {
            swap(&v[i], &v[j]);
            i++;
        }
    }

    swap(&v[i], &v[r]);

    return i;
}

int quickselectionSort (int *v, int l, int r, int pos) {

    if(pos > 0 && pos <= r-l+1) {

        int i = separa(v, l, r);;

        if(i - l == pos - 1)
            return pos;

        if (i - l > pos - 1)
            return quickselectionSort(v, l, i-1, pos);

        return quickselectionSort(v, i+1, r, pos-i+l-1);
    }
    
    return r;
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

    int i = P * X;

    quickselectionSort(v, 0, N, i);

    // // teste de print
    // int i = P * X;

    // for(i=0; i<N; i++) {

    //     printf("%d ", v[i]);
    // }

    // printf("\n");

    for(i; i<N && X>0 ; i++, X--) {

        printf("%d\n", v[i]);
    }

    return 0;
}