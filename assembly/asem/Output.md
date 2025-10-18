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

armasem on ARM64
```
% as armasem.s -o armasem.o
% gcc -o armasem armasem.o -nostdlib -static
Undefined symbols for architecture arm64:
  "start", referenced from:
      <initial-undefines>
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 
```

ran this on ARM64
```
% strings asem | less

__bss_start
_edata
_end
.symtab
.strtab
.shstrtab
.note.gnu.property
.note.gnu.build-id
.text
```