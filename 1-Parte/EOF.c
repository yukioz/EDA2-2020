#include <stdio.h>

int main(){

    int n, total=0;
    while(scanf("%i", &n) != EOF){
        total++;
    }

    printf("%i", total);

    return 0;
}