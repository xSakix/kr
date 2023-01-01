#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

//if we define sp as static in stack.c, it will not work anymore
//as static keeps it local to the file
//extern int sp;

int main(){

    // test
    // push(0.01);
    // printf("%g",pop());


    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        // printf("sp=%d\n", sp);
        //printf("%d\n", type);
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;                
            case '-':
                push(pop() - pop());
                break;
            case '/':
                push(pop() / pop());
                break;
            case '%':
                push((int)pop() % (int)pop());
                break;
            case '\n':
                printf("result is %.8g\n",pop());
                break;
            case 'p':
                printf("top is %.8g\n",peek());
                break;
            case 'd':
                dupe();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case 'i':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'o':
                push(pow(pop(),pop()));
                break;
            case '\0':
                //empty
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }

    return 0;
}

