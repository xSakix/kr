#include <stdio.h>

int _strlen(char s[]);


int main(){


    printf("Empty string length = %d\n",_strlen(""));
    printf("Len = %d\n",_strlen("Hello world!"));
    printf("Len = %d\n",_strlen("Hello world!Hello world!"));

    return 0;
}


int _strlen(char s[]){
    int i;

    i = 0;
    while(s[i] != '\0'){
        ++i;
    }

    return i;
}