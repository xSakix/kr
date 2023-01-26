//#include "syscall.h"
#include <unistd.h>

#define BUFSIZE 100
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
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    //read input in "big" chunks
    if(n == 0){
        n = read(STDIN_FILENO, buf, sizeof buf);
        bufp = buf;
    }


    //after read
    //write/return one char at a time
    return (--n >= 0) ? (unsigned char) *bufp++: EOF;
}

void putchar(char c){
    write(STDOUT_FILENO, &c, 1);
}