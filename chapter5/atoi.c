#include <stdio.h>

int atoi(char*);

int main(){

    printf("%d\n", atoi(""));
    printf("%d\n", atoi("1"));
    printf("%d\n", atoi("11"));
    printf("%d\n", atoi("111"));

    return 0;
}

int atoi(char *s){
    int n = 0;
    
    if(!s){
        return n;
    }

    for(; *s >= '0' && *s <= '9'; s++){
        n = 10*n + (*s-'0');
    }

    return n;
}