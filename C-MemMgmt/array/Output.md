## Output

Dereferencing Pointers</br>
```
% gcc -o array main.c array.c -std=c99 -Wall -Werror

% ./array 
Running suite: update_file
[SUCCESS] Test: /test_update_file_basic
[SUCCESS] Test: /test_update_file_different_values
--- Test Summary ---
Passed: 2, Failed: 0
2 of 2 (100%) tests successful
```

Output from running this on a Fedora Linux Distro
```
$ gcc -o array2 main.c array.c -std=c99 -Wall -Werror
array.c:3:22: error: argument 1 of type ‘int[200]’ with mismatched bound [-Werror=array-parameter=]
    3 | void update_file(int filedata[200], int new_filetype, int new_num_lines) {
      |                  ~~~~^~~~~~~~~~~~~
In file included from array.c:1:
array.h:6:23: note: previously declared as ‘int *’
    6 | void update_file(int *filedata, int new_filetype, int new_num_lines);
      |                  ~~~~~^~~~~~~~
cc1: all warnings being treated as errors
```

From learning some assembly stuff
```
% strings array | less

/test_update_file_basic
/test_update_file_different_values
update_file
No tests found.
Running suite: %s
[FAILED] Test: %s, Reason: %s
[SUCCESS] Test: %s
--- Test Summary ---
Passed: %d, Failed: %d
%d of %d (%.0f%%) tests successful
Assertion Failed in test '%s': %s
munit_test_func_test_update_file_basic
Number of lines should be update to 100
  Expected: %d %s %d
Assertion failure
File type should be update to 1
Last element should be set to 0
munit_test_func_test_update_file_different_values
Number of lines should be update to 250
File type should be update to 3
```