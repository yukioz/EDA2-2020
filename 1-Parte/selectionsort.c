#include <stdio.h>

//Structs:

// Declaração de macros e constantes:

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int *v, int l, int r){

    int i, j, menor, aux;
    for(i=l; i<r-1; i++){
        menor = i;
        for(j=i+1; j<r; j++){
            if(v[j] < v[menor]){
            menor = j;
            }
        }
    swap(&v[menor], &v[i]);
    }
}

void printVetor(int *v, int tam) 
{ 
    int i; 
    for (i=0; i < tam; i++) 
        printf("%d ", v[i]); 

    printf("\n"); 
}

int main(){

    int vetor[1002];
    int n, i=0;

    while(scanf("%i", &n) != EOF){
        
        vetor[i] = n;
        i++;
    }

    selectionSort(vetor, 0, i);

    printVetor(vetor, i);

    return 0;
}
