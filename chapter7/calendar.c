#include <stdio.h>
#include <stdlib.h>

int main(){

    int day, year, month;
    char monthname[20];

    // scanf("%d %s %d", &day, monthname, &year);

    // printf("date: %d %s %d \n",day, monthname, year);

    // scanf("%d/%d/%d",&month, &day, &year);

    // printf("date:%d.%d.%d\n",day, month, year);

    char buff[100];
    char *line = buff;
    size_t len = 100;

    while(getline(&line, &len, stdin) > 0){
        if(sscanf(line,"%d %s %d", &day, monthname, &year) == 3){
            printf("valid: %s",line);
        }else if(sscanf(line,"%d/%d/%d", &month, &day, &year) == 3){
            printf("valid: %s",line);
        }else{
            printf("invalid: %s",line);
        }
    }

    return 0;
}