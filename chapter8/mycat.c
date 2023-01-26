#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 100

int main(int argc, char *argv[]){

    int fd;
    void filecopy(int f1, int f2);
    char *prog = argv[0];
    char text[BUFSIZE];

    if(argc == 1){
        filecopy(STDIN_FILENO, STDOUT_FILENO);
    }else{
        while(--argc > 0){
            if((fd = open(*++argv,O_RDONLY)) == -1){
                
                sprintf(text, "%s: can't open %s\n", prog, *argv);
                write(STDERR_FILENO, text, strlen(text));
                exit(1);
            }else{
                filecopy(fd, STDOUT_FILENO);
                close(fd);
            }
        }
    }

    if(ferror(stdout)){
        sprintf(text, "%s: error writing stdout\n",prog);
        write(STDERR_FILENO, text, strlen(text));
        exit(2);
    }


    exit(0);
}

void filecopy(int f1, int f2){
    char c;

    while(read(f1, &c, 1) == 1){
        write(f2, &c, 1);
    }
}
