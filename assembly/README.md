# Assembly

### Learning Assembly from YT

- Learn assembly in 10 minutes via Low Level from YT - https://youtu.be/6S5KRJv-7RU?si=x7J50EJHgejavtuT
- everything is open source if you can reverse engineer (try it RIGHT NOW!) - https://youtu.be/gh2RXE9BIN8?si=Vf2sP8vugaM4TpJI
- Assembly Language Programming with ARM – Full Tutorial for Beginners via fCC.org - https://youtu.be/gfmRrPjnEw4?si=wSQN_AcRhdUXNMHE

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