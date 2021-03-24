#include <stdio.h>
#include <stdlib.h>

int main(void){

    int **m;

    m = malloc(4*8);

    int i;
    for(i=0; i<4; i++){
        m[i]=malloc(3*4);
    }

}

