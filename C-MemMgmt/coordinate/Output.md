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

coordinate_update_x            > 0x1001cc7bc
coordinate_update_and_return_x > 0x1001cc828
new_coordinate                 > 0x1001cc728

Running suite: pointers
orginal value old.x  = 1 > 0x16fc32be8
orginal value old.y  = 2 > 0x16fc32bec
orginal value old.z  = 3 > 0x16fc32bf0

test unchanged old.x = 1 > 0x16fc32be8
test unchanged old.x = 1 > 0x16fc32be8
[SUCCESS] Test: /test_unchanged

test changed   old.x = 1 > 0x16fc32bd8
test changed   new.x = 4 > 0x16fc32bc8
test changed   old.x = 1 > 0x16fc32bd8
[SUCCESS] Test: /test_changed

--- Test Summary ---
Passed: 2, Failed: 0
2 of 2 (100%) tests successful
```