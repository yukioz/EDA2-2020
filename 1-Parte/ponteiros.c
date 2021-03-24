#include <stdio.h>

//Passagem por referência
int main(void){

    int x;
    x=15;

    teste(&x);

    printf("%d\n", x);

}

void teste(int *a){

    *a = 20;
    printf("%d\n", *a);
}