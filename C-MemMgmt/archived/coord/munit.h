#ifndef MUNIT_H
#define MUNIT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* --- Data Structures --- */

// The structure for a single test case.
typedef const char* (*MunitTestFunc)(const void* params);
typedef struct {
    char* name;
    MunitTestFunc test_func;
} MunitTest;

// The structure for a test suite.
typedef struct MunitSuite {
    char* name;
    MunitTest* tests;
} MunitSuite;


/* --- Macros for defining tests and assertions --- */

// The munit_case macro defines a test function.
#define munit_case(tag, name, body) \
    static const char* munit_test_func_##name(const void* params) { \
        (void)params; \
        body \
        return NULL; \
    }

// The munit_test macro creates an entry in the MunitTest array.
#define munit_test(name_str, test_func_name) \
    (MunitTest){name_str, munit_test_func_##test_func_name}

// The sentinel macro to end the array of tests.
#define munit_null_test {NULL, NULL}

// assert_int macro
#define assert_int(a, op, b, message) do { \
    if (!((a) op (b))) { \
        printf("\nAssertion Failed in test '%s': %s\n", __func__, message); \
        printf("  Expected: %d %s %d\n", (int)(a), #op, (int)(b)); \
        return "Assertion failure"; \
    } \
} while(0)


/* --- Function prototypes and implementation --- */

// Create a test suite.
MunitSuite munit_suite(const char* name, MunitTest* tests) {
    MunitSuite s;
    s.name = (char*)name;
    s.tests = tests;
    return s;
}

// Run the tests in a suite.
static int run_suite(MunitSuite* suite) {
    if (suite == NULL || suite->tests == NULL) {
        printf("No tests found.\n");
        return 0;
    }

    int failures = 0;
    int total_tests = 0;

    printf("Running suite: %s\n", suite->name);

    for (int i = 0; suite->tests[i].name != NULL; ++i) {
        const char* result = suite->tests[i].test_func(NULL);
        if (result != NULL) {
            printf("[FAILED] Test: %s, Reason: %s\n", suite->tests[i].name, result);
            failures++;
        } else {
            printf("[SUCCESS] Test: %s\n", suite->tests[i].name);
        }
        total_tests++;
    }

    if (total_tests > 0) {
        printf("--- Test Summary ---\n");
        printf("Passed: %d, Failed: %d\n", total_tests - failures, failures);
        printf("%d of %d (%.0f%%) tests successful\n\n", 
            total_tests - failures, total_tests, 
            ((float)(total_tests - failures) / total_tests) * 100.0f);
    }

    return failures;
}

// The main entry point for the test runner.
int munit_suite_main(MunitSuite* suite, const void* params, unsigned int flags, void* user_data) {
    (void)params;
    (void)flags;
    (void)user_data;

    int total_failures = run_suite(suite);
    return total_failures > 0 ? 1 : 0;
}

#endif // MUNIT_H
