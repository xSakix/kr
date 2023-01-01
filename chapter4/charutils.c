#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void){
    //if an ungetch occured, read from buffer the stored char
    //otherwise read from input stream
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}