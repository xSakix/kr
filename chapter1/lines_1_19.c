#include <stdio.h>

#define MAXLINE 100

int _getline(char line[], int maxline);
void revert(char to[], char from[], int len);
void empty(char arr[]);

int main(){

    int len;
    char line[MAXLINE];
    char output[MAXLINE];

    empty(line);
    empty(output);

    while((len = _getline(line, MAXLINE)) > 0){
        
        revert(output, line, len);
        printf("%s\n",output);
        
        empty(line);
        empty(output);

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

void empty(char arr[]){
    int i;
    for(i = 0; i < MAXLINE; ++i)
        arr[i] = 0;
}

void revert(char to[], char from[], int len){
    int i, j;

    for( i = len -1, j = 0; i >= 0; --i, ++j){
        to[i] = from[j];
    }
}

