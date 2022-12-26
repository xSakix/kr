#include <stdio.h>

/*
Print Fahrenheit-celsius table for fahr = 0, 20, ..., 300
*/
main()
{
    float fahr, celsius, fahr_converted;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("FAHR  CELSIUS   FAHR\n");
    printf("--------------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        fahr_converted = (9.0*celsius+160.0)/5.0;
        printf("%3.0f %6.1f %6.0f\n", fahr, celsius,fahr_converted);
        fahr = fahr+step;
    }
}