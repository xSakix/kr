#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//it's illegal for a structure to contain an instance of itself
//but it's ok to contain a pointer!
struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(){

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word,MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }

    treeprint(root);

    return 0;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    struct tnode *talloc(void);
    char *_strdup(char*);
    //if not in the tree, create a new node for the word
    if(p == NULL){
        p = talloc();
        p->word = _strdup(w); //it's a pointer and we don't wan't to rewritte it. So duplicate.
        p->count = 1;
        p->left = p->right = NULL;
    }else if((cond = strcmp(w, p->word)) == 0){ //if it's in the tree incement count
        p->count++;
    }else if(cond < 0){ //navigate left if its less than current node
        p->left = addtree(p->left, w);
    }else{ // navigate right, if it's more than current node
        p->right = addtree(p->right, w);
    }

    return p;
}

struct tnode *talloc(){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *_strdup(char *s){
    char *p;

    p = (char *)malloc(strlen(s) + 1); //+1 for '\0'
    if(p != NULL){
        strcpy(p, s);
    }

    return p;
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