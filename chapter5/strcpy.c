#include <stdio.h>

void _strcpy(char*, char*);


// void _strcpy(char *s, char *t){
//     while((*t = *s) != '\0'){
//         s++;
//         t++;
//     }
// }

// void _strcpy(char *s, char *t){
//     while((*t++ = *s++) != '\0')
//     ;
// }

void _strcpy(char *s, char *t){
    while(*t++ = *s++);
}