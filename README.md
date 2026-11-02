# infinadd

**Arbitrary-precision addition** in C: adds two integers of any length, limited only by
memory.

Each number is stored as a doubly linked list of digits; the addition walks both lists from
the least significant digit, carrying as it goes, exactly like on paper.

## Build and use

```sh
make
./infinadd 99999999999999999999999999999 1
# 100000000000000000000000000000
```

