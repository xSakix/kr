#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error: stack is full, can't push %g\n", f);
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double peek(void){
    if(sp > 0){
        return val[sp - 1];
    }else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

void dupe(void){
    push(peek());
}

void swap(void){
    if(sp > 1){
        double v1 = pop();
        double v2 = pop();
        push(v1);
        push(v2);
    }else{
        printf("Not enough elements in the stack!\n");
    }
}

void clear(void){
    while(sp > 0){
        pop();
    }
    
}