#include <stdio.h>

int lower(int c);

int main(){

    const char s[] = "Hello World!";
    int i;
    char c;
    unsigned char c2;
    
    printf("Original:\t%s\n",s);
    printf("Lower:\t\t");

    for(i = 0; (c = s[i]) != '\0'; ++i){
        printf("%c",lower(c));
    }
    printf("\n");

    //because char is an int
    //on some machines left most bit set to 1 is considered a negative sign
    //on some machines the compiler adds zeros from left as to not overflow/represent char as a negative int
    c = 127;
    printf("%d\n",c);
    c = 128;
    printf("%d\n",c);
    //character will always be 'positive'
    printf("%c\n",c);

    //for portability specify unsigned if you don't want negative integers in char
    c2 = 128;
    printf("%d\n",c2);
    printf("%c\n",c2);

    return 0;
}

//!!! will not work on EBCDIC encoding as it has different values for chars than ASCII
int lower(int c){

    if(c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A';
    }
    
    return c;    
}
