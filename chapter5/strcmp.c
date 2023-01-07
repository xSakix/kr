#include <stdio.h>

int _strcmp(char*, char*);

/*
if s < t -> negative number
if s == t -> return 0
if s > t -> return positive number
*/
// int _strcmp(char *s, char *t){
//     int  i;
    
//     for(i = 0; s[i] == t[i];i++){
//         if(s[i] == '\0'){
//             return 0;
//         }
//     }

//     return *s - *t;
// }
int _strcmp(char *s, char *t){
    
    for(;*s == *t; s++, t++){
        if(*s == '\0'){
            return 0;
        }
    }

    return *s - *t;
}
