#ifndef MUNIT_H
#define MUNIT_H

#include <stdio.h>
#include <math.h>   // For floating-point comparisons
#include <string.h> // For string-related functions
#include <stdlib.h> // For exit() and other utilities

/* --- Data Structures --- */

// A forward declaration for the test suite struct to allow nested suites.
struct MunitSuite;

// The function signature for a single test case.
// It returns NULL on success or a string with an error message on failure.
typedef const char* (*MunitTestFunc)(const void* params);

// Structure to define a single test case.
typedef struct {
    char* name;
    MunitTestFunc test_func;
    // ... additional fields for setup/teardown could be added here
} MunitTest;

// Structure to define a test suite, which is a collection of test cases.
typedef struct MunitSuite {
    char* name;
    MunitTest* tests;
    struct MunitSuite* suites; // Allows for nested suites
    // ... additional fields for setup/teardown could be added here
} MunitSuite;


/* --- Macros for defining tests and suites --- */

// A special macro to mark the end of an array of MunitTest.
#define munit_null_test {NULL, NULL}

// Macro for defining a test function.
// It uses a unique function name based on the identifier provided.
// The `tag` is for potential test filtering in a more advanced implementation.
#define munit_case(tag, name, body) \
    static const char* munit_test_func_##name(const void* params) { \
        (void)params; /* Avoid unused parameter warning */ \
        body \
        return NULL; /* Return NULL on success */ \
    }

// Macro for creating an MunitTest structure instance.
// It correctly references the unique function name created by munit_case.
#define munit_test(name_str, test_func_name) \
    (MunitTest){name_str, munit_test_func_##test_func_name}


/* --- Assertion Macros --- */

// The standard epsilon for comparing floating-point numbers.
#define MUNIT_EPSILON 1e-6

// A macro for comparing two doubles.
#define munit_assert_double_equal(expected, actual, message) do { \
    if (fabs((expected) - (actual)) > MUNIT_EPSILON) { \
        printf("\nAssertion Failed in test: %s\n", message); \
        printf("  Expected: %f\n", (double)(expected)); \
        printf("  Actual:   %f\n", (double)(actual)); \
        return "Double values are not equal"; \
    } \
} while(0)


/* --- Function prototypes and minimal implementation for running tests --- */

// The main function to run the test suite.
int munit_suite_main(MunitSuite* suite, const void* params, unsigned int flags, void* user_data);

// Function to create and configure a test suite.
MunitSuite munit_suite(const char* name, MunitTest* tests) {
    MunitSuite s;
    s.name = (char*)name;
    s.tests = tests;
    s.suites = NULL;
    return s;
}

// A minimal function to run a suite.
static int run_suite(MunitSuite* suite) {
    if (suite == NULL || suite->tests == NULL) {
        return 0; // No tests to run
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
    printf("Suite finished. Total tests: %d, Failures: %d\n\n", total_tests, failures);

    return failures;
}

// A basic implementation of munit_suite_main for this minimal example.
int munit_suite_main(MunitSuite* suite, const void* params, unsigned int flags, void* user_data) {
    (void)params;
    (void)flags;
    (void)user_data;

    int total_failures = run_suite(suite);

    if (total_failures > 0) {
        printf("All tests finished. Total failures: %d\n", total_failures);
        return 1; // Return non-zero for failure
    } else {
        printf("All tests passed!\n");
        return 0; // Return zero for success
    }
}

#endif // MUNIT_H
