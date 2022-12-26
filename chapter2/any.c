#include <stdio.h>

#define true 1
#define false 0
#define NOT_FOUND -1

int any(char s[], char c[]);

int main(){
    int index = NOT_FOUND;
    char s[] = "hello world?";

    printf("%s\n",s);
    
    index = any(s, "abc");
    printf("%d\n",index);

    index = any(s, "low");
    printf("%d\n",index);

    return 0;
}


int any(char s[], char c[]){
    int i,j,k, found;

    for(i = j = 0;s[i] != '\0'; i++){
        found = false;
        for(k = 0; c[k] != '\0';k++){
            found = found || s[i] == c[k];
        }
        if(found){
            return i;
        }
    }

    return NOT_FOUND;
}