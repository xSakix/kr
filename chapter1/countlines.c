#include <stdio.h>

int main(){

    int c, nl, nb, nt,continousBlanks ;

    nl = nt = nb = continousBlanks = 0;
    while((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
            continousBlanks = 0;
        }else if(c == '\t'){
            ++nt;
            c = '\\';
            putchar(c);
            c = 't';
        }else if(c == '\b'){

            c = '\\';
            putchar(c);
            c ='b';
        }else if(c ==' '){
            ++nb;
            ++continousBlanks;
        }

        if(continousBlanks > 0 && continousBlanks % 2 == 0){
            --continousBlanks;
        }else{
            if(c != ' ' && continousBlanks > 0){
                --continousBlanks;
            }
            putchar(c);            
        }

    }

    printf("Number of blanks:%d\n",nb);
    printf("Number of tabs:%d\n",nt);
    printf("Number of lines:%d\n",nl);

    return 0;
}