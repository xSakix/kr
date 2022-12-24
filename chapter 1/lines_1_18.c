#include <stdio.h>

#define MAXLINE 100

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void trim(char input[],int len);

int main(){

    int len;
    char line[MAXLINE];
    char output[MAXLINE];

    while((len = _getline(line, MAXLINE)) > 0){
        
        copy(output, line);
        trim(output, len);
        if(output[0] != '\0')        
            printf("%s",output);

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

void trim(char input[], int len){
    int i;
    
    for(i = len-1; i >= 0; --i){
        if(input[i] == ' '|| input[i] == '\t' || input[i] == '\b' || input[i] == '\0'){
            input[i] = '\0';
        }else {
            break;
        }
    }
}

