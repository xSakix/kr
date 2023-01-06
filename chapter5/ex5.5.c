#include <stdio.h>
#include <string.h>

void _strncpy(char *,char *, int);
void _strncat(char *, char *, int);
int _strncmp(const char *, const char *, int);


int main(){

    char s2[100];

    _strncpy("Hello world", s2, 5);
    printf("%s\n",s2);
    
    _strncpy("Hello world", s2, 7);
    printf("%s\n",s2);

    _strncpy("Hello world", s2, 14);
    printf("%s\n",s2);
    
    _strncat(s2," what is happening?",4 );
    printf("%s\n",s2);

    _strncat(s2," is happening?",4 );
    printf("%s\n",s2);

    _strncat(s2,"appening?",10 );
    printf("%s\n",s2);

    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 1));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 2));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 3));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 4));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 5));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 6));
    printf("%d\n", _strncmp("Hello world", "Hello, how are you", 7));

    return 0;
}

//copy n chars from source to target
void _strncpy(char *s,char *t, int n){
    while((*t++ = *s++) != '\0' && n-- > 0);
}

//copy n chars from s2 to the end of s1;
void _strncat(char *s1, char *s2, int n){
    while(*s1 != '\0'){
        s1++;
    }
    while((*s1++ = *s2++) != '\0' && n-- >0);
}

int _strncmp(const char *s1, const char *s2, int n){

    for(;n > 0 && *s1 == *s2;n--,s1++,s2++);
    
    if(n == 0)
        return 0;

    return *s1 - *s2;
}
