#include "getline.h"


// int _getline(char *input){

//     int i, c;
    
//     for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
//         *input++ = c;
//     }

//     if(c == '\n'){
//         *input++ = c;
//     }

//     *input = '\0';

//     return i;
// }


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