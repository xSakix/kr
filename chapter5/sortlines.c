#include <stdio.h>
#include "strcmp.c"
#include "getline.h"
#include "getline.c"
#include "mem.c"
#include "strcpy.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char*[], int nlines);
void writelines(char *[], int nlines);

void qsort(char *[], int left, int right);

int main(){
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }

    printf("error: input too big to sort\n");

    return 0;
}

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines){

    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;

    while((len = _getline(line)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;
        }else{
            line[len-1] = '\0';
            _strcpy(line, p);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines){
    
    while(nlines-- > 0)
        printf("%s\n",*lineptr++);
}


void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right)
        return;
    
    swap(v, left, (left+right)/2);
    last = left;

    for(i = left + 1;i <= right; i++){

        if(_strcmp(v[i],v[left]) < 0){
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
