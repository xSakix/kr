#include <stdio.h>

void printd(int n);

int main(){

    printd(1);
    putchar('\n');
    printd(12);
    putchar('\n');
    printd(123);
    putchar('\n');
    printd(1234);
    putchar('\n');
    printd(12345);
    putchar('\n');
    printd(-12345);
    putchar('\n');
    printd(-0);
    putchar('\n');
    printd(0);
    putchar('\n');

    return 0;
}

void printd(int n){
    if (n < 0){
        putchar('-');
        n = -n;
    }
    
    if(n / 10){
        printd(n / 10);
    }

    putchar(n % 10 + '0');
}