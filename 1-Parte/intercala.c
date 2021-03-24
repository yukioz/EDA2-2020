#include <stdio.h>
#include <stdlib.h>

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

    int n=8;
    int tam, num;
    int v[1000002]={};
    int i=0, j=0;

    while(n--){

        scanf("%d", &tam);

        for(i=0;i<tam;i++){

            scanf("%d", &num);

            v[j] = num;
            j++;
        }
    }

    mergesort(v, 0, j-1);

    int k;
    for(k=0;k < j; k++){

        if(k == j-1)
            printf("%d\n", v[k]);
        else{
            printf("%d ", v[k]);
        }
    }


    return 0;
}