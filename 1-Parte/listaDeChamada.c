#include <stdio.h>

int main(){

    int lista[1000002]={};
    int turma, i, valor, aux=1, j;
    int total=0;

    scanf("%d", &turma);

    for(i=0; i<turma; i++){
        
        scanf("%d", &valor);

        lista[valor]=1;

    }

    for(i=0; i<=1000000; i++){

        if(lista[i] == 1){
            total++;
        }
    }

    printf("%d\n", total);

    return 0;
}
