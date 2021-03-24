#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *v, int l, int r1, int r2){

    int *v2 = malloc(sizeof(int) * (r2-l+1));

    int k=0;
    int i=l, j=r1+1;

    while(i <= r1 && j<= r2){

        if(v[i] <= v[j])
            v2[k++]=v[i++];
        else 
            v2[k++]=v[j++];
    }

    while(i <= r1)
        v2[k++]=v[i++];

    while(j <= r2)
        v2[k++]=v[j++];

    k=0;
    for(i=l; i<= r2; i++){
        v[i]= v2[k++];
    }
    free(v2);
}

void mergesort(int *v, int l, int r){

    if(l>=r)
        return;

    int meio = (r+l)/2;

    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v, l, meio, r);

}

int main(void){

    int n, num, i;

    scanf("%d", &n);

    int *v = (int *)malloc(sizeof(int) * n);

    for(i=0; i<n; i++){

        scanf("%d", &num);

        v[i] = num;

    }

    //int tam = sizeof(v);

    //printf("\n\n!!!%d!!!\n\n", tam);

    mergesort(v, 0, n-1);

    for(i=0; i<n; i++){

        if(i == n-1)
            printf("%d\n", v[i]);
        else
            printf("%d ", v[i]);

    }

    free(v);
}