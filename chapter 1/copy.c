#include <stdio.h>

int main(){

    int c;
    
    //printf("%d\n",(c=getchar()!=EOF)); 1 when not EOF, 0 when EOF
    
    while((c=getchar()) != EOF){
        putchar(c);
    }

    //printf("EOF:%d\n",EOF); = -1

    return 0;
}