#include <stdio.h>

#define MAXLINE 100
#define N_TAB 7

void empty(char arr[]);
int readline(char input[]);
void copy(char input[], char output[]);
void detab(char input[], char output[]);

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

void empty(char arr[]){
    int i;
    for(i = 0; i < MAXLINE; ++i)
        arr[i] = 0;
}

int readline(char input[]){

    int i, c;
    
    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        input[i] = c;
    }

    if(c == '\n'){
        input[i] = c;
        ++i;
    }

    input[i] = '\0';

    //'\0' is not counted to length. Based on length it's invisible and it will be always the last element of valid string array
    return i;
}

void copy(char input[], char output[]){

    int i;

    for(i = 0; (output[i] = input[i]) != '\0'; ++i);

}

void detab(char src[], char dest[]){

  int i, j, k, count_chars;

    i = 0, j = 0, count_chars = 0;

    while(src[i] != '\0'){
        if(src[i] == '\t'){
            int fill = N_TAB-(count_chars % N_TAB);
            for(k = 0;k < fill; ++k){
                dest[j++] = ' ';
                count_chars++;
            }              
        }else{
            dest[j] = src[i];
            ++j;
            count_chars++;
        }
        ++i;
    }
}