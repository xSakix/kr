#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 20

static long positions[100];
static long *posptr = positions;

int get(int, long, char*,int);

int main(int argc, char *argv[]){
    
    long pos = 0L;
    int ret = 1;
    char buf[BUFSIZE];
    
    struct stat st;
    stat("copy.c",&st);
    off_t size = st.st_size;

    int fd = open("copy.c",O_RDONLY, 0);

    while(1){
        memset(buf, 0, BUFSIZE);
        ret = get(fd, (long)pos, buf, BUFSIZE);
        if(ret <= 0){
            break;
        }
        pos += ret;
        write(STDOUT_FILENO,buf,BUFSIZE);
        // write(STDOUT_FILENO,"||",2);
    }

    close(fd);
    
    printf("\nReading order:\n");
    for(long *p = positions; p < posptr; p++){
        printf("\t%ld\n",*p);
    }
    printf("File size: %ld\n",size);

    return 0;
}

int get(int fd, long pos, char *buf, int n){

    *posptr++ = pos;

    if( lseek(fd, pos, 0) >= 0){
        return read(fd, buf,n);
    }

    return -1;    
}