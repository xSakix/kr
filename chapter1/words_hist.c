#include <stdio.h>

#define IN 1 //inside word
#define OUT 0 //outside word

int main(){

    int c, i, j, nl, nw, nc, state, wl;
    int word_hist[10];

    for(int i = 0; i < 10; ++i){
        word_hist[i]=0;
    }

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        ++nc;
        if(c == '\n'){
            ++nl;
        }
        if(c != ' ' && c != '\n' && c != '\t'){
            wl++;
        }else{
            if(wl > 0 && wl <= 10){
                ++word_hist[wl-1];                
            }
            wl = 0;
        }

        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;            
        }else if(state == OUT){
            state = IN;
            ++nw;
        }        

    }

    //verticaly
    // printf("Histogram of word lengths(max 10):\n");
    // for(i = 0; i < 10;i++){
    //     printf("%d ", i);
    //     for(j = 0;j < word_hist[i]; ++j){
    //         printf("o");
    //     }
    //     printf("\n");
    // }

    //horizontally
    printf("Histogram of word lengths(max 10):\n");

    for(i = 0; i < 10 ; ++i){
        printf("%d\t",i+1);

        for(j = 0; j < word_hist[i]; ++j){
            if(j == 0){
                printf("\t");
            }else{
                printf(" ");
            }
            printf("o");
        }

        printf("\n");
    }

    return 0;
}