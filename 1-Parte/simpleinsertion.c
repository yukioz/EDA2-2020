#include <stdio.h>

//Structs:

// Declaração de macros e constantes:

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSort(int *v, int l, int r){

    int i, j;
    for(i=l+1; i<r; i++)
        for(j=i; j>l; j--){
            if (v[j] < v[j-1]){

                swap(&v[j], &v[j-1]);
            }
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

    insertionSort(vetor, 0, i);

    printVetor(vetor, i);

    return 0;
}
