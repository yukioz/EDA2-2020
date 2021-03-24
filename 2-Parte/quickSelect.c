#include <stdio.h>

int quickSelect(int *v, int l, int r, int pos){

    int j = separa(v, l, r);

    if(j > pos) {
        return quickSlect(v, l, j-1, pos);
    }
    else if(j < pos) {
        return quickSelect(v, j+1, pos);
    }

    return j;
}