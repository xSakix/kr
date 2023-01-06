#include <stdio.h>

#define MAXLINE 100

int readline(char *input){

    int i, c;
    
    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        *input++ = c;
    }

    if(c == '\n'){
        *input++ = c;
    }

    *input = '\0';

    return i;
}