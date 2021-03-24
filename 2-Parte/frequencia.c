#include <stdio.h>
#include <string.h>

typedef struct {
    int count;
    int key;
}contador;

int less(contador A, contador B){

    if(A.key == B.key){
        return (A.key < B.key);
    }
    else
        return (A.key < B.key);

}

void swap(int *k, int *j){

    int temp = *k;
    *k = *j;
    *j = temp;
}

int separa3(contador *v, int l, int r){

    int i=l-1, j=r;

    for(;;){

        while(less(v[++i], v[r]));

        while(less(v[r], v[--j])){
            if(j==l)
                break;
        }

        if(i>=j)
            break;

        swap(&v[i].count, &v[j].count);

    }

    swap(&v[i].count, &v[r].count);

    return i;
}

void insertionSort(contador *v, int l, int r){

    int i, j, aux;
    for(i=1; i<r; i++){
        
        j = i-1;
        aux = v[i].count;

        while(j >= 0 && less(v[j], v[i])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1].count = v[i].count;
    }
}

void quickSortM3(contador *v, int l, int r){

    int j;

    if(r-l<=32){
        return;
    }

    if(less(v[(l+r)/2], v[r])){ // 1ª vez ele compara 40 e 7
        swap(&v[(l+r)/2].count, &v[r].count);

        if(less(v[l], v[(l+r)/2])){ // 1ª vez compara 90 e 40
            swap(&v[r].count, &v[(l+r)/2].count);

            if(less(v[r], v[(l+r)/2])) // 1ª vez ele compara 7 e 40
                swap(&v[r].count, &v[(l+r)/2].count); // troca 40 com 7 {90,80,30,20,100,50,7,1,2,3,4,5,6,40}
        }
    }

    j=separa3(v, l, r); // 9
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1,r);
}

void quicksortM3insertion(contador *v,int l,int r)
{
  quickSortM3(v,l,r);
  insertionSort(v,l,r);
}

int main () {

    contador texto[128]={};
    char palavra[1001];

    memset(texto, 0, sizeof(contador) * 128);

    while(scanf("%s", palavra) != EOF){

        int i;
        int tam = strlen(palavra);
        int index, letra,teste;
        int max = 0;

        for(i=0; i<tam; i++) {

            texto[palavra[i]].key = palavra[i];
            texto[palavra[i]].count++;
        }

        quicksortM3insertion(texto, 0, 127);

        i=0;

        while(texto[i].count == 0)
            i++;

        while(texto[i].count != 0){
            printf("%hd %d", texto[i].key, texto[i].count);
            i++;
        }

        printf("\n");
    }

    return 0;
}