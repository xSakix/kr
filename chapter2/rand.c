#include <stdio.h>
#include <time.h>

unsigned long int next = 1;

int rand(void);
void srand(unsigned int seed);

int main(){

    int i;
    time_t seconds;

    seconds = time(NULL);
    srand(seconds);
    
    for(i =0; i < 10; i++){
        printf("%d\n",rand());
    }

    return 0;
}

int rand(void){
    next = next * 1103515245+12345;
    return (unsigned int)(next/65536) % 32765;
}

void srand(unsigned int seed){
    next = seed;
}