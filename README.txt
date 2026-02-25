0. Team Members
Samuel Habib (smh389), Victor Peng (vmp134)

1. Test Plan


2. Test Programs
    memtest.c
        -
    memgrind.c 
        - No arguments.
        - Runs through the 3 standard tasks and 2 other implemented tasks 50 times, returns the microseconds taken on average for 50 workloads (all 5 tasks).
        - Tasks are as follows:
            Test 1: Allocate + Free 1-byte object 120 times
            Test 2: Allocate 120 1-byte objects then Free
            Test 3: Randomly Allocate and Free objects, with 120 total Allocates
            Test 4: Allocate 120 1-byte objects then Free odds then evens (Coalesce)
            Test 5: Allocate 16-byte objects (24 bytes total) spanning MEMLENGTH, then iterate and randomly Free, then Free remaining

3. Further Design Notes
    mymalloc
        - During allocation, if a split were to yield an 8-byte chunk (which would only fit a header), myalloc would give those 8 bytes to the allocated space and skip splitting.
    myfree