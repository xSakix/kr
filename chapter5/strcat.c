#include <stdio.h>

#define MAXSIZE 100

void _strcat(char *s, char *t);
void copy(char *src, char *dest);


int main(){

    char s[MAXSIZE];
    char s2[MAXSIZE];

    copy("Hello ",s);
    copy("World!",s2);

    _strcat(s,s2);

    printf("%s\n", s);

    return 0;
}

void copy(char *src, char *dest){

    while((*dest++ = *src++) != '\0')
        ;
}


void _strcat(char *s, char *t){

    while(*s != '\0'){
        s++;
    }

    while((*s++ = *t++) != '\0');
}
