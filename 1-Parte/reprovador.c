#include <stdio.h>
#include <string.h>

//Structs:
typedef struct{

    char nome[21];
    int nota;
}aluno;


// Declaração de macros e constantes:

// Funções

int reprovador(aluno *lista, int tam){

    int i;
    int index = 0;
    for(i=0; i<=tam; i++){

        if(lista[index].nota > lista[i].nota){
            index = i;

        }
        else if(lista[index].nota == lista[i].nota){

            if(strcmp(lista[index].nome,lista[i].nome) < 0){ // index vem antes no alfabeto

                index = i;

            }
        }
        
    }

    return index;

}

int main(){



    aluno aluno[101];
    int turma, i, valor;
    char name[21];
    int instancia = 1;

    while(scanf("%d", &turma) != EOF){

        for(i=0; i<turma; i++){

            scanf("%s", name);
            strcpy(aluno[i].nome, name);

            scanf("%d", &valor);
            aluno[i].nota = valor;
        }
        int reprovado;

        reprovado = reprovador(aluno, turma-1);

        printf("Instancia %d\n", instancia);
        printf("%s\n", aluno[reprovado].nome);

        instancia++;

    }

    return 0;
}