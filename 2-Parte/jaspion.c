#include <stdio.h>
#include <string.h>

typedef struct{

    int hash;
    char *traduz[81];
}jaspion;

int Hash (char *palavra){



    return 1;
}

int main() {

    int M, N, T;

    scanf("%d", &T);

    while(T--){

        scanf("%d %d", &M, &N);

        char palavra[81];
        char traducao[81];
        int i;

        jaspion lista[1000001];

        for(i=0; i<M; i++){

        scanf(" %[^\n]s\n", palavra); // não pega o \n
        scanf(" %[^\n]s\n", traducao);

        lista[i].traduz = traducao;

        }


    }

    return 0;

}