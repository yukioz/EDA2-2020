#include <stdio.h>
#include <stdlib.h>

typedef struct _arvore
{
    int info;
    struct _arvore *esq;
    struct _arvore *dir;
} Arvore;

/*Cria uma arvore vazia!*/
Arvore *cria_arv_vazia()
{
    return NULL;
}

/*Cria um no em uma arvore!*/
Arvore *inserir(Arvore *a, int v)
{
    if (a == NULL)
    {
        a = (Arvore *)malloc(sizeof(Arvore)); // criação do HEAD
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else
    {
        a->dir = inserir(a->dir, v);
    }
    return a;
}

void pre_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        printf("%d ", arv->info);
        pre_ordem(arv->esq);
        pre_ordem(arv->dir);
    }
}

void in_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        in_ordem(arv->esq);
        printf("%d ", arv->info);
        in_ordem(arv->dir);
    }
}

void pos_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        pos_ordem(arv->esq);
        pos_ordem(arv->dir);
        printf("%d ", arv->info);
    }
}

int main()
{

    Arvore *a = cria_arv_vazia();
    int num;

    while (scanf("%d", &num) != EOF) // Isso funciona
    {
        a = inserir(a, num);
    }

    in_ordem(a);
    printf("\n");

    return 0;
}