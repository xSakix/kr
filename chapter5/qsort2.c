#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.c"

#define MAXLINE 100000
char *lineptr[MAXLINE];

int readlines(char *[],int);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[],int left, int right, int (*comp)(void*, void*));
int numcmp(char*,char*);


int main(int argc, char *argv[]){
    
    int nlines;
    int numeric = 0;

    if(argc > 1 && strcmp(argv[1],"-n") == 0){
        numeric = 1;
    }

    if((nlines = readlines(lineptr, MAXLINE)) >= 0){
        _qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }

}

void _qsort(void *v[], int left, int right, int(*comp)(void*,void*)){

    int i, last;
    void swap(void *[], int, int);

    if(left >= right){
        return;
    }

    swap(v, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++){
        if((*comp)(v[i], v[left]) < 0){
            swap(v, ++left, i);
        }
    }

    swap(v, left, last);
    _qsort(v, left, last-1,comp);
    _qsort(v, last+1,right, comp);

}


int numcmp(char *s1, char *s2){
    double v1,v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1 < v2){
        return -1;
    }else if(v1 > v2){
        return 1;
    }

    return 0;
}

void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int readlines(char *lineptr[],int maxlines){
    int _getline(char *line);
    void _strcpy(char *s, char *t);
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

int _getline(char *line){
    
    char *start = line;
    
    for(;line-start < MAXLINE - 1 && (*line = getchar()) != EOF && *line != '\n'; line++);
    if(*line == '\n'){
            line++;
        }
    *line = '\0';

    //without '\0'
    int len = line - start;
    if(!len){
        return len;
    }

    return len + 1;
}

void _strcpy(char *s, char *t){
    while(*t++ = *s++);
}

void writelines(char *lineptr[], int nlines){
    
    while(nlines-- > 0)
        printf("%s",*lineptr++);
}
