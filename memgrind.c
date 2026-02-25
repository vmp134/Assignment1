#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "mymalloc.h"

#define MEMLENGTH 4096
#define HEADERLENGTH 8

void test1(void) {
    for (int i = 0; i < 120; i++) {
        char *p = malloc(1);
        free(p);
    }
}

void test2(void) {
    char *pArr[120];
    for (int i = 0; i < 120; i++) {
        pArr[i] = malloc(1);
    }
    for (int i = 0; i < 120; i++) {
        free(pArr[i]);
    }
}

void test3(void) {
    
}


/* NOTES:
NEED TO IMPLEMENT TIMEOFDAY, AND THEN RUN TEST 50 TIMES, THEN GET MEAN TEST TIME IN MAIN
*/
int main (int argc, char **argv) {

    //Test 1: Allocate + Free 1-byte object 120 times


    //Test 2: Allocate 120 1-byte objects then Free


    //Test 3: Randomly Allocate and Free objects, with 120 total Allocates

    
    //Test 4:


    //Test 5:



    return EXIT_SUCCESS;
}