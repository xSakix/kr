#include <stdio.h>

long power(int base, int exp);

int main(){

    unsigned char c; //default char is signed!
    int i;
    //char is 1 byte and should be in range 0 to 255
    printf("sizeof(unsigned char)=%ld bytes\n",sizeof(c));
    for(i = 0; i< 256; i++){
        c = i;
        printf("%d:%c | ",c,c);
    }
    printf("\noverflow: %d:%c",i,i);
    printf("\n");
    printf("----------------------------------\n");

    signed char c2;
    printf("sizeof(signed char)=%ld bytes\n",sizeof(c2));
    //signed char is 1 byte and should be in range -128 to 127
    for(i = -128; i< 128; i++){
        c2 = i;
        printf("%d:%c | ",c2,c2);
    }
    printf("\noverflow: %d:%c",i,i);
    printf("\n");
    printf("----------------------------------\n");


    char c3;
    printf("sizeof(char)=%ld bytes\n",sizeof(c3));
    //char is 1 byte and should be in range -128 to 127
    for(i = -128; i< 128; i++){
        c3 = i;
        printf("%d:%c | ",c3,c3);
    }
    printf("\noverflow: %d:%c",i,i);
    printf("\n");
    printf("----------------------------------\n");


    int signed_int; //default is signed
    int int_size = power(2,sizeof(signed_int)*8 -1);
    printf("sizeof(int)=%ld bytes which is equal to %d bits\n",sizeof(signed_int),(int)sizeof(signed_int)*8);
    printf("range is from %d to %d\n",-int_size, int_size -1);

    signed_int = int_size - 1;
    printf("max size %d\n",signed_int);
    signed_int = signed_int + 1;
    printf("overflow and min size %d\n",signed_int);

    printf("----------------------------------\n");

    unsigned int unsigned_int;
    long u_int_size = power(2,sizeof(unsigned_int)*8);
    printf("sizeof(unsigned int)=%ld bytes which is equal to %d bits\n",sizeof(signed_int),(int)sizeof(signed_int)*8);
    printf("range is from %1d to %ld\n",0, u_int_size-1);
    unsigned_int = -1;
    //printf format is different for unsingned ints...it is %u...if you use %d it will consider it as a signed int!!!
    printf("max size %u\n",unsigned_int);
    unsigned_int = unsigned_int + 1;
    printf("overflow and min size %u\n",unsigned_int);

    printf("----------------------------------\n");

    return 0;
}

long power(int base, int exp){
    long result = 1;
    while(exp > 0){
        result = result * base;
        --exp;
    }

    return result;
}


