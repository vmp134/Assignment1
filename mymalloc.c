#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
Preprocessor items, such as
    - Size of heap we're working with
    - Size of header we're working with
    - Rounding up size for 8-byte alignment
    - The global array, as per fig. 2 of p1.pdf
    - Check to see if heap has been created
*/
#define MEMLENGTH 4096
#define HEADERLENGTH 8
#define ROUND(x) (((x)+7)&~7)

static union {
    char bytes[MEMLENGTH];
    double not_used;
} heap;

static int check = 0;

/*
Helper functions, including
    - initialize() - initialize the heap, currently has no action if already initialized
    - detect() - runs at exit, detects leaks
*/
void initialize () {
    if (!check) {
        check = 1;
        heap.bytes[0] = (size_t)MEMLENGTH;
    }
}

/*
mymalloc(), implemented by Victor Peng, vmp134
Note the pointer returned by mymalloc() must point to the payload, not the chunk header.
*/
void * mymalloc (size_t size, char *file, int line) {
    
    //Setup of initial variables and the heap
    void *ret;
    size_t neededBytes = HEADERLENGTH + ROUND(size);
    initialize();

    //Loop to check for free/unallocated memory
    //Since everything will be 8-byte aligned, the 3 LSBs are unused. 
    //We will therefore use the first LSB (representing 2^0) to represent free (0) or allocated (1).
    int i = 0;
    while (i < MEMLENGTH) {
        if ((size_t)heap.bytes[i] & 1) {
            i += ((size_t)heap.bytes[i] - 1);
        }
        else if (0) {

        }
        else {

        }
    }
    
    return ret;
}

