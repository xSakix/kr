/**
This is an implementation from K&R. The pointers and memory don't hold, because the program allocates blocks of 1024 B of mem from system. This means, 
if you allocate a string of size 21, you can actually set values until 1024...1025 will throw a segmentation fault.

This might be dangerous as you could overwrite memory in your progs...

Also the free doesn't deallocate the block you got from system. So even when you free a pointer you can continue to write into that memory using that pointer, 
as the underlying block is still valid.

So you can't have access to the underlying block memory via any pointer, and future implementation should consider this. 

This was one of the harder to understand exercises....

*/
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

#define NALLOC 1024

typedef long Align;

union header{
    struct{
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void printheader(Header *p, char *name);

void _free(void *ap){
    
    Header *bp, *p;

    bp = (Header *)ap-1; //point to block header

    //printheader(bp);

    for(p = freep; !(bp > p && bp < p->s.ptr);p=p->s.ptr){
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr)){ //freed block at the start or end
            break;
        }
    }

    if(bp + bp->s.size == p->s.ptr){ //join to upper nbr
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;   //join to lower nbr
    }

    if(p + p->s.size == bp){
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }

    //printheader(p);

    freep = p;
}


static Header *morecore(unsigned nu){
    void *cp;
    Header *up;

    if(nu < NALLOC){
        nu = NALLOC;
    }

    cp = sbrk(nu*sizeof(Header));

    if(cp == (void*)-1){
        return NULL;
    }

    up = (Header*)cp;
    up->s.size = nu;
    _free((void*)(up+1));

    return freep;
}



void *_malloc(unsigned nbytes){

    Header *p, *prevp;
    unsigned nunits;

    //this is a rounding to the size of Header
    nunits = (nbytes *sizeof(Header) - 1)/sizeof(Header)+1;
    printf("Requested size in bytes: %d\n",nbytes);
    printf("Size of Header:%ld\n",sizeof(Header));
    printf("nbytes*sizeof(Header) - 1 = %ld\n",nbytes *sizeof(Header) - 1);
    printf("nunits = %d\n",nunits);

    //init the free list
    if((prevp = freep) == NULL){
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
        printheader(&base, "BASE");
        //the base header points to the start of free space
        //freep (and prevp) point to the main-base block, from which we allocate free space
    }

    //the first run says, insert into p Base header, which contains info about free size
    for(p = prevp->s.ptr; ;prevp = p, p = p->s.ptr){
        //if the base has enoug size
        if(p->s.size >= nunits){
            printf("Requested size will fit into allocated block of memory...\n");
            //if its the same size as requested, just use this
            if(p->s.size == nunits){
                printf("Requested size equals current size...\n");
                prevp->s.ptr = p->s.ptr;
            } else {
                //if not we need to substract the requested size from currently available size
                //and move the pointer to the 'right' by the currently available size(minus requested size)...e.g. at the end of the free block
                //adjust size of new block to requested size...pointer at this moment points to the new block at the end
                //p->s.ptr will be nil, as it marks the end of the 'chain'
                printf("Requested size is lower than current size, adjusting current size and moving pointer to new free space...\n");
                printheader(p, "Previous pointer - points to head of block with the allocated size");
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;


            printheader(p, "new pointer");
            printheader(freep, "new freep");

            //we return +1, as the first 'slot' is taken by the block/slot header
            return (void *)(p+1);
        }
        //if the current base doesn't contain enough free space, go ahead and create another block from system memory
        if(p == freep){ //wrapped around free list
            printf("Requesting new block of memory from system...\n");
            if((p = morecore(nunits)) == NULL){
                return NULL; // none left
            }
        }
    }
}

void printheader(Header *p, char *name){
    printf("----Header(%p)-%s----\n",p,name);
    printf("\ts.ptr=%p\n", p->s.ptr);
    printf("\ts.size=%d\n",p->s.size);
    printf("\tAlign=%ld\n",p->x);
}

#include <string.h>

int main(){

    char *p[100];
    
    // for(int i = 0; i < 100;i++){
    //     p[i] = (char*)_malloc(80*sizeof(char));
    //     strcpy(p[i], "Hello world");
    //     if(i % 2 == 0){
    //         _free(p[i]);
    //         //printf("%p\n",p[i]);
    //         p[i] = NULL;
    //     }
    // }
    
    // //printf("%s\n",p);
    // for(int i = 0; i < 100;i++){
    //     if(p[i] != NULL)
    //         _free(p[i]);
    // }
    
    // printheader(&base, "BASE");
    // for(int i = 0; i < 5;i++){
    //     p[i] = (char*)_malloc(256*sizeof(char));
    //     strcpy(p[i], "Hello world");
    //     // printf("%s\n",p[i]);
    //     // printheader((Header*)p[i]-1);
    // }

    // printf("Base:");
    // printheader(&base);
    // printf("freep:");
    // printheader(freep);

    // printf("\n\n");
    // for(int i = 0; i < 5;i++){
    //     _free(p[i]);
    //     printheader((Header*)p[i]-1);
    // }

    // printf("\n\n");
    // Header *hptr = &base;
    // while(hptr->s.size > 0){
    //     printheader(hptr);
    //     hptr = hptr->s.ptr;
    // }
    printf("\n---INFO----\n");
    // _malloc(256*sizeof(int));
    // _malloc(256*sizeof(long));
    // _malloc(256*sizeof(double));
    // _malloc(256*sizeof(long double));
    char *s = _malloc(21*sizeof(char));


    // strcpy(s, "aaaaaaaaaabbbbbbbbbbc");
    // printf("%s\n",s);

    //it actually doesn't respect the size...which should be 21...or strcpy allocates new mem for this...
    // strcpy(s, "aaaaaaaaaabbbbbbbbbbccccccccccdd");
    // printf("%s\n",s);
    // //and it doesn't deallocate the memory actually. Only adjusts the headers/block list
    // _free(s);
    // printf("%s\n",s);
    //this will work, because the block is actually of size 1024
    for(int i = 0;i < 23;i++){
        s[i] = 'a'+i;
    }
    printf("%s\n",s);

    //so if we do the same, but move beyond the 1024 bytes allocated from system, we should drop
    for(int i = 0;i < 1025;i++){
        s[i] = 'a'+i;
    }
    printf("%s\n",s);

    // char *s2 = malloc(21*sizeof(char));
    // strcpy(s2, "aaaaaaaaaabbbbbbbbbbc");
    // printf("%s\n",s2);
    // strcpy(s2, "aaaaaaaaaabbbbbbbbbbccccccccccdd");
    // printf("%s\n",s2);


    return 0;
}
