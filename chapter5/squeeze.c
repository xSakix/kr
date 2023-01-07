#include <stdio.h>

void squeeze(char *, char);

int main(){
    char s[] = "hello world?";

    printf("%s\n",s);
    
    squeeze(s, 'l');

    printf("%s\n",s);

    return 0;
}


void squeeze(char *s, char c){
    char *p = s;

    for(;*s;  s++){
        if(*s != c){
            *p++ = *s;
        }
    }

    *p = '\0';
}