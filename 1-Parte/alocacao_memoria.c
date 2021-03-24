#include <stdio.h>
#include <stdlib.h>

int main(void){

    int *a;
    a = malloc(300);

    a[0]=3;
    a[1]=4;

    printf("%d %d\n", a[0], a[1]);

    teste(a);

    printf("%d %d\n", a[0], a[1]);

    free(a);

    a[0]=3;

    printf("%d %d\n", a[0], a[1]);

}

void teste(int *b){

    int i;
    for(i=0; i<10; i++){
        
        int x;
        scanf("%d", &x);
        b[i] = x;
    }
    
}