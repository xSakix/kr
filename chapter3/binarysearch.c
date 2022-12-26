#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define IMAX_BITS(m) ((m)/((m)%255+1) / 255%255*8 + 7-86/((m)%255+12))
#define RAND_MAX_WIDTH IMAX_BITS(RAND_MAX)
_Static_assert((RAND_MAX & (RAND_MAX + 1u)) == 0, "RAND_MAX not a Mersenne number");

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )
#define MAXSIZE 1000000000L
// #define MAXSIZE 100L

unsigned long binarysearch(unsigned long x, const unsigned long v[], unsigned long n);
void shellsort(unsigned long v[], unsigned long l, unsigned long r);
unsigned long rand64(void);

int main(){

    unsigned long i, found, search_val;
    static unsigned long v[MAXSIZE];
    time_t seconds, start, stop;
    struct timespec m_stop, m_start;

    seconds = time(NULL);
    printf("seed = %ld\n",seconds);
    srand(seconds);

    printf("Creating array...\n");
    for(i = 0; i < MAXSIZE ; i++){
        v[i] = rand64();
    }

    start = time(NULL);
    printf("Starting to sort...\n");
    shellsort(v,0L, MAXSIZE - 1);
    printf("Sorted ...\n");
    stop = time(NULL);
    printf("Sort of %ld elements took %ld s. Min is %ld and max is %ld. \n", MAXSIZE, stop-start, v[0], v[MAXSIZE-1]);
    
    // for(i = 0; i< 10; i++){
    //     printf("%ld, ",v[i]);
    // }
    // printf("\n");

    search_val = v[rand() % ARR_SIZE(v)];
    clock_gettime(CLOCK_MONOTONIC_RAW, &m_start);
    found = binarysearch(search_val, v, MAXSIZE);
    clock_gettime(CLOCK_MONOTONIC_RAW, &m_stop);
    unsigned long delta_us = (m_stop.tv_sec - m_start.tv_sec) * 1000000 + (m_stop.tv_nsec - m_start.tv_nsec) / 1000;

    printf("Search took %ld ms. Found %ld at v[%ld] = %ld\n",delta_us,search_val,found,v[found]);

    return 0;
}

unsigned long rand64(void) {
  unsigned long r = 0;
  for (int i = 0; i < 32; i += RAND_MAX_WIDTH) {
    r <<= RAND_MAX_WIDTH;
    r ^= (unsigned) rand();
  }
  return r;
}


//input is search value 'x', sorted array 'v' and length 'n' of v
unsigned long binarysearch(unsigned long x, const unsigned long v[], unsigned long n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low+high)/2;
        if(x < v[mid]){
            high = mid - 1;
        }else if(x > v[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }

    return -1L;
}

void shellsort(unsigned long v[], unsigned long l, unsigned long r){
    unsigned long i, j, h, item;
    // printf("%ld, %ld \n", l, r);
    //init h    
    for(h = 1; h <= (r-l)/9; h = 3*h + 1);
    // printf("h = %ld\n",h);
    //sort
    for(; h > 0; h /= 3){
        for(i = l+h; i <= r; i++){
            j = i;
            item = v[i];
            while(j >= l+h && item < v[j-h]){
                v[j] = v[j-h];
                j -= h;
            }
            v[j] = item;
        }
    }
    
}
