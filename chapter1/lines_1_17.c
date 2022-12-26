#include <stdio.h>

#define MAXLINE 100
#define MAX_LEN 10

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

    int len;
    char line[MAXLINE];

    while((len = _getline(line, MAXLINE)) > 0){
        // printf("length:%d\n",len);
        if(len >= MAX_LEN){
            printf("%s",line);
        }
    }

    return 0;
}

int _getline(char line[], int maxline){
    int c, i , nc;

    nc = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i, ++nc ){
        if(i < maxline - 2){
            line[i] = c;
        }
    }

    line[i++] = '\n';
    line[i] = '\0';

    return nc;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}
