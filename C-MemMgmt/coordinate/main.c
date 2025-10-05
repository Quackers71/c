#include <stdio.h>
#include "munit.h"
#include "coordinate.h"
#include "coordinate.c"

munit_case(RUN, test_unchanged, {
    coordinate_t old = new_coordinate(1, 2, 3);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");

    coordinate_update_x(old, 4);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");
});

munit_case(RUN, test_changed, {
    coordinate_t old = new_coordinate(1, 2, 3);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");

    coordinate_t new = coordinate_update_and_return_x(old, 4);
    munit_assert_int(new.x, ==, 4, "new.x must be 4");
    munit_assert_int(old.x, ==, 1, "old.x must be 1");

    munit_assert_ptr_not_equal(&old, &new, "Must not be the same address");
});

int main() {
    MunitTest tests[] = {
        munit_test("/test_unchanged", test_unchanged),
        munit_test("/test_changed", test_changed),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("pointers", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
