#include <stdio.h>

int strend(char*,char*);

int main(){

    printf("%d\n",strend("Hello world!", "world!"));
    printf("%d\n",strend("Hello wo", "world!"));

    return 0;
}

// int strend(char *s, char *search){
//     char *start = search;

//     while(*s != '\0') 
//         s++;
//     while(*search != '\0')
//         search++;

//     while(*search == *s){
//         search--;
//         s--;
//     }
//     search++;

//     if(search == start)
//         return 1;
    
//     return 0;
// }

int strend(char *s, char *search){
    char *start = search;

    while(*s != '\0') 
        s++;
    while(*search != '\0')
        search++;

    for(;*search == *s; search--, s--){
        if(search == start)
            return 1;
    }

    return 0;
}