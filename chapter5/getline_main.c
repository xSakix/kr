#include <stdio.h>
#include "getline.h"
#include "getline.c"


int main(){

    char s[100];
    int n = _getline(s);

    printf("length=%d\n",n);
    printf("%s\n", s);

    return 0;
}

