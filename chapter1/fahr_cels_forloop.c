#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/*
Print Fahrenheit-celsius table for fahr = 0, 20, ..., 300
*/
main() {
  int fahr, celsius;

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    // for(fahr = 300;fahr >= 0;fahr-=20){
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}