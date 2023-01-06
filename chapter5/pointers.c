#include <stdio.h>


int main(){

    int x = 1, y = 3, z[10];
    int *ip;


    for(int i = 0; i < 10; i++){
        z[i] = i;
    }

    //segmentation fault
    // printf("%p = %d \n",ip, *ip);

    ip = &x;
    printf("%p = %d \n",ip, *ip);

    y = *ip;
    printf("%p = %d \n",ip, *ip);
    printf("y = %d \n",y);

    *ip = 0;
    printf("%p = %d \n",ip, *ip);
    printf("x = %d \n",x);

    ip = &z[0];
    for(int i = 0; i < 10;i++){
        (*ip)++; // increment value at z[i]
        printf("%d,",*(ip++)); //print value at *ip = z[i], and move ip to next element in z[]
    }
    putchar('\n');

    return 0;
}