#include <stdio.h>
#include <string.h>

int checkfile(FILE *fp, char *name);

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Usage: %s filename1 filename2\n",argv[0]);
        return 1;
    }

    FILE *first = fopen(argv[1],"r");
    FILE *second = fopen(argv[2],"r");
    if(!checkfile(first, argv[1]) || !checkfile(second, argv[2])){
        return 1;
    }

    char line1[100];
    char line2[100];
    int n = 0;
    while(fgets(line1, 100, first) != NULL && fgets(line2, 100, second) != NULL){
        // printf("file1:%s", line1);
        // printf("file2: %s", line2);
        if(strcmp(line1, line2) != 0){
            printf("%d:%s%s", n, line1, line2);
            break;
        }
        n++;
    }

    fclose(first), fclose(second);
}

int checkfile(FILE *fp, char *name){
    if(fp == NULL){
        printf("File '%s' not found!\n",name);
        return 0;
    }

    // printf("File '%s' opened for reading...\n",name);

    return 1;
}