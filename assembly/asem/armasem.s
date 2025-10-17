.global _start
.align 2

_start:
        // Set the value 8 into register x0
        mov x0, #8

        // Copy the value from x0 into x1
        mov x1, x0

        // Perform an exit system call with the status code from x0
        mov x8, #93
        svc #0
