#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char str1[101], str2[101], str3[101], str4[101];
    char *copy;
    char *copy2;
    int tam;

    scanf("%s", str1);
    scanf("%s", str2);

    copy = strstr(str1, str2);
    strcpy(str3, copy);

    int tam = strlen(str1);

    for(int i=0, j=0; i<=tam; i++){
        if(strcpm(str3[j, i], str2)){
            
        }


    }
    
    return 0;
}