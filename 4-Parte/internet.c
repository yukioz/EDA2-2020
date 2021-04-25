#include <stdio.h>
#include <stdlib.h>

typedef struct internet {
    int download;
    int upload;
} internet;

int comparar(internet x, internet y) {

    if(x.download == y.download){
        if(x.upload < y.upload) {
            return 1;
        }
        return 0;
    } else if(x.download < y.download) {
        return 1;
    }

    return 0;
}

void swap(internet *k, internet *j){

    internet temp = *k;
    *k = *j;
    *j = temp;
}

int separa3(internet *v, int l, int r){

    internet aux = v[r];
    int j=l;

    for(int k=l; k<r; k++) {
        if(comparar(v[k], aux)) {
            swap(&v[k], &v[j]);
            j++;
        }
    }

    swap(&v[j], &v[r]);

    return j;
}

void insertionSort(internet *v, int l, int r){

    int i;
    for(i=r; i>l; i--){
        if(comparar(v[i], v[i-1])) {
            swap(&v[i], &v[i-1]);
        }
    }

    for(i=l+2; i<=r; i++) {
        int j=i;
        internet aux = v[j];

        while (comparar(aux, v[j-1])) {
            v[j] = v[j-1];
            j--;
        }

        v[j] = aux;
    }
}

void quickSortM3(internet *v, int l, int r){

    int j;

    if(r-l<=32){
        return;
    }

    swap(&v[(l+r)/2], &v[r-1]);
    if(comparar(v[l], v[r-1])){ // 1ª vez ele compara 40 e 7  <
        swap(&v[l], &v[r-1]);

        if(comparar(v[l], v[r])){ // 1ª vez compara 90 e 40
            swap(&v[l], &v[r]);

            if(comparar(v[r-1], v[r])) // 1ª vez ele compara 7 e 40
                swap(&v[r-1], &v[r]); // troca 40 com 7 {90,80,30,20,100,50,7,1,2,3,4,5,6,40}
        }
    }

    j=separa3(v, l+1, r-1);
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1,r);
}

void quicksortM3insertion(internet *v,int l,int r)
{
  quickSortM3(v,l,r);
  insertionSort(v,l,r);
}

int main() {

    int D, U, L, T;

    scanf("%d %d %d %d", &D, &U, &L, &T);

    int downloadLimit = (D*(100-L)/100);
    int uploadLimit = (U*(100-L)/100);

    internet *list = malloc(sizeof(internet) * T); 
    int up, down;
    int index=0;

    while(T--) {
        scanf("%d/%d", &down, &up);

        if(down < downloadLimit || up < uploadLimit) {
            list[index].download = down;
            list[index].upload = up;
            index++;
        }
    }

    quicksortM3insertion(list, 0, index-1);

    for(int i=0; i < index; i++) {

        printf("%d/%d\n", list[i].download, list[i].upload);
    }

    return 0;
}