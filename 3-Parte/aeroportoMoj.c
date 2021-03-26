#include <stdio.h>
#include <string.h>

int main() {

  int aeroportCount[101]={}; // Hash
  int aeroporto, voos, x, y, teste = 1;

  while (scanf("%d %d", &aeroporto, &voos) == 2 && aeroporto > 0 && voos > 0) { // scanf retorna +1 para cada variável lida.

    memset(aeroportCount, 0, sizeof(aeroportCount)); // Zera o vetor

    int i;

    for(i=0; i < voos; i++) {

      scanf("%d %d", &x, &y);
      aeroportCount[x]++;
      aeroportCount[y]++;
    }

    int max;
    max = aeroportCount[0];

    for (i = 0; i <= aeroporto; i++){

      if (aeroportCount[i] > max)
        max = aeroportCount[i];
    }

    printf("Teste %d\n", teste++);

    for (i = 1; i <= aeroporto; i++){

      if (aeroportCount[i] == max)
        printf("%d ", i);
    }
    printf("\n\n");
  }
  return 0;
}
