#include <stdio.h>
#include <stdlib.h>

// Separa divide um vetor escolhendo o ultimo elemento do vetor e coloca os números
// menores que ele a sua direita. por fim retorna o ídice da posição do número escolhido.

void swap(int *k, int *j){

    int temp = *k;
    *k = *j;
    *j = temp;
}

int separa (int *v, int l, int r){

    int tam = r-l+1;
    int *menores = malloc(sizeof(int) * tam);
    int *maiores = malloc(sizeof(int) * tam);
    int i, j, N;
    int imenor=0, imaior=0;

    N = v[r];

    for(i=l; i<r; i++){

        if(v[i] < N)
            menores[imenor++] = v[i];
        else
            maiores[imaior++] = v[i];
    }

    i=l;
    for(j=0; j<imenor; j++){

        v[i++] = menores[j];
    }

    v[i] =  N;;

    int Npos = i;
    i++;

    for(j=0; j<imaior; j++){

        v[i++] = maiores[j];
    }

    free(maiores);
    free(menores);

    return Npos;
}

int separa2(int *v, int l, int r){ // sem correção: Ordenou ao contrário ({90,80,30,20,100,50,40}, 0, 6)// depois de consertado: O último continua errado// Depois da 3ª alteração: quebrou tudo.

    int c=v[r]; // 40

    int j=l; // 0
    int k; // random

    for(k=l; k<r; k++){ // k=0

        if(v[k] < c)
            swap(&v[k],&v[j]); // 0-nada, 1-nada,  
            
        j++;
    }

    swap(&v[j],&v[r]); 

    return j; // returna 40 na 1ª vez
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

void quickSort(int *v, int l, int r){

    int j;

    if(r<=l)
        return;


    j=separa2(v, l, r);

    quickSort(v, l, j-1);
    quickSort(v, j+1,r);
}

void quickSort2(int *v, int l, int r){

    int j;

    if(r<=l)
        return;

    if(v[(l+r)/2] < v[r]){ // 1ª vez ele compara 40 e 7
        swap(&v[(l+r)/2], &v[r]);

        if(v[l] < v[(l+r)/2]){ // 1ª vez compara 90 e 40
            swap(&v[r], &v[(l+r)/2]);

            if(v[r] < v[(l+r)/2]) // 1ª vez ele compara 7 e 40
                swap(&v[r], &v[(l+r)/2]); // troca 40 com 7 {90,80,30,20,100,50,7,1,2,3,4,5,6,40}
        }
    }

    j=separa2(v, l, r); // 9
    quickSort2(v, l, j-1);
    quickSort2(v, j+1,r);
}


int main() {

    int v[14]= {90,80,30,20,100,50,40,1,2,3,4,5,6,7}; // 14 elementos, índice de 0 a 13

    quickSort2(v, 0, 13); // <- passa 13

    int n=14;
    int i=0;

    while(n--){

        printf("%d ", v[i]);
        i++;
    }

    printf("\n");


    return 0;
}