#include <stdio.h>

#define MAXLEN 1000

int _getline(char line[], int max);
int strindex(char source[], char searchfor[]);

int main(){

    char line[MAXLEN];
    int found = 0;
    
    while(_getline(line, MAXLEN) > 0){
        if(strindex(line, "ould") >= 0){
            printf("%s",line);
            found++;
        }
    }


    return found;
}

int _getline(char line[], int max){
    int c, i;

    i = 0;

    while(--max > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }

    if( c == '\n'){
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

int strindex(char source[], char searchfor[]){
    int i, j, k;

    for(i = 0; source[i] != '\0'; i++){
        for(j = i, k= 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++ );

        if(k > 0 && searchfor[k] == '\0'){
            return i;
        }        
    }

    return -1;
}
