#include <stdio.h>
#include "strcmp.c"

int main(){

    printf("%d\n", _strcmp("a", "b"));
    printf("%d\n", _strcmp("hello", "hello"));
    printf("%d\n", _strcmp("b", "a"));


    return 0;
}
