#include <stdio.h>
#include "days.c"

void print_date_info(int year, int day);

int main(){

    print_date_info(1988, 60);
    print_date_info(2023, 60);
    print_date_info(2023, 180);
    print_date_info(2022, 60);
    print_date_info(2020, 60);

    // char *start = daytab[0];
    // for(int i = 0; i < 13;i++)
    //     printf("%d\n",*start++);

    return 0;
}

void print_date_info(int year, int day){
    int m, d, _day;

    month_day(year,day, &m, &d);
    printf("%d-%s-%d",year,month_name(m),d);
    _day = day_of_year(year,m,d);
    printf(" is the %dth day in given year\n",_day);
}