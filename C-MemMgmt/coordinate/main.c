#include <stdio.h>
#include "munit.h"
#include "coordinate.h"
#include "coordinate.c"

munit_case(RUN, test_unchanged, {
    coordinate_t old = new_coordinate(1, 2, 3);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");
    printf("test unchanged old.x = %d > %p\n", old.x, &old.x);

    coordinate_update_x(old, 4);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");
    printf("test unchanged old.x = %d > %p\n", old.x, &old.x);

});

munit_case(RUN, test_changed, {
    coordinate_t old = new_coordinate(1, 2, 3);
    munit_assert_int(old.x, ==, 1, "old.x must be 1");

    coordinate_t new = coordinate_update_and_return_x(old, 4);
    munit_assert_int(new.x, ==, 4, "new.x must be 4");
    printf("test changed   new.x = %d > %p\n", new.x, &new.x);

    munit_assert_int(old.x, ==, 1, "old.x must be 1");
    printf("test changed   old.x = %d > %p\n", old.x, &old.x);

    munit_assert_ptr_not_equal(&old, &new, "Must not be the same address");
});

int main() {

    printf("\ncoordinate_update_x            = %p\n", coordinate_update_x);
    printf("coordinate_update_and_return_x = %p\n", coordinate_update_and_return_x);
    printf("new_coordinate                 = %p\n", new_coordinate);
    printf("\n");
    
    MunitTest tests[] = {
        munit_test("/test_unchanged\n", test_unchanged),
        munit_test("/test_changed\n", test_changed),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("pointers", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
