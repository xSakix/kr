#include <stdio.h>

int main(){
    int i,j,k;
    char aname[][15] = {"One", "Two", "Three", "Four"};

    for(j = 0; j < 15;j++){
        printf("%d\t",j);
    }
    putchar('\n');

    for(i = 0; i < 4;i++){
        for(j = 0; j < 15;j++){
            if(aname[i][j] == '\0') 
                putchar('0');
            else
                putchar(aname[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }

    //pointer to multidimensional array
    //pointer to an array of 15 chars
    char (*anameptr)[15] = aname;
    printf("\n");
    for(i = 0; i < 4;i++){
        for(j = 0; j < 15;j++){
            if((*anameptr)[j] == '\0') 
                putchar('0');
            else
                putchar((*anameptr)[j]);
            putchar('\t');
        }
        putchar('\n');
        anameptr++;
    }

    printf("\n");

    //flatten array with a pointer. The offset is 15
    char *p = aname;
    //60 = 4x15
    for(j = 0; j < 60;j++){
        if(j < 10)
            printf("|%d |",j);
        else
            printf("|%d|",j);
    }
    putchar('\n');

    for(i = 0; i < 60;i++){
        putchar('|');
        char c = *p++;
        if(c == '\0') 
            putchar('0');
        else
            putchar(c);
        putchar(' ');
        putchar('|');

         
    }
    
    printf("\n");
}