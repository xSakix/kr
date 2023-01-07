static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month,int day);
void month_day(int year, int yearday, int *pmonth, int *pda);
char *month_name(int month);

int is_leap_year(int year){
   return year % 4 ==0 && year % 100 != 0 || year % 400 == 0;
}

// int day_of_year(int year, int month,int day){

//     int leap = is_leap_year(year);

//     //if its a leap year, leap = 1, otherwise leap = 0 
//     for(int i = 1; i < month;i++){
//         day += daytab[leap][i];
//     }

//     return day;
// }

//pointer version
int day_of_year(int year, int month,int day){

    int leap = is_leap_year(year);
    char *start = &daytab[leap][1];    
    //if its a leap year, leap = 1, otherwise leap = 0 
    while(--month > 0){
        day += *start++;
    }

    return day;
}


// void month_day(int year, int yearday, int *pmonth, int *pda){
//     int i;
//     int leap= is_leap_year(year);

//     for(i = 1; yearday > daytab[leap][i]; i++){
//         yearday -= daytab[leap][i];
//     }

//     *pmonth = i;
//     *pda = yearday;
// }

//pointer version
void month_day(int year, int yearday, int *pmonth, int *pda){
    int i;
    int leap= is_leap_year(year);
    char *p = &daytab[leap][1];    
    
    while(yearday > *p){
        yearday -= *p;
        p++;
    }

    *pmonth = p - daytab[leap];
    *pda = yearday;
}


char *month_name(int month){
    static char *name[] = {
        "Illegal month",
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    return (month < 1 || month > 12) ? name[0] : name[month];
}