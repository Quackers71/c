## Output

memaddr_old (renamed)
```
% ./memaddr_old
Running suite: colors

Assertion Failed in test 'munit_test_func_size_of_addr_16': size should be 4
  Expected: 8 == 4
[FAILED] Test: /size_of_addr_16, Reason: Assertion failure

Assertion Failed in test 'munit_test_func_size_of_addr_32': size should be 4
  Expected: 8 == 4
[FAILED] Test: /size_of_addr_32, Reason: Assertion failure

Assertion Failed in test 'munit_test_func_size_of_addr_64': size should be 4
  Expected: 8 == 4
[FAILED] Test: /size_of_addr_64, Reason: Assertion failure

Assertion Failed in test 'munit_test_func_size_of_addr_128': size should be 4
  Expected: 8 == 4
[FAILED] Test: /size_of_addr_128, Reason: Assertion failure
--- Test Summary ---
Passed: 0, Failed: 4
0 of 4 (0%) tests successful
```

memaddr
```
% ./memaddr
Running suite: colors
[SUCCESS] Test: /size_of_addr_16
[SUCCESS] Test: /size_of_addr_32
[SUCCESS] Test: /size_of_addr_64
[SUCCESS] Test: /size_of_addr_128
--- Test Summary ---
Passed: 4, Failed: 0
4 of 4 (100%) tests successful
```

memfulladdr
```
% ./memfulladdr                                   
The variable 'i' holds the value: 128
The memory address of 'i' is: 0x16f542cd8
Running suite: colors
[SUCCESS] Test: /size_of_addr_16
[SUCCESS] Test: /size_of_addr_32
[SUCCESS] Test: /size_of_addr_64
[SUCCESS] Test: /size_of_addr_128
--- Test Summary ---
Passed: 4, Failed: 0
4 of 4 (100%) tests successful
```