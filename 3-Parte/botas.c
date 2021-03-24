#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_pilha(){
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
    return topo;
}

int isPilhaVazia(celula *pilha){
    if(pilha->prox == NULL)
        return 0;
    else
        return 1;
}

void empilha (celula *p, int x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->dado = x;
    ponteiro->prox = p->prox;
    p->prox = ponteiro;
}

int desempilha (celula *p){
    int numero = 0;
    celula *lixo = p->prox;
    numero = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return numero;
}

int main(){
    celula *botas[31];
    int tamanho = 0, par = 0, desempilhado = 0, lado = 0, vazia = 0;
    char pe;

    for(int i = 0; i < 31; i++){
        botas[i] = cria_pilha();
    }

    while(scanf("%d %c", &tamanho, &pe)!=EOF){
        if(isPilhaVazia(botas[tamanho-30]) == 0)
            empilha(botas[tamanho-30], pe);
        else{
            desempilhado = desempilha(botas[tamanho-30]);
            if(desempilhado != pe)
                par++;
            else{
                empilha(botas[tamanho-30], pe);
                empilha(botas[tamanho-30], pe);
            }
        }
    }

    printf("%d\n", par);
}