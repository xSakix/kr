//#include "syscall.h"
#include <unistd.h>

#define EOF -1

int getchar(void);
void putchar(char c);

int main(){

    char c;
    while((c = getchar()) != EOF){
        putchar(c);
    }


    return 0;
}

int getchar(void){
    char c;

    return (read(STDIN_FILENO, &c, 1) == 1) ? c : -1;
}

void putchar(char c){
    write(STDOUT_FILENO, &c, 1);
}