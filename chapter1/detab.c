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

void detab(char input[], char output[]){

    int i, j, k;

    i = 0, j = 0;

    while(input[i] != '\0'){
        if(input[i] == '\t'){
            for(k = 0;k < N_TAB; ++k){
                output[j++] = ' ';
            }              
        }else{
            output[j] = input[i];
            ++j;
        }
        ++i;
    }
}