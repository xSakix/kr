#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    int c;

    int lower = strcmp("./lower", argv[0]) == 0;
    int upper = strcmp("./upper", argv[0]) == 0;

    printf("%s\n",argv[0]);


    while((c = getchar()) != EOF){
        if(lower){
            putchar(tolower(c));        
        }else if(upper){
            putchar(toupper(c));       
        }else{
            putchar(c);
        }
    }
}