#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct nlist{
    struct nlist *next;
    char *name;//name
    char *defn;//replacement for name
};

#define HASHSIZE 101
#define MAXWORD 100

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char*, char*);

int main(){    
    char word[MAXWORD];
    int getword(char *word, int lim);
    int i;
    int hashchar = 0;
    int define = 0;

    char *name = NULL;
    char *replacement = NULL;    

    //if was #define, than next word is name and the next one is defn
    while(getword(word,MAXWORD) != EOF){
        // printf("<start>%s<end>\n",word);
        if(word[0] == '#'){
            hashchar = 1;
        }else if(hashchar){
            if(strcmp(word, "define") == 0){
                define = 1;
                continue;
            }else{
                hashchar = 0;
            }
        }
        
        if(define && name == NULL){
            name = strdup(word);
        }else if(define && replacement == NULL){
            replacement = strdup(word);            
        }
        
        if(name != NULL && replacement != NULL){
            // printf("Adding %s, %s\n", name, replacement);
            install(name, replacement);
            name = NULL;
            replacement = NULL;
            
            hashchar = define = 0;
        }
    }

    for(int i = 0; i < HASHSIZE; i++){
        printf("%4d:", i);
        for(struct nlist *p = hashtab[i]; p != NULL; p = p->next){
            printf("%s->%s | ",p->name, p->defn);
        }
        printf("\n");
    }

    return 0;
}

unsigned hash(char *s){
    unsigned hashval;
    
    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31*hashval;
    }

    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;

    //table contains a linked list. For given key we compute hash. Than if found, the linked list is returned and we look for the value in the list.
    for(np = hashtab[hash(s)]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0){
            return np;
        }
    }

    return NULL;
}

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){ //not found
        np = (struct nlist *)malloc(sizeof(struct nlist));
        
        if(np == NULL || (np->name = strdup(name)) == NULL){ //out of mem
            return NULL;
        }

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else{
        free((void *)np->defn);
    }

    if((np -> defn = strdup(defn)) == NULL){
        return NULL;
    }

    return np;
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