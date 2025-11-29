.global _start
.global KfoMain

.section ".text.startup"
_start:
    mrs x1, mpidr_el1
    and x1, x1, #3

    cmp x1, #0
    bne _halt

    mov sp, #0x80000

    bl KfoMain

_halt:
    b _halt