#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, num, x, bool=0;

    scanf("%d", &n);

    int vetor[140000]={};
    
    for(i=0; i<n; i++){

        scanf("%d", &num);

        vetor[num] = 1;

    }

    while(scanf("%d", &x) != EOF){

        if(vetor[x] == 1){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }


    }


    return 0;

}