#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char *, int);

int main(int argc, char *argv[]){

    char line[MAXLINE];
    int found = 0;
    
    if(argc != 2){
        printf("Usage: find pattern\n");
    }else{
        while(_getline(line, MAXLINE) > 0){
            if(strstr(line, argv[1]) != NULL){
                printf("%s\n", line);
                found++;
            }
        }
    }

    return found;
}

int _getline(char *line, int max){

    char *start = line;
    
    for(;line-start < max - 1 && (*line = getchar()) != EOF && *line != '\n'; line++);

    *line = '\0';

    //without '\0'
    int len = line - start;
    if(!len){
        return len;
    }

    return len + 1;
}
