#include <stdio.h>
#include <stdlib.h>

int buscabinaria(int *v, int x, int y){

    int inicio = 0, fim = y-1;
    int meio;
    
    while(inicio <= fim){

        int meio = (inicio + fim)/2;

        if(x < v[inicio]){

            return 0;
        }
        else if(x > v[fim]){
            return fim + 1;
        }
        else if(x < v[meio] && x > v[meio-1]){

            return meio;
        }
        else if(x > v[meio] && x < v[meio+1]){

            return meio+1;
        }
        else if(v[meio] < x){

            inicio = meio+1;
        }
        else if(v[meio] > x){

            fim = meio-1;
        }
        else{

            return meio;
        }

    }

    return -1;

}

int main(){

    int N, M;

    scanf("%d %d", &N, &M);

    int *v = malloc(sizeof(int) * N);
    int i, num;

    for(i=0; i<N; i++){

        scanf("%d", &num);

        v[i] = num;

    }

    /*for(i=0; i<N; i++){

        printf("%d ", v[i]);

    }*/

    for(i=0; i<M; i++){

        scanf("%d", &num);

        printf("%d\n", buscabinaria(v, num, N));
    }

    return 0;

}