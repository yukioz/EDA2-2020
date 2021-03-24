#include <stdio.h>

//Structs:

// Declaração de macros e constantes:

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
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

void printVetor(int *v, int tam) 
{ 
    int i; 
    for (i=0; i < tam; i++) 
        printf("%d ", v[i]); 

    printf("\n"); 
}

int main(){

    int vetor[50002];
    int n, i=0;

    while(scanf("%i", &n) != EOF){
        
        vetor[i] = n;
        i++;
    }

    insertionSort(vetor, 0, i);

    printVetor(vetor, i);

    return 0;
}
