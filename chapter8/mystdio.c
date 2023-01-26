#define NULL        0
#define EOF         (-1)
#define BUFSIZE     1024
#define OPEN_MAX    20

typedef struct _iobuf {
    int cnt;    //chars left    
    char *ptr;  //next char pos
    char *base; //location of buffer
    int flag;   //mode of file access
    int fd;     //file descriptor
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

enum _flags {
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,
    _EOF    = 010,
    _ERR    = 020
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)  (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define PERMS 0666

FILE *myfopen(char *name, char *mode){

    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        return NULL;
    }

    for(fp = _iob;fp < _iob+OPEN_MAX;fp++){
        if((fp->flag & (_READ | _WRITE)) == 0){
            break; //found free slot
        }
    }

    if(fp >= _iob + OPEN_MAX){ //no free spot
        return NULL;
    }

    if(*mode == 'w'){
        fd = creat(name, PERMS);
    }else if(*mode == 'a'){
        if((fd = open(name, O_WRONLY,0)) == -1){
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2); // move to the end of file to append data
    }else{
        fd = open(name, O_RDONLY, 0);
    }

    if(fd == -1){ //couldn't access file
        return NULL;
    }

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;

    return fp;
}

int _fillbuf(FILE *fp){

    int bufsize;

    if((fp->flag & (_READ | _EOF | _ERR)) != _READ){
        return EOF;
    }

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

    if(fp->base == NULL){ //no buffer yet
        if((fp->base = (char*)malloc(bufsize)) == NULL){
            return EOF;
        }
    }

    fp->ptr = fp->base;
    //read a maximum of 1024 into fp->ptr which equals fp->base from file descriptor fp->fd
    //reading is blocking, and will block any other processing until done!
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    
    const char *msg = "Reading done...\n";
    write(STDOUT_FILENO, msg, strlen(msg));

    if(--fp->cnt < 0){
        if (fp->cnt == -1){
            fp->flag |= _EOF;
        }else{
            fp->flag += _ERR;
        }
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}


FILE _iob[OPEN_MAX] = {
    {0, (char*)0, (char*)0, _READ, 0},
    {0, (char*)0, (char*)0, _WRITE, 1},
    {0, (char*)0, (char*)0, _WRITE | _UNBUF, 2}
};

//is not full implementation. Just so much code to make the getchar/putchar demo work
int _flushbuf(int c, FILE *fp)
{
    //#define putc(x, p)  (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))
    //we work with a buffer here and flush only when all chars where moved to it
    //--(p)->cnt means lower the count of characters left to read
    //if number of chars left >= 0, than *(p)->ptr++ mean, to move to the next character position on fp and put x there
    //otherwise if chars left < 0, flush to the screen


    //#define putchar(x)  putc((x), stdout)
    //#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
    //#define getchar()   getc(stdin)
    int n;

    n = write(fp->fd, &c, 1);

    if((fp->flag & (_WRITE | _ERR | _EOF)) != _WRITE){
        return EOF;
    }



    return n;
}


int main(){
    
    void itoa(int n, char s[]);
    int c;
    char s[100];
    const char *info = "Number of chars left in buffer: ";

    while((c = getchar()) != EOF){
        memset(s, 0, 100);
        itoa(stdin->cnt,s);
        write(STDOUT_FILENO, info, strlen(info));
        write(STDOUT_FILENO, s, 100);
        write(STDOUT_FILENO, "\n",1);
        //write(STDOUT_FILENO, &c, 1);
        //putchar(c);
    }
    
    //putchar(c);

    return 0;
}

void itoa(int n, char s[]){
    void reverse(char s[]);

    int i, sign;

    if((sign = n) < 0){
        n = -n;
    }

    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}


void reverse(char s[]){
     int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j;i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}