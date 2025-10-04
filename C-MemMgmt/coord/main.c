#include <stdio.h>
#include "munit.h"
#include "coord.h"
// #include "coord.c" // was advised this was generally considered bad practice!
                      // Source files should be compiled seperately and linked together.

munit_case(RUN, test_new_coordinate1, {
    struct Coordinate c = new_coord(1, 2, 3);
    assert_int(c.x, ==, 1, "should set x");
    assert_int(c.y, ==, 2, "should set y");
    assert_int(c.z, ==, 3, "should set z");
});

munit_case(RUN, test_new_coordinate2, {
    struct Coordinate c = new_coord(4, 2, 0);
    assert_int(c.x, ==, 4, "should set x");
    assert_int(c.y, ==, 2, "should set y");
    assert_int(c.z, ==, 0, "should set z");
});

munit_case(RUN, test_scaled_coordinate1, {
    struct Coordinate c = new_coord(10, 20, 30);
    struct Coordinate scaled = scale_coordinate(c, 2);
    assert_int(scaled.x, ==, 20, "should scale x");
    assert_int(scaled.y, ==, 40, "should scale y");
    assert_int(scaled.z, ==, 60, "should scale z");
});

munit_case(RUN, test_scaled_coordinate2, {
    struct Coordinate c = new_coord(40, 20 , 10);
    struct Coordinate scaled = scale_coordinate(c, 5);
    assert_int(scaled.x, ==, 200, "should scale x");
    assert_int(scaled.y, ==, 100, "should scale y");
    assert_int(scaled.z, ==, 50, "should scale z");
});

int main() {
    MunitTest tests[] = {
        munit_test("/test_new_coordinate1", test_new_coordinate1),
        munit_test("/test_new_coordinate2", test_new_coordinate2),
        munit_test("/test_scaled_coordinate1", test_scaled_coordinate1),
        munit_test("/test_scaled_coordinate2", test_new_coordinate2),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("get_new_coordinates", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}