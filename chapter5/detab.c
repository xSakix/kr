#include <stdio.h>

#define MAXLINE 100
#define N_TAB 8

void empty(char*);
int readline(char*);
void copy(char*, char*);
void detab(char*, char*);

int main(){
    char input[MAXLINE];
    char output[MAXLINE];
    int len;

    while((len = readline(input)) > 0){
        empty(output);
        detab(input, output);
        printf("%s",output);
    }

    return 0;
}

void empty(char *arr){
    int i;
    for(i = 0; i < MAXLINE; ++i)
        arr[i] = 0;
}

int readline(char *input){

    int i, c;
    
    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        *input++ = c;
    }

    if(c == '\n'){
        *input++ = c;
    }

    *input = '\0';

    //'\0' is not counted to length. Based on length it's invisible and it will be always the last element of valid string array
    return i;
}

void copy(char *src, char *dst){

    while(*dst++ = *src++);
}

//tab = 8 chars
//so if i write 2 chars and press tab, it moves me only 6chars
//example
//tttttttt
//abtttttt
//ab cdttt
//so if i want to exchange tab for space, i need to count the chars and add count % 8 to string
void detab(char *src, char *dest){

    int i, j, k, count_chars;

    i = 0, j = 0, count_chars = 0;

    while(*src != '\0'){
        if(*src == '\t'){
            int fill = N_TAB-(count_chars % N_TAB);
            for(k = 0;k < fill; k++){
                *dest++ = ' ';
                count_chars++;
            }              
        }else{
            *dest++ = *src;
            count_chars++;
        }
        src++;
    }
    
}