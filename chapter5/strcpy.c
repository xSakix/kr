#include <stdio.h>

void _strcpy(char*, char*);
int _strlen(char*);

int main(){

    char *s1 = "Hello world!";
    char s2[_strlen(s1)];

    _strcpy(s1, s2);

    printf("%s\n",s2);

    return 0;
}

// void _strcpy(char *s, char *t){
//     while((*t = *s) != '\0'){
//         s++;
//         t++;
//     }
// }

void _strcpy(char *s, char *t){
    while((*t++ = *s++) != '\0')
    ;
}


// void _strcpy(char *s, char *t){
//     while(*t++ = *s++)
//     ;
// }

int _strlen(char *s){
    char *p = s;
    while(*p++ != '\0');

    return p - s;
}
