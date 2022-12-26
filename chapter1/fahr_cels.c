#include <stdio.h>

/*
Print Fahrenheit-celsius table for fahr = 0, 20, ..., 300
*/
main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        //this is by far the simplest solution
        celsius = 5 * (fahr - 32) / 9;
        //the following will be always zero, as celsius is int and 5/9 rounded is always 0
        //celsius = (5/9) * (fahr - 32);
        //if we change types to floats and after convert to int, it works
        //celsius = (int)((5.0 / 9.0) * ((float)fahr - 32.0));
        // printf("%d\t%d\n", fahr, celsius);
        //to justify numbers to the right
        //%Xd - X is number of digits
        printf("%3d %6d\n", fahr, celsius);
        fahr = fahr+step;
    }
}