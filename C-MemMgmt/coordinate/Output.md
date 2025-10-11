## Output

coordinate</br>
```
% gcc -o coordinate main.c -std=c99 -Wall -Werror
% ./coordinate
Running suite: pointers
[SUCCESS] Test: /test_unchanged
[SUCCESS] Test: /test_changed
--- Test Summary ---
Passed: 2, Failed: 0
2 of 2 (100%) tests successful
```

with some printf outputs
```
% ./coordinate 

coordinate_update_x            = 0x100c947bc
coordinate_update_and_return_x = 0x100c94828
new_coordinate                 = 0x100c94728

Running suite: pointers
test unchanged old.x = 1 > 0x16f16abe8
test unchanged old.x = 1 > 0x16f16abe8
[SUCCESS] Test: /test_unchanged

test changed   new.x = 4 > 0x16f16abc8
test changed   old.x = 1 > 0x16f16abd8
[SUCCESS] Test: /test_changed

--- Test Summary ---
Passed: 2, Failed: 0
2 of 2 (100%) tests successful
```