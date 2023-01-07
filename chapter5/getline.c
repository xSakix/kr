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


int _getline(char *input){

    char *start = input;
    
    for(;input-start < MAXLINE - 1 && (*input = getchar()) != EOF && *input != '\n'; input++);

    *input = '\0';

    //without '\0'
    int len = input - start;
    if(!len){
        return len;
    }

    return len + 1;
}