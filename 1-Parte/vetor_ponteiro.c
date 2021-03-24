#include <stdio.h>

//Passagem por referência
int main(void){

    int vetor[4]={1,2,3,4};
    int tamanho = sizeof(vetor)/sizeof(int);
    int i;

    for(i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }

    //printf("%d\n", tamanho);

    teste(vetor, tamanho);

    for(i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }

}

void teste(int *vetor, int tam){

    int i, x;

    // Primeira forma:
    /*
    for(i=0; i<tam; i++){
        scanf("%d", &x);
        vetor[i] = x;
    }
    */
    // Segunda forma:
    
    for(i=0; i<tam; i++){
        scanf("%d", &x);
        *(vetor+i) = x;
    }
    
    for(i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }
}