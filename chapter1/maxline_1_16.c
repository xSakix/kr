#include <stdio.h>

#define MAXLINE 10

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = _getline(line, MAXLINE)) > 0){
        // printf("length:%d\n",len);
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0){
        printf("%s",longest);
    }


    return 0;
}

int _getline(char line[], int maxline){
    int c, i, j , nc;

    nc = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i, ++nc ){
        if(i < maxline - 2){
            line[i] = c;
            j = i;
        }
    }

    line[j++] = '\n';
    line[j] = '\0';

    return nc;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}
