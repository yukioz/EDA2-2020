#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;
typedef node* pont;

typedef struct aux {
    TIPOCHAVE chave;

    struct aux *esq, *dir;
    
} node;

pont inicializa() { // link
    return(NULL);
}

pont adiciona(pont raiz, pont node) {
    if(raiz == NULL)
        return(node);
    
    if(node->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, node);
    else    
        raiz->dir = adiciona(raiz->dir, node);

    // ignorar chave igual

    return(raiz);
}

pont criarNode(TIPOCHAVE key) {
    pont novoNode = (pont)malloc(sizeof(node));
    novoNode->esq = NULL;
    novoNode->dir = NULL;
    novoNode->chave = key;
    return(novoNode);
}

pont contem(TIPOCHAVE key, pont raiz) {
    if(raiz == NULL)
        return(NULL);
    
    if(raiz->chave == key)
        return raiz;
    
    if(raiz->chave > key)
        return contem(key, raiz->esq);
    
    return (key, raiz->dir);
}

int numeroDeNodes(pont raiz) {
    if(!raiz)
        return 0;
    return(numeroDeNodes(raiz->esq) + 1 + numeroDeNodes(raiz->dir));
}

void exibirArvore(pont raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}

pont buscaNode(pont raiz, TIPOCHAVE key, pont *pai) {
    pont atual = raiz;
    *pai = NULL;
    while(atual) {
        if(atual->chave == key)
            return atual;
        
        if(key < atual->chave)
            atual=atual->esq;
        else 
            atual = atual->dir;
    }
}

pont removeNode(pont raiz, TIPOCHAVE key) {
    pont pai, no, p, q;
    no = buscaNode(raiz, key, &pai);
    if(no == NULL)
        return raiz;

    if(!no->esq || !no->dir) {
        if(!no->esq)
            q = no->dir;
        else
            q = no->esq;
    }
    else {
        p = no;
        q = no->esq;
        while(q->dir) {
            p = q;
            q = q->dir;
        }
    }
    if(!pai) {
        free(no);
        return(q);
    }
    if(key < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;

    free(no);
    return(raiz);
}

int main(){
    pont r = inicializa();
    pont no = criarNode(23);
    r = adiciona(r, no);

    no = criarNode(12);
    r =  adiciona(r,no);
    r = adiciona(r, no);
    r = adiciona(r, no);
    r = adiciona(r, no);

    exibirArvore(r);

    return 0;
}