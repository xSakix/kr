#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#define PERMS 0666 //RW for owner, group and others
#define BUFSIZE 100

void error(char *,...);

int main(int argc, char *argv[]){

    int f1, f2, n, wn;
    char buf[BUFSIZE];

    if(argc != 3){
        error("Usage: cp from to");
    }

    if((f1 = open(argv[1],O_RDONLY, 0)) == -1){
        error("cp: can't open file %s", argv[1]);
    }

    // if((f2 = open(argv[2], O_CREAT | O_WRONLY, PERMS)) == -1){
    if((f2 = creat(argv[2], PERMS)) == -1){
        error("cp: can't create %s, mode %03o", argv[2], PERMS);
    }

    while((n = read(f1, buf, BUFSIZE)) > 0){
        if((wn = write(f2, buf, n) )!= n){
            // printf("read:%d\n",n);
            // printf("written:%d\n",wn);
            error("cp: write error on file %s", argv[2]);
        }
    }

    close(f1);
    close(f2);

    return 0;
}

void error(char *fmt, ...){

    va_list args;
    
    va_start(args, fmt);

    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);

    exit(1);
}