### Output

asem on Linux
```
% cd asem
% as asem.s -o asem.o
% gcc -o asem asem.o -nostdlib -static

# Output
% ./asam
Segmentation fault (core dumped)
```

armasem on M4
```
% as armasem.s -o armasem.o
% gcc -o armasem armasem.o -nostdlib -static
Undefined symbols for architecture arm64:
  "start", referenced from:
      <initial-undefines>
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 
```