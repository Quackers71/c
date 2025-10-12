## Again using the munit testing framework for temperature if/else statements

For this exercise, again we didn't have the munit.h file, so I leaned on AI to help create this and worked out the errors from compiling</br>

- https://share.google/aimode/zKQyOKsBjWhKFLVoL

Compiled using :
```
gcc -o temperature main.c exercise.c
```

Final Output :
```
% ./temperature
Running suite: get_temperature_status
[SUCCESS] Test: /test_cold
[SUCCESS] Test: /test_hot
[SUCCESS] Test: /test_just_right
[SUCCESS] Test: /test_just_right2
Suite finished. Total tests: 4, Failures: 0

--- Test Summary ---
Passed: 4, Failed: 0
4 of 4 (100%) tests successful
```