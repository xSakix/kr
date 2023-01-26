//#include "syscall.h"
#include <unistd.h>

#define BUFSIZE 100

int main(){

    char buf[BUFSIZE];
    int n;

    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0){
        write(STDOUT_FILENO, buf, n);
    }

    return 0;
}