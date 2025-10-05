## Output 
```
% ./structpad 
Running suite: padding

Assertion Failed in test 'munit_test_func_test_optimal_size': Should be 16 (in online playground)
  Expected: 24 == 16
[FAILED] Test: /test_optimal_size, Reason: Assertion failure
--- Test Summary ---
Passed: 0, Failed: 1
0 of 1 (0%) tests successful
```

Corrected structpad
```
% ./structpad 
sizeof(sneklang_var_t) = 24
Running suite: padding
[SUCCESS] Test: /test_optimal_size
--- Test Summary ---
Passed: 1, Failed: 0
1 of 1 (100%) tests successful
```