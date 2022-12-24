#include <stdio.h>

int main(){

    long nc;

    nc = 0;
    printf("SIZE OF long: %ld\n",sizeof(long));
    printf("SIZE OF int: %ld\n",sizeof(int));
    printf("SIZE OF short: %ld\n",sizeof(short));

    while(getchar() != EOF){
        ++nc;
    }

    printf("Number of characters read:%ld\n",nc);

    return 0;
}