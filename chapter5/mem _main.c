#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "mem.c"

#define ALLOCSIZE 100 //redefined

void fill(char*, char, int);


int main(){

    char *start = allocbuf;
    char *p1 = alloc(13);
    char *p2 = alloc(25);
    char *p3 = alloc(32);
    char *p4 = alloc(30);

    strcpy(p1,"Hello world!");
    strcpy(p2,"Hello world!Hello world!");
    fill(p3,'1',32);
    fill(p4,'2',30);

    printf("%s\n",p1);
    printf("%s\n",p2);
    printf("%s\n",p3);
    printf("%s\n",p4);

    //printf whole
    for(int i = 0; i < 100; i++){
        if(*start == '\0'){
            printf("0");
            start++;
        }else{
            printf("%c",*start++);
        }
    }
    putchar('\n');

    assert(allocp == allocbuf + ALLOCSIZE);


    _free(p4);
    _free(p3);
    _free(p2);
    _free(p1);

    assert(allocp == allocbuf);

    return 0;
}

void fill(char *s, char c, int n){
    for(int i = 0; i < n-1; i++){
        *s++ = c;
    }
    *s='\0';
}