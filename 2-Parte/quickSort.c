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

int separa2(int *v, int l, int r){

    int c=v[r];

    int j=l;
    int k;

    for(k=l; k<r; k++){

        if(v[k] < c)
            swap(&v[k],&v[j]);
            
        j++;
    }

    swap(&v[j],&v[r]);

    return j;
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
            swap(&v[i], &v[j]);

    }

    swap(&v[i], &v[r]);

    return i;
}

void quickSort(int *v, int l, int r){

    int j;

    if(r<=l)
        return;

    j=separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1,r);
}


int main() {

    int v[7]= {90,80,30,20,100,50,40};

    quickSort(v, 0, 6);

    int n=7;
    int i=0;

    while(n--){

        printf("%d ", v[i]);
        i++;
    }

    printf("\n");


    return 0;
}