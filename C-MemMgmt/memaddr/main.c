#include <stdio.h>

#include "munit.h"
#include "snek.h"
#include "snek.c"

munit_case(RUN, size_of_addr_16, {
    unsigned long size = size_of_addr(16);
    munit_assert_ulong(size, ==, 8, "size should be 8 on a 64-bit system");
});

munit_case(RUN, size_of_addr_32, {
    unsigned long size = size_of_addr(32);
    munit_assert_ulong(size, ==, 8, "size should be 8 on a 64-bit system");
});

munit_case(RUN, size_of_addr_64, {
    unsigned long size = size_of_addr(64);
    munit_assert_ulong(size, ==, 8, "size should be 8 on a 64-bit system");
});

munit_case(RUN, size_of_addr_128, {
    unsigned long size = size_of_addr(128);
    munit_assert_ulong(size, ==, 8, "size should be 8 on a 64-bit system");
});

int main() {

    /* long long i = 128;
    printf("The variable 'i' holds the value: %lld\n", i);
    printf("The memory address of 'i' is: %p\n", (void *)&i); */

    MunitTest tests[] = {
        munit_test("/size_of_addr_16", size_of_addr_16),
        munit_test("/size_of_addr_32", size_of_addr_32),
        munit_test("/size_of_addr_64", size_of_addr_64),
        munit_test("/size_of_addr_128", size_of_addr_128),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("colors", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}