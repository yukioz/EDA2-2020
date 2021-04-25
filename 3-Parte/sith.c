#include <stdio.h>

int main() {

    int num;
    int poder;

    scanf("%d", &num);

    while(num--){

        scanf("%d", &poder);

        if(poder%2 == 0)
            printf("Jedi\n");
        else
            printf("Sith\n");
    }



    return 0;
}