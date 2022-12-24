#include <stdio.h>


float fahr_to_celsius(float fahr);
float celsius_to_fahr(float celsius);

/*
Print Fahrenheit-celsius table for fahr = 0, 20, ..., 300
*/
int main()
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
        celsius = fahr_to_celsius(fahr);
        fahr_converted = celsius_to_fahr(celsius);
        printf("%3.0f %6.1f %6.0f\n", fahr, celsius,fahr_converted);
        fahr = fahr+step;
    }

    return 0;
}

float fahr_to_celsius(float fahr){
    return (5.0 / 9.0) * (fahr - 32.0);

}

float celsius_to_fahr(float celsius){
    return (9.0*celsius+160.0)/5.0;
}
