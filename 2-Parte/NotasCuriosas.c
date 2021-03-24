#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    int N, nota, i;
    int notas[1002]={};
    int maiorFreq = 0, index = 0;

    scanf("%d", &N);

    for(i=0; i<N; i++){

        scanf("%d", &nota);

        notas[nota]++;

        if(notas[nota] == maiorFreq){
            if(nota > index){
                index = nota;
            }
        }
        else if(notas[nota] > maiorFreq){
            maiorFreq = notas[nota];
            index = nota;
        }
    }

    printf("%d\n", index);

    return 0;
}