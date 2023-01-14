#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFERSIZE 100000
#define LINE_LENGTH 80

static char buffer[BUFFERSIZE]; 
static char *tail = buffer;

int main(int argc, char *argv[]){

    int rows;
    int max_rows = 10;
    //getline params
    char _line[LINE_LENGTH];
    char *line = _line;
    size_t len = LINE_LENGTH;

    // printf("%d\n",argc);
    if(argc == 3 ){
        if(strcmp("-n", argv[1]) == 0){
            char *p = argv[2];
            while(*p != '\0'){
                if(!isdigit(*p)){
                    goto error;
                }
                p++;
            }
            max_rows = atoi(argv[2]);
        }else{            
            goto error;
        }
    }

    
    for(rows = 0; getline(&line, &len,stdin) > 0; rows++){
        strcpy(tail, line);
        tail += strlen(line)+1;
    }
    rows--;

    char *head = buffer;
    for(; rows >= 0; rows--){
        if(rows < max_rows){
            printf("%s", head);        
        }
        
        while(*head++ != '\0');                
    }

    return 0;

error:
    printf("Usage: tail -n <number>\n");
    return -1;
}
