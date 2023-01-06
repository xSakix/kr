#include <stdio.h>

#define STACKSIZE 10

static char stack[STACKSIZE];
static char *top = NULL;

void push(char);
char pop(void);
char peek(void);

int main(){

    char c;

    while((c = getchar()) != EOF && c != '\n' && top - stack < STACKSIZE){
        push(c);
    }

    printf("last item at %p\n",top);
    printf("peek:%d\n", peek());

    printf("stack size = %d\n",(int)(top - stack));

    while(top - stack){
        printf("%c(%d)", peek(),peek());
        pop();
    }
    putchar('\n');


    return 0;
}

void push(char c){
    if(top == NULL){
        top = stack;
    }

    if(top < stack + STACKSIZE){
        printf("pushing(%p):%d = %c\n",top, c, c);
        *top++ = c;
    }else{
        printf("pushing(%p):%d = %c\n",top, c, c);
        printf("Stack is full!\n");
    }
}

char pop(void){
    if(top == NULL){
        printf("Stack is empty!\n");
        return '\0';
    }
    while(top >= stack+STACKSIZE){
        top--;
    }

    return *--top;
}

char peek(void){

    // printf("top: %p\n", top);
    // printf("top: %p\n", &stack[STACKSIZE-1]);
    while(top >= stack+STACKSIZE){
        top--;
    }

    return *top;
}
