#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 100

int strlen(char s[]);
int htoi(char s[]);
int _htoi(char s[]);
int pow(int base, int exp);
int starts_with(char orig[], char start[]);
int substring(char orig[], char dest[], int start);

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

int strlen(char s[]){

    int n = 0;

    while(s[n] != '\0'){
        ++n;
    }

    return n;
}

int starts_with(char orig[], char start[]){
    int len1, len2, i;
    
    len1 = strlen(orig);
    len2 = strlen(start);

    if(len1 < len2){
        return false;
    }

    for(i = 0; i < len2; ++i){
        if(orig[i] != start[i]){
            return false;
        }
    }

    return true;
}

int substring(char orig[], char dest[], int start){
    int len1, len2, i, j;
    
    len1 = strlen(orig);
    if(start >= len1){
        return -1;
    }

    // for(i = 0, len2 = 0; i < len1; ++i){
    //     if(i < start){
    //         continue;
    //     }
    //     dest[i-start] = orig[i];
    //     ++len2;
    // }

    // for(i = j = 0, len2 = 0; i < len1; i++){
    //     if(i >= start){
    //         dest[j++] = orig[i];
    //         ++len2;
    //     }
    // }

    for(i = j = 0, len2 = 0; i < len1; i++){
        if(i < start){
            continue;
        }
        dest[j++] = orig[i];
        ++len2;
    }

    return len2;
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
    char sub[MAXSIZE];
    

    if(starts_with(s, "0x") || starts_with(s, "0X")){
        int l = substring(s, sub, 2);
        if(l < 0){
            return -1;
        }
        return _htoi(sub);
    }

    return _htoi(s);
}

/**
precondition: s doesn't start with 0x or 0X, and contains valid hexa digits to be converted
*/
int _htoi(char s[]){
    int i;      //iterate
    int num;    //final computed value
    int len;    //len of string
    
    len = strlen(s);
    num = 0;


    for(i = len-1; i >= 0; --i){
        if(s[i] >= '0' && s[i] <= '9') 
            num = num+pow(16, i) * (s[i] - '0');
        else if(s[i] >= 'a' && s[i] <= 'f'){
            num = num+pow(16,i) * ((s[i] - 'a') + 10);
        } else if (s[i] >= 'A' && s[i] <= 'F'){
            num = num+pow(16,i) * ((s[i] - 'A')+10);
        }else{
            return -1;
        }
    }

    return num;
}