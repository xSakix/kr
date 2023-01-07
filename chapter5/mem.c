#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int);
void _free(char*);

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else{
        return 0;
    }
}

void _free(char *p){
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
        allocp = p;
    }
}

