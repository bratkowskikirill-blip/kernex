;db 0x12 1 byte
;dw 0x1234 2 bytes
;dd 0x12345678 4 bytes
;dq 0x123456789ABCDEF0 8 bytes
bits 32
section .multiboot
header_start:
    dd 0xE85250D6
    dd 0
    dd header_end - header_start
    dd -(0xE85250D6 + 0 + (header_end - header_start))

    dw 0
    dw 0
    dd 8

header_end:

section .text
global start
extern kernel_main

start:
    cli
    call kernel_main

.hang:
    hlt
    jmp .hang