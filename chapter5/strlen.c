#include <stdio.h>

int _strlen(char*);

int main(){

    printf("%d\n", _strlen("Hello world!"));
    printf("%d\n", _strlen("Hello world!Hello world!"));

    return 0;
}

// int _strlen(char *s){
//     int n;
//     for(n = 0; *s != '\0'; s++){
//         n++;
//     }

//     return n;
// }

int _strlen(char *s){
    char *p = s;

    while(*p != '\0'){
        p++;
    }

    return p - s;
}

