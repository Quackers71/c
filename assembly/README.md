# Assembly

### Learning Assembly from YT

- Learn assembly in 10 minutes via Low Level from YT - TBC

You can Build and Run in a Terminal or run it via the Terminal in VSCode
```
# e.g.
% cd asem
% as asem.s -o asem.o
% gcc -o asem asem.o -nostdlib -static

# Output
./asam
Segmentation fault (core dumped)
```

Some other commands
```
% objdump -d Mintel asem | test
/Library/Developer/CommandLineTools/usr/bin/objdump: error: 'Mintel': No such file or directory
# need to work on this and try it out on Linux
```