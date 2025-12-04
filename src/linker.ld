ENTRY(_start)

SECTIONS
{
    /* QEMU loads kernel at 0x40000000 */
    . = 0x40000000;

    .text : {
        KEEP(*(.text.startup))
        *(.text*)
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    }
}
