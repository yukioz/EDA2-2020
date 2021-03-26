#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char string[4];
    int sim=0, trials=0;
    int i=1;

    while(scanf("%s", string) != EOF) {

        if(strcmp(string,"sim") == 0){
            sim++;
        }

        i++;

        if(i == 10){
            if(sim >= 2){
                trials++;
            }
            i=0;
            sim=0;
        }

    }

    printf("%d\n", trials);

}