#include <stdio.h>
#include <stdlib.h>

int buscabinaria(int *v, int x, int y){

    int inicio = 0, fim = y-1;
    int meio;
    
    while(inicio <= fim){

        int meio = (inicio + fim)/2;

        if(v[meio] < x){

            inicio = meio+1;
        }
        else if(v[meio] > x){

            fim = meio-1;
        }
        else if(v[meio] == x){

            return v[meio];
        }

    }

    return -1;

}

void merge(int *v, int l, int r1, int r2){

    int *v2 = malloc(sizeof(int) * (r2-l+1));

    int k=0;
    int i=l, j=r1+1;

    while(i <= r1 && j<= r2){

        if(v[i] <= v[j])
            v2[k++]=v[i++];
        else 
            v2[k++]=v[j++];
    }

    while(i <= r1)
        v2[k++]=v[i++];

    while(j <= r2)
        v2[k++]=v[j++];

    k=0;
    for(i=l; i<= r2; i++){
        v[i]= v2[k++];
    }
    free(v2);
}

void mergesort(int *v, int l, int r){

    if(l>=r)
        return;

    int meio = (r+l)/2;

    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v, l, meio, r);

}

int set(int *vetor, int tam){

    int array[200000];

    if(tam <= 1)
        return tam;

    int i=0, j=0;

    for(i=0; i<tam-1; i++){

        if(vetor[i] != vetor[i+1]){
            array[j] = vetor[i];
            j++;
        }
    }

    array[j] = vetor[i];
    j++;

    for(i=0; i<j; i++){
        vetor[i] = array[i];
    }

    return j;

}

int main(){

    int N, i=0, j, num, k=0;
    int tam2, tam3;
    int temp;
    int l;

    scanf("%d", &N);

    int vetor[200000];

    for(i; i<N; i++){

        scanf("%d", &num);

        vetor[i] =  num;
        
    }

    //printf("\n>>>%d<<<\n", i);


    mergesort(vetor, 0, N-1);

    tam2 = set(vetor, N);

    // tam2 é a quantidade de itens
    i = tam2;

    //printf("\n\n>>>%d<<<\n", i);

    // Coloca 1 bilhão
    if(tam2%2 != 0){
        vetor[i] = 1000000000;
        tam2++;
        i++;

        // printf("\n>>>%d<<<\n", tam2);

        // printf("\n>>ja>%d<<<\n", vetor[i]);
    }

    for(j=0; j<tam2; j+=2){

        //printf("\n>>>%d<<<\n", i);

        vetor[i] = (vetor[j] + vetor[j+1]);
        //printf("\n>>>%d + %d = %d<<<\n", vetor[j], vetor[j+1], vetor[i]);
        k++;
        i++;

    }

    // até aki está certo

    // printf("\nxxxxxxxxxxxxxxxx\n");

    
    // for(l=0; l<i; l++){

    //     printf("%d: %d\n", l, vetor[l]);
    // }


    mergesort(vetor, 0, tam2+k-1);

    // printf("\n\n>>>%d<<<\n", tam2+k-1);

    // printf("\nxxxxxxxxxxxxxxxx\n");

    
    // for(l=0; l<i; l++){

    //     printf("%d: %d\n", l, vetor[l]);
    // }


    tam3 = set(vetor, tam2+k);

    //printf("\n\n>>>%d<<<\n", i);

    //printf(">>>%d<<<", tam3);

    // for(l=0; l<tam2+k-1; l++){

    //     printf("%d: %d\n", l, vetor[l]);
    // }
    j=0;
    
    while((tam3-j) > 0 && tam3 > 0){

            printf("%d\n", vetor[j]);
            j+=4;
        }
        printf("Elementos: %d\n", tam3);


    return 0;
}