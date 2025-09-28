## Using the munit testing framework

For this exercise we didn't have the munit.h file, so I leaned on AI to help create this and worked out the errors from compiling</br>

- https://share.google/aimode/ALzr7zwrdezPg5lO4

Once the main errors I believed were fixed, when compiling I received a linking error :</br>
```
% gcc -o munit main.c    
Undefined symbols for architecture arm64:
  "_get_average", referenced from:
      _munit_test_func_test_get_average in main-9b4b78.o
      _munit_test_func_test_non_integer in main-9b4b78.o
      _munit_test_func_test_average_of_same in main-9b4b78.o
      _munit_test_func_test_average_of_big_numbers in main-9b4b78.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

To Fix this AI advised to run clang and link both .c files, I opted to use ggc which does the same function
```
gcc -o munit main.c exercise.c
```

Final Output :
```
% ./munit 
Running suite: get_average
[SUCCESS] Test: /get_average
[SUCCESS] Test: /get_average_float
[SUCCESS] Test: /get_average_same
[SUCCESS] Test: /get_average_big
Suite finished. Total tests: 4, Failures: 0

--- Test Summary ---
Passed: 4, Failed: 0
4 of 4 (100%) tests successful
```

Output with value's changed for some of the unit tests were set to fail :
```
% ./munit                       
Running suite: get_average

Assertion Failed in test 'munit_test_func_test_get_average': Average of 3, 4, 5 is 4
  Expected: 13.666667
  Actual:   4.000000
[FAILED] Test: /get_average, Reason: Double values are not equal

Assertion Failed in test 'munit_test_func_test_non_integer': Average of 3, 3, 5 is 3.66667
  Expected: 103.666664
  Actual:   3.666667
[FAILED] Test: /get_average_float, Reason: Double values are not equal

Assertion Failed in test 'munit_test_func_test_average_of_same': Average of 10s... is 10
  Expected: 3.333333
  Actual:   10.000000
[FAILED] Test: /get_average_same, Reason: Double values are not equal
[SUCCESS] Test: /get_average_big
Suite finished. Total tests: 4, Failures: 3

--- Test Summary ---
Passed: 1, Failed: 3
1 of 4 (25%) tests successful
```

I went through the munit.h and main.c to try and work out how the tests worked! But will re-visit this exercise once I've learnt more C stuff... 

## Summary of the munit.h file's interaction with main.c
1. main.c uses munit_case macros to define individual tests, which creates the underlying C functions.
2. main.c uses the munit_test helper macro to build an array of MunitTest structs, with each entry pointing to the correct test function.
3. main.c calls munit_suite() to bundle the test array into a MunitSuite.
4. Finally, main.c calls munit_suite_main() to kick off the testing process, with the munit.h functions handling all the logic for running the tests and reporting the results. 
