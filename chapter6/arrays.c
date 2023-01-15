#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab/ sizeof keytab[0])

struct key{
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,    
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "_Packed", 0
};


int getword(char *, int);
int binsearch(char *, struct key *, int );

int main(){

    int n;
    char word[MAXWORD];
    // unsigned long len = sizeof(keytab)/sizeof(struct key);

    //struct key keytab[NKEYS];
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            if((n=binsearch(word, keytab, NKEYS)) >= 0){
                keytab[n].count++;
            }
        }
    }
    
    for(int i = 0; i < NKEYS; i++){
        printf("%s:%d\n",keytab[i].word, keytab[i].count);
    }



    return 0;
}

int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;

    low = 0;
    high = n -1;
    while(low <= high){
        mid = (low+high)/2;

        if((cond = strcmp(word, tab[mid].word)) < 0){
            high = mid - 1;
        }else if(cond > 0){
            low = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()));

    if (c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }

    *w = '\0';

    return word[0];
}



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