#include <stdio.h>

#define MAXLINE 100

int _getline(char s[]);

int main(){

    char line[MAXLINE];
    int len = 0;

    while((len = _getline(line)) > 0){
        printf("%s\n",line);
    }


    return 0;
}

int _getline(char s[]){

    int i,c;

    i = 0;
    //rewritten for(i = 0; i < MAXLINE -1 && (c = getchar()) != '\n' && c != EOF; ++i)
    while(i < MAXLINE-1){
        c = getchar();
        
        if(c == '\n'){
            break;
        }

        if(c == EOF){
            break;
        }
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    
    return i;
}