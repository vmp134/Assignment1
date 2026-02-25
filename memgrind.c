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

void test4(void) {

}

void test5(void) {

}

int main (int argc, char **argv) {

    struct timeval tv;
    suseconds_t start = tv.tv_usec;

    for (int i = 0; i < 50; i++) {
        //Test 1: Allocate + Free 1-byte object 120 times
        test1();

        //Test 2: Allocate 120 1-byte objects then Free
        test2();

        //Test 3: Randomly Allocate and Free objects, with 120 total Allocates
        test3();
        
        //Test 4:
        test4();

        //Test 5:
        test5();
    }

    suseconds_t end = tv.tv_usec;
    suseconds_t meanTime = (end - start)/50;
    printf("%ld microseconds taken on average for 50 workloads", meanTime);
    return EXIT_SUCCESS;
}