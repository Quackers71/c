#include <stdio.h>
#include "../munit.h"
#include "alt-deref.h"
// Do NOT include "deref.c", as it should be compiled separately and linked.

// A helper function to create a new codefile_t struct
codefile_t new_codefile(int lines, int filetype) {
    return (codefile_t){.lines = lines, .filetype = filetype};
}

munit_case(RUN, test_change_filetype1, {
    codefile_t original = new_codefile(100, 1);
    codefile_t changed = change_filetype(&original, 2);
    
    munit_assert_int(changed.filetype, ==, 2, "Filetype should change");
    munit_assert_int(original.filetype, ==, 1, "Original struct should be unchanged");

    print_codefile_info("original", original); // function call from alt-deref.c and declared in alt-deref.h
    print_codefile_info("changed", changed); // function call
});

munit_case(RUN, test_change_filetype2, {
    codefile_t original = new_codefile(50, 3);
    codefile_t changed = change_filetype(&original, 4);

    munit_assert_int(changed.filetype, ==, 4, "Filetype should change");
    munit_assert_int(original.filetype, ==, 3, "Original struct should be unchanged");

    print_codefile_info("original", original); // function call
    print_codefile_info("changed", changed); // function call
});

munit_case(RUN, test_change_filetype3, {
    codefile_t original = new_codefile(200, 5);
    codefile_t changed = change_filetype(&original, 5);

    munit_assert_int(changed.filetype, ==, 5, "Filetype should not change if same value");
    munit_assert_int(original.filetype, ==, 5, "Original struct should be unchanged");

    print_codefile_info("original", original); // function call
    print_codefile_info("changed", changed); // function call
});

munit_case(RUN, test_change_filetype4, {
    codefile_t original = new_codefile(1, 0);
    codefile_t changed = change_filetype(&original, 1);

    munit_assert_int(changed.filetype, ==, 1, "Filetype should change from 0");
    munit_assert_int(original.filetype, ==, 0, "Original struct should be unchanged");

    print_codefile_info("original", original); // function call
    print_codefile_info("changed", changed); // function call
});

munit_case(RUN, test_change_filetype5, {
    codefile_t original = new_codefile(1000, 10);
    codefile_t changed = change_filetype(&original, 20);

    munit_assert_int(changed.filetype, ==, 20, "Filetype should change to 20");
    munit_assert_int(original.filetype, ==, 10, "Original struct should be unchanged");

    print_codefile_info("original", original); // function call
    print_codefile_info("changed", changed); // function call
});

int main() {

    MunitTest tests[] = {

        munit_test("/test_change_filetype1", test_change_filetype1),
        munit_test("/test_change_filetype2", test_change_filetype2),
        munit_test("/test_change_filetype3", test_change_filetype3),
        munit_test("/test_change_filetype4", test_change_filetype4),
        munit_test("/test_change_filetype5", test_change_filetype5),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("change_filetype", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
