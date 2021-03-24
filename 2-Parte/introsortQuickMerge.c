#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef int Item;
int trapstop=0;
int trapsize=0;

int separa(Item *V,int l,int r)
{
  int i=l-1, j=r; Item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}

void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

void insertionsort(Item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-i],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; Item tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}


static void quicksortM3(Item *V,int l, int r,int rec)
{
  if (r-l<=32 || trapstop==1) return;

  if(rec==0)
  {
    trapstop=1;
    return;
  }

  exch(V[(l+r)/2],V[r-1]);
  cmpexch(V[l],V[r-1]);
  cmpexch(V[l],V[r]);
  cmpexch(V[r-1],V[r]);


  int j=separa(V,l+1,r-1);
  quicksortM3(V,l,j-1,rec-1);
  quicksortM3(V,j+1,r,rec-1);
}

void introsortquickmerge(Item *V,int l,int r)
{
  trapsize=2*((int)log2((double)(r-l+1)));
  quicksortM3(V,l,r,trapsize);

  if(trapstop==1)
  {
    fprintf(stderr,"trap/");
    mergesort(V,l,r);
  }
  else
    insertionsort(V,l,r);
}

int main() {

    int v[14]= {90,80,30,20,100,50,40,1,2,3,4,5,6,7}; // 14 elementos, índice de 0 a 13

    introsortquickmerge(v, 0, 14); // <- passa 13

    int n=14;
    int i=0;

    while(n--){

        printf("%d ", v[i]);
        i++;
    }

    printf("\n");


    return 0;
}