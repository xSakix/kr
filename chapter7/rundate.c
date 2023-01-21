#include <stdio.h>
#include <string.h>


int main(){

    system("date > tmp.txt");
    //its not caught in stdin, because main is halted, system is run and after is main resumed
    char line[100];
    char result[200];
    
    FILE *fp = fopen("tmp.txt","r");
    
    if(fp == NULL){
        printf("File not found...\n");
        return 1;
    }

    fgets(line, 100, fp);
    strcpy(result, "The current date is:");
    strcat(result, line);

    printf("%s",result);
    
    fclose(fp);
}