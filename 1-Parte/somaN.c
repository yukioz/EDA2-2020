#include <stdio.h>

int main(){

    int N;

    scanf("%i", &N);

    int i, x, soma = 0;

    for(i=0;i<N;i++){

        scanf("%i", &x);

        soma += x;
    }

    printf("%i\n", soma);
}