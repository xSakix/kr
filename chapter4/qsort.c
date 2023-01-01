#include <stdio.h>

#define _swap(t,a,b) {int t = a; a=b; b=t;}

void qsort(int [], int,int);
void swap(int [], int, int);

int main(){

    int v[] = {6,9,5,7,10,8,4,3,2,1};

    qsort(v, 0, 9);

    for(int i = 0; i < 10;i++){
        printf("%d, ", v[i]);
    }
    putchar('\n');

    return 0;
}

void swap(int v[], int i, int j){
    printf("Swapping v[%d] = v[%d] | %d <- %d\n",i,j,v[i],v[j]);
    // int t;
    // t = v[i], v[i] = v[j], v[j] = t;
    _swap(t,v[i],v[j]);
}

void qsort(int v[], int l,int r){
    
    if(l >= r){
        return;
    }

    swap(v,l, (l+r)/2);

    int last = l;

    for(int i = l+1; i <= r; i++){
        if(v[i] < v[l]){
            //this is moving the 'pointer' to the last element which lower than left+1
            int k = ++last;
            //but in the first round it would move the same index to same index
            if(k == i){
                continue;
            }
            swap(v, k,i);
        }
    }
    swap(v, l, last);
    qsort(v, l, last-1);
    qsort(v, last+1,r);
}