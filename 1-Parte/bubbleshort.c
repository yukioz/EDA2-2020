#include <stdio.h>

//Structs:

// Declaração de macros e constantes:

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesort(int *v, int l, int r){

    int i, j;
    for(i=l; i<r; i++)
        for(j=l; j<r-i-1; j++){
            if (v[j] > v[j+1]){

                swap(&v[j], &v[j+1]);
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

    bubblesort(vetor, 0, i);

    printVetor(vetor, i);

    return 0;
}
