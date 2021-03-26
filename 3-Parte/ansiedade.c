#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char string[4];
    int sim=0, trials=0;
    int i;

    while(scanf("%s", string) != EOF) {

        if(strcmp(string,"sim") == 0){
                sim++;
        }

        for(i=0; i<9; i++){

            scanf("%s", string);

            if(strcmp(string,"sim") == 0){
                sim++;
            }

        }

        if(sim >= 2){
            trials++;
        }
        sim=0;

    }

    printf("%d\n", trials);

}