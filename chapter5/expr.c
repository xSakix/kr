#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXNUMS 1000

static int stack[MAXNUMS];
static int *stackp = stack;
static int *head = stack;

int isnumber(char *s);
int isop(char op);


void push(int num);
int pop(void);

int op(int a, int b, char op);


int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Usage: exp num1 num2 .. numn op1 op2 ... opm\n");
        return -1;
    }

    
    for(int i = 1; i < argc; i++){
        char *in = argv[i];
        // printf("%s\n",in);
        if(isnumber(in)){
            int num = atoi(in);            
            push(num);
        }else if(isop(*in)){
            //if we need some sequence of values, we need to do 'pop' explictly like this
            int a = pop();
            int b = pop();
            //if we would do op(pop(),pop(),*in) the execution would do pop in reverse order b= pop, a = pop
            int num = op(a,b,*in);
            //printf("%d\n", num);
            push(num);
        }else{
            return -1;
        }
    }

    // while(stackp != stack){
    //     printf("result: %d\n",pop());
    // }
    int result = pop();
    printf("%d\n", result);

    return result;
}

int isnumber(char *s){
    
    if(*s == '-')
        s++;

    while(*s != '\0'){
        if(!isdigit(*s)){
            return 0;
        }
        s++;
    }


    return 1;
}

int isop(char op){
    char operators[] = {'+','-','*','/'};
    
    for(int i = 0; i < 4; i++){
        if(operators[i] == op)
            return 1;
    }

    return 0;
}

void push(int num){
    // printf("push: %p = %d\n", stackp, num);
    head = stackp;
    *stackp++ = num;
}

int pop(void){    
    // printf("pop: %p = %d\n", head, *head);
    stackp--;
    return *head--;
}

int op(int a, int b, char op){
    // printf("Computing %d %c %d\n", a, op, b);
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }

    return -1;
}