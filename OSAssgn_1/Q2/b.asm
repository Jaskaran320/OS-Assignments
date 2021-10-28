extern c
section .data

    text1: db "In b()",0xa
    len: equ $ - text1

section .bss
    a resb 2

section .text
    global b

b:
    mov rax,rdi
    call print

    mov r10,$c
    mov [rbp+8],r10
    ret

print:
    mov rcx,a
    mov [rcx],dl
    mov rax,1
    mov rdi,1
    mov rsi,rax
    mov rdx,7
    syscall

    mov rax,1
    mov rdi,1
    mov rsi,text1
    mov rdx,len
    ret