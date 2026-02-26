0. Team Members
Samuel Habib (smh389), Victor Peng (vmp134)

1. Test Plan
    We plan to utilize our tests in memtest.c for correctness testing and memgrind.c for stress testing. 
    We have followed the guidelines in p1.pdf to the best of our ability, and added additional tests to further scrutinize our implementation of mymalloc and myfree. 
    Descriptions of these tests and the item(s) being tested can be seen below.

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
            Test 4: Allocate 120 1-byte objects then Free odds then evens. This puts pressure on coalesce, putting it as the focus of this stress test.
            Test 5: Allocate 16-byte objects (24 bytes total) spanning MEMLENGTH, then iterate and randomly Free, then Free remaining. This simulates the allocation of a linked list through all available memory, with random removals of nodes. We scrutinize our programs' ability to maintain fractured memory allocations and coalesce.

3. Further Design Notes
    mymalloc
        - mymalloc uses an 8-byte header that contains the length of the current chunk. The header uses the 2^0 bit to signify free (0) or allocated (1). This also means that the minimum length for a memory block is 16 bytes.
        - During allocation, if a split were to yield an 8-byte chunk leftover, myalloc would give those 8 bytes to the allocated space and skip splitting. This is because a valid memory block needs to be at least 16 bytes.
        - 
    myfree