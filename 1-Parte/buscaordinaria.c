#include <stdio.h>
#include <stdlib.h>

int buscanormal(int *v, int x, int y){

    int i = 0;
    
    for(i=0; i<y; i++){

        if(v[i] == x){
            return i;
        }

    }

    return -1;

}

int main(){

    int N, M;

    scanf("%d %d", &N, &M);

    int *v = malloc(sizeof(int) * N);
    int i, num;

    for(i=0; i<N; i++){

        scanf("%d", &num);

        v[i] = num;

    }

    /*
    printf("\n\n");

    for(i=0; i<N; i++){

        printf("%d ", v[i]);

    }

    printf("\n\n");
    */

    for(i=0; i<M; i++){

        scanf("%d", &num);

        printf("%d\n", buscanormal(v, num, N));
    }

    return 0;

}