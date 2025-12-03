.global _start
.global KfoMain

.section ".text.startup"
_start:

    mov sp, #0x80000

    bl KfoMain

_halt:
    b _halt
