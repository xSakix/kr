#include <stdio.h>

#define true 1
#define false 0

void squeeze(char s[], char c[]);

int main(){
    char s[] = "hello world?";

    printf("%s\n",s);
    
    squeeze(s, "low");

    printf("%s\n",s);

    return 0;
}


void squeeze(char s[], char c[]){
    int i,j,k, found;

    for(i = j = 0;s[i] != '\0'; i++){
        found = false;
        for(k = 0; c[k] != '\0';k++){
            found = found || s[i] == c[k];
        }
        if(!found){
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}