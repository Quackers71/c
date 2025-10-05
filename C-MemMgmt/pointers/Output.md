## Output

```
% ./pointers 
int x = 5
x is 5            @ 0x16b736d4c
int y = x
y is 5            @ 0x16b736d48
x = 7
x is 7            @ 0x16b736d4c
int *x_ptr = &x
*x_ptr is 7       @ 0x16b736d40
int z = *z_ptr
z is 7            @ 0x16b736d3c
*x_ptr = 12
*x_ptr is 12      @ 0x16b736d40
x is now 12       @ 0x16b736d4c
```