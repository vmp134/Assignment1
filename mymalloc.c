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
#define HEADERSIZE 8
#define ROUND(x) (((x)+7)&~7)
static union {
    char bytes[MEMLENGTH];
    double not_used;
} heap;
static int check = 0;

/*
Helper functions, including
*/

/*
mymalloc(), implemented by Victor Peng, vmp134
Note the pointer returned by mymalloc() must point to the payload, not the chunk header.
*/
void * mymalloc (size_t size, char *file, int line) {
    
    //Setup of initial variables and the heap
    void *ret;
    size_t neededBytes = HEADERSIZE + ROUND(size);
    if (check == 0) {
        check = 1;
        
    }

    

    return ret;
}

