#include <stdio.h>
#include <string.h>

void patos (int N){

    int vetormem[1000001]={};
    int cor;
    int i;
    int max=0;
    int index;

    for(i=0; i<N; i++){

        scanf("%d", &cor);

        vetormem[cor]++;

        if(vetormem[cor] > max){
            max = vetormem[cor];
            index = cor;
        }
    }

    printf("%d\n", index);




}

int main(){

    int N;


    scanf("%d", &N);

    while(N !=0){

        patos(N);

        scanf("%d", &N);
    }

}