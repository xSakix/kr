#include <stdio.h>

void squeeze(char s[], char c);

int main(){
    char s[] = "hello world?";

    printf("%s\n",s);
    
    squeeze(s, 'l');

    printf("%s\n",s);

    return 0;
}


void squeeze(char s[], char c){
    int i,j;

    for(i = j = 0;s[i] != '\0'; i++){
        if(s[i] != c){
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}