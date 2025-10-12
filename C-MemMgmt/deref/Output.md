## Output

Dereferencing Pointers</br>
```
% gcc -o deref main.c deref.c -std=c99 -Wall -Werror

% ./deref 
Running suite: change_filetype
[SUCCESS] Test: /test_change_filetype1
[SUCCESS] Test: /test_change_filetype2
[SUCCESS] Test: /test_change_filetype3
[SUCCESS] Test: /test_change_filetype4
[SUCCESS] Test: /test_change_filetype5
--- Test Summary ---
Passed: 5, Failed: 0
5 of 5 (100%) tests successful
```

Full Output</br>
```
% ./deref 

Running suite: change_filetype

original.lines    = 100  > 0x16ce22c18
original.filetype = 1    > 0x16ce22c1c
changed.lines     = 100  > 0x16ce22c10
changed.filetype  = 2    > 0x16ce22c14
[SUCCESS] Test: /test_change_filetype1

original.lines    = 50   > 0x16ce22c18
original.filetype = 3    > 0x16ce22c1c
changed.lines     = 50   > 0x16ce22c10
changed.filetype  = 4    > 0x16ce22c14
[SUCCESS] Test: /test_change_filetype2

original.lines    = 200  > 0x16ce22c18
original.filetype = 5    > 0x16ce22c1c
changed.lines     = 200  > 0x16ce22c10
changed.filetype  = 5    > 0x16ce22c14
[SUCCESS] Test: /test_change_filetype3

original.lines    = 1    > 0x16ce22c18
original.filetype = 0    > 0x16ce22c1c
changed.lines     = 1    > 0x16ce22c10
changed.filetype  = 1    > 0x16ce22c14
[SUCCESS] Test: /test_change_filetype4

original.lines    = 1000 > 0x16ce22c18
original.filetype = 10   > 0x16ce22c1c
changed.lines     = 1000 > 0x16ce22c10
changed.filetype  = 20   > 0x16ce22c14
[SUCCESS] Test: /test_change_filetype5

--- Test Summary ---
Passed: 5, Failed: 0
5 of 5 (100%) tests successful
```