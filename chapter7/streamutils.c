#include <stdio.h>


char *_fgets(char *s, int n,FILE *iop);
int _fputs(char *s, FILE *iop);
int _getline(char *, int);


int main(){

    char line[100];

    // while(_fgets(line, 100, stdin) != NULL){
    //     int error = _fputs(line, stdout);
    //     if(error)
    //         break;
    // } 
    // else {
    //     printf("User didn't enter any value...\n");
    // }

    while(_getline(line, 100) > 0){
        int error = _fputs(line, stdout);
        if(error)
            break;
    }

}

char *_fgets(char *s, int n,FILE *iop){

    register int c;
    register char *cs;

    cs = s;
    while(--n > 0 && (c = getc(iop)) != EOF){
        if((*cs++ = c) == '\n'){
            break;
        }

       
    }

    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

int _fputs(char *s, FILE *iop){
    register int c;
    while(c = *s++){ //last char will be '\0' which is 0, which is FALSE
        putc(c, iop);
    }

    return ferror(iop) ? EOF : 0; //ferror returns non-zero value for error, and fputs returns EOF in case of error
}

int _getline(char *line, int max){

    int _strlen(char *);

    if(_fgets(line, max, stdin) == NULL){
        return 0;
    }

    return _strlen(line);
}

int _strlen(char *s){
    int n = 0;
    
    while(*s++){
        n++;
    }

    return n;
}