#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int D[61] = {}, E[61] = {};
    int tamanho, pares=0;
    char lado;
    int i;
    // for(i=0; i<61; i++){

    //     printf("%d ", D[i]);
    // }
    while (scanf("%d %c", &tamanho, &lado) != EOF)
    {
        if (lado == 'E')
        {
            E[tamanho]++;
        }
        else
        {
            D[tamanho]++;
        }
        if (E[tamanho] >= 1 && D[tamanho] >= 1)
        {
            E[tamanho]--;
            D[tamanho]--;
            pares++;
        }
    }
    printf("%d\n", pares);

    return 0;
}