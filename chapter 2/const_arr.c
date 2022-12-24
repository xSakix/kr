#include <stdio.h>


int main(){

    const char s[] = "Hello world!";
    char s2[] = "Hello world!";

    //this will not work because it's const
    //s[0] = 'h';
    //this will work because it's not const
    s2[0] = 'h';

    return 0;
}
