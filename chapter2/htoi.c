/**
This is an ugly version. It's prob more optimal than using substrings, etc...but it looks ugly and has confusing logic.
*/
#include <stdio.h>
#include <string.h>


int htoi(char s[]);
int pow(int base, int exp);

int main(){

    printf("%d\n",htoi("0"));
    printf("%d\n",htoi("1"));
    printf("%d\n",htoi("a"));
    printf("%d\n",htoi("f"));
    printf("%d\n",htoi("A"));
    printf("%d\n",htoi("F"));
    printf("%d\n",htoi("01"));
    printf("%d\n",htoi("11"));
    printf("%d\n",htoi("aa"));
    printf("%d\n",htoi("ff"));
    printf("%d\n",htoi("AA"));
    printf("%d\n",htoi("FF"));
    printf("%d\n",htoi("111"));
    printf("%d\n",htoi("aaa"));
    printf("%d\n",htoi("fff"));


    printf("%d\n",htoi("0x0"));
    printf("%d\n",htoi("0x1"));
    printf("%d\n",htoi("0xa"));
    printf("%d\n",htoi("0xf"));
    printf("%d\n",htoi("0xA"));
    printf("%d\n",htoi("0xF"));
    printf("%d\n",htoi("0x01"));
    printf("%d\n",htoi("0x11"));
    printf("%d\n",htoi("0xaa"));
    printf("%d\n",htoi("0xff"));
    printf("%d\n",htoi("0xAA"));
    printf("%d\n",htoi("0xFF"));
    printf("%d\n",htoi("0x111"));
    printf("%d\n",htoi("0xaaa"));
    printf("%d\n",htoi("0xfff"));


    return 0;
}

int pow(int base, int exp){
    int i,n;

    i = 0;
    n = 1;

    for(i = 0; i < exp; ++i){
        n = n * 16;
    }

    return n;
}

int htoi(char s[]){
    int i;      //iterate
    int num;    //final computed value
    int len;    //len of string
    int offset; //if string starts with 0x or 0X, we offset the begining by 2
    int key;    //key into the array of chars which is the input. It is computed by using i and offset
    int exp;    //the exponent used in the pow(16,exp). Its computed based on iterator, offset and length
    
    len = strlen(s);
    num = 0;
    offset = 0;

    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
        offset = 2;
    }

    for(i = 0, key=i+offset, exp=len-offset-1; i < len-offset; ++i, key=i+offset, --exp){
        // printf("%c\n",s[n]);
        if(s[key] >= '0' && s[key] <= '9') 
            num = num+pow(16, exp) * (s[key] - '0');
        else if(s[key] >= 'a' && s[key] <= 'f'){
            num = num+pow(16,exp) * ((s[key] - 'a') + 10);
        } else if (s[key] >= 'A' && s[key] <= 'F'){
            num = num+pow(16,exp) * ((s[key] - 'A')+10);
        }else{
            return -1;
        }
    }

    return num;
}