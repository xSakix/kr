#include <stdio.h>
#include "strcpy.c"

int _strlen(char*);

int main(){

    char *s1 = "Hello world!";
    char s2[_strlen(s1)];

    _strcpy(s1, s2);

    printf("%s\n",s2);

    return 0;
}

int _strlen(char *s){
    char *p = s;
    while(*p++ != '\0');

    return p - s;
}
