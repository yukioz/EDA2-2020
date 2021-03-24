#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int indice;
    int valor;
}item;

int buscabinaria(item *v, int x, int y){

    int inicio = 0, fim = y-1;
    int meio;
    
    while(inicio <= fim){

        int meio = (inicio + fim)/2;

        if(v[meio].valor < x){

            inicio = meio+1;
        }
        else if(v[meio].valor > x){

            fim = meio-1;
        }
        else if(v[meio].valor == x){

            return v[meio].indice;
        }

    }

    return -1;

}

void merge(item *v, int l, int r1, int r2){

    item *v2 = malloc(sizeof(item) * (r2-l+1));

    int k=0;
    int i=l, j=r1+1;

    while(i <= r1 && j<= r2){

        if(v[i].valor <= v[j].valor)
            v2[k++].valor = v[i++].valor;
        else 
            v2[k++].valor = v[j++].valor;
    }

    while(i <= r1)
        v2[k++].valor = v[i++].valor;

    while(j <= r2)
        v2[k++].valor = v[j++].valor;

    k=0;
    for(i=l; i<= r2; i++){
        v[i].valor = v2[k++].valor;
    }
    free(v2);
}

void mergesort(item *v, int l, int r){

    if(l>=r)
        return;

    int meio = (r+l)/2;

    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v, l, meio, r);

}

int main(){

    int N;

    scanf("%d", &N);

    item *v = malloc(sizeof(item) * N);
    int i, num;

    for(i=0; i<N; i++){

        scanf("%d", &num);

        v[i].indice = i;
        v[i].valor = num;

    }

    mergesort(v, 0, N-1);

    int booler;

    while(scanf("%d", &num) != EOF){

         booler = buscabinaria(v, num, N);

         if(booler == -1){
             printf("NAO\n");
         }
         else{
             printf("SIM\n");
         }
    }

    return 0;

}