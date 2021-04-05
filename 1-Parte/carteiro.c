#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int num;
    int index;

}Rua;

int main() {

    int casas, encomendas;
    int milao = 1000001;

    scanf("%d %d", &casas, &encomendas);

    int *rua = malloc(sizeof(int) * milao);
    int tempo=0;
    int i;
    int num;
    int index=0;

    for(int i=0; i<casas; i++){

        scanf("%d", &num);
        rua[num] = i;
    }

    int dado;

    for(int i=0; i<encomendas; i++){

        scanf("%d", &dado);

        if(rua[dado] > index)
            tempo += (rua[dado] - index);
        else
            tempo += (index - rua[dado]);

        index = rua[dado];
    }

    printf("%d\n", tempo);

    return 0;
}