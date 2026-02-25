0. Team Members
Samuel Habib (smh389), Victor Peng (vmp134)

1. Test Plan


2. Test Programs


3. Further Design Notes
    mymalloc
        - During allocation, if a split were to yield an 8-byte chunk (which would only fit a header), myalloc would give those 8 bytes to the allocated space and skip splitting.
    myfree