#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char *, int);

int main(int argc, char *argv[]){

    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    
    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n",c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }


    if(argc != 1){
        printf("Usage: find -x -n pattern\n");
    }else{
        while(_getline(line, MAXLINE) > 0){
            // printf("%s\n", line);
            lineno++;
            if((strstr(line, *argv) != NULL) != except){
                if(number)
                    printf("%ld:",lineno);
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
