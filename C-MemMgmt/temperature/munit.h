#ifndef MUNIT_H
#define MUNIT_H

#include <stdio.h>
#include <math.h>   // For floating-point comparisons
#include <string.h> // For string comparison (strcmp)
#include <stdlib.h> // For exit() and other utilities

/* --- Data Structures --- */

struct MunitSuite;

typedef const char* (*MunitTestFunc)(const void* params);

typedef struct {
    char* name;
    MunitTestFunc test_func;
} MunitTest;

typedef struct MunitSuite {
    char* name;
    MunitTest* tests;
    struct MunitSuite* suites;
} MunitSuite;


/* --- Macros for defining tests and suites --- */

#define munit_null_test {NULL, NULL}

#define munit_case(tag, name, body) \
    static const char* munit_test_func_##name(const void* params) { \
        (void)params; \
        body \
        return NULL; \
    }

#define munit_test(name_str, test_func_name) \
    (MunitTest){name_str, munit_test_func_##test_func_name}


/* --- Assertion Macros --- */

#define MUNIT_EPSILON 1e-6

#define munit_assert_double_equal(expected, actual, message) do { \
    if (fabs((expected) - (actual)) > MUNIT_EPSILON) { \
        printf("\nAssertion Failed in test '%s': %s\n", __func__, message); \
        printf("  Expected: %f\n", (double)(expected)); \
        printf("  Actual:   %f\n", (double)(actual)); \
        return "Double values are not equal"; \
    } \
} while(0)

#define munit_assert_string_equal(expected, actual, message) do { \
    if (strcmp((const char*)(expected), (const char*)(actual)) != 0) { \
        printf("\nAssertion Failed in test '%s': %s\n", __func__, message); \
        printf("  Expected: \"%s\"\n", (const char*)(expected)); \
        printf("  Actual:   \"%s\"\n", (const char*)(actual)); \
        return "String values are not equal"; \
    } \
} while(0)


/* --- Function prototypes and minimal implementation for running tests --- */

int munit_suite_main(MunitSuite* suite, const void* params, unsigned int flags, void* user_data);

MunitSuite munit_suite(const char* name, MunitTest* tests) {
    MunitSuite s;
    s.name = (char*)name;
    s.tests = tests;
    s.suites = NULL;
    return s;
}

static int run_suite(MunitSuite* suite) {
    if (suite == NULL || suite->tests == NULL) {
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

    printf("Suite finished. Total tests: %d, Failures: %d\n\n", total_tests, failures);

    if (total_tests > 0) {
        float success_rate = ((float)(total_tests - failures) / total_tests) * 100.0f;
        printf("--- Test Summary ---\n");
        printf("Passed: %d, Failed: %d\n", total_tests - failures, failures);
        printf("%d of %d (%.0f%%) tests successful\n", total_tests - failures, total_tests, success_rate);
    }

    return failures;
}

int munit_suite_main(MunitSuite* suite, const void* params, unsigned int flags, void* user_data) {
    (void)params;
    (void)flags;
    (void)user_data;

    int total_failures = run_suite(suite);

    if (total_failures > 0) {
        return 1;
    } else {
        return 0;
    }
}

#endif // MUNIT_H
