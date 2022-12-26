#include <stdio.h>

#define MAXSIZE 100

void strcat(char s[], char t[]);
void copy(char src[], char dest[]);


int main(){

    char s[MAXSIZE];
    char s2[MAXSIZE];

    copy("Hello ",s);
    copy("World!",s2);

    strcat(s,s2);

    printf("%s\n", s);

    return 0;
}

void copy(char src[], char dest[]){

    int i;

    i = 0;

    while((dest[i] = src[i]) != '\0'){
        i++;
    }

}


void strcat(char s[], char t[]){

    int i, j;

    i = j = 0;
    while(s[i] != '\0'){
        i++;
    }

    while((s[i++] = t[j++]) != '\0');
}
