#include <stdio.h>

void reverse(char*);
void _strcpy(char*,char*);

int main(){
    char buff[100];
    _strcpy("Hello world!", buff);
    char *s = buff;

    reverse(s);
    printf("%s\n",s);

    return 0;
}


void _strcpy(char *s, char *t){
    while(*t++ = *s++);
}

//head points to the beginning of string
void reverse(char *head){

    //if string is empty = '\0', return immediately
    if(!head)
        return;

    char *tail = head;

    //move tail to the end of string
    while(*tail) tail++;
    //move on one before the '\0'
    --tail;

    for(; head < tail; head++, tail--){
        char tmp = *head;
        *head = *tail;
        *tail = tmp;
    }
}