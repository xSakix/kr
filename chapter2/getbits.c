#include <stdio.h>

#define MAX_N 32

unsigned table[MAX_N];

/*getbits: get n bits from position p*/
void init_table(void);
unsigned getbits(unsigned x, int p, int n);
void printbinary(unsigned x);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned _pow(unsigned base, int exp);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);


int main(){

    unsigned x = 65325;
    //unsigned x = 27;

    init_table();
    for(int i = 0; i < MAX_N; i++){
        printf("%u = %0b\n", table[i],table[i]);
    }

    printf("-------------------------------------------------------\n");
    for(int i = 0; i < 10; i++){
        printf("~1<<%d = \t%0b\n",i, (~1<<i));
        printf("~0<<%d = \t%0b\n",i, (~0<<i));
        printf("~(~0<<%d) = \t%0b\n",i, ~(~0<<i));
        printf("1<<%d = \t%0b\n",i, (1<<i));
        printf("0<<%d = \t%0b\n",i, (0<<i));
    }
    printf("-------------------------------------------------------\n");

    //%b for binary
    printf("x = \t\t\t%0b\n",x);

    printf("077: \t\t\t%0b\n", 077);
    printf("0177: \t\t\t%0b\n", 0177);
    printf("0777: \t\t\t%0b\n", 0777);
    printf("~077: \t\t\t%0b\n", ~077);
    printf("0177700: \t\t%0b\n", 0177700);
    printf("~0177700: \t\t%0b\n", ~0177700);


    printf("x & 077 = \t\t%0b\n", x & 077);
    printf("x & ~077 = \t\t%0b\n", x & ~077);
    printf("x & 0177700 = \t\t%0b\n", x & 0177700);
    printf("x & ~0177700 = \t\t%0b\n", x & ~0177700);
    printf("getbits(x, 4, 5)=\t%0b\n",getbits(x, 4, 5));
    printf("-------------------------------------------------------\n");
    printf("setbits(x, 4, 3, 127) = \t%0b\n",setbits(x, 4, 3, 127));
    printf("setbits(x, 7, 3, 127) = \t%0b\n",setbits(x, 7, 3, 127));
    printf("-------------------------------------------------------\n");
    printf("invert(x, 4, 3)=\t\t%0b\n",invert(x, 4, 3));
    printf("invert(x, 7,3)=\t\t\t%0b\n",invert(x, 7, 3));
    printf("-------------------------------------------------------\n");
    unsigned result = rightrot(x, 4);
    printf("rightrot(x, 4)=\t\t\t%0b=%u\n",result,result);
    
    return 0;
}

void init_table(void){
    printf("Initializing table...\n");
    unsigned r = 0;
    for(int i = 0; i < MAX_N;i++){
        r = r + _pow(2,i);
        table[i] = r;
    }

}


unsigned getbits(unsigned x, int p, int n){

    return (x >> (p + 1 - n)) & ~((~0) << n);
    //return (x >> (p + 1 - n)) & ~(1 << n);
}

void printbinary(unsigned x){
    if(x >> 1){
        printbinary(x >> 1);
    }

    putc((x & 1) ? '1':'0',stdout);
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    printf("--------setbits(%u,%d,%d,%u)-----------\n",x,p,n,y);
    printf("x = \t\t\t\t%0b\n",x);
    printf("y = \t\t\t\t%0b\n",y);
    unsigned ny = y & ~(~0 << n);
    printf("ny = \t\t\t\t%0b\n",ny);
    printf("ny = \t\t\t\t%0b\n",ny<<(p+1-n));
    return x | ny<<(p+1-n);
}

unsigned _pow(unsigned base, int exp){
    int i;
    int n = 1;
    
    for(i = 1; i <= exp; i++){
        n = n*base;
    }

    return n;
}

unsigned invert(unsigned x, int p, int n){
    printf("--------invert(%u,%d,%d)-----------\n",x,p,n);
    printf("x = \t\t\t\t%0b\n",x);
    
    printf("1 << n = %0b\n", 1 << n);
    printf("(1 << n)-1 = %0b\n", (1 << n)-1);
    printf("((1 << n)-1) << (p-n+1) = %0b\n", ((1 << n)-1) << (p-n+1));


    return x ^ (((1<< n)-1) << (p-n+1));
}

unsigned rightrot(unsigned x, int n){
    printf("--------rightrot(%u,%d)-----------\n",x,n);
    printf("x = \t\t\t\t%0b=%u\n",x,x);

    for(; n > 0; n--){
        x = (x >> 1) | ~(~0u >> (x&1));
    }
    return x;
}