section .text
global asm_SAXPY
global asm_LENGTH

; rcx contains n
asm_LENGTH:
    mov rbx, rcx
    ret


; xmm0 contains scalar variable A
; rdx contains scalar variable X
; r8 contains scalar variable Y
; r9 contains scalar varaible Z_asm
asm_SAXPY:
    push rbp
    mov rbp, rsp
    mov r15, rdx 
    mov r14, r8
    mov r13, r9

; loop to perform SAXPY function
SAXPY_LOOP:
    movss xmm1, dword[r15]
    movss xmm2, dword[r14]

    mulss xmm1, xmm0
    addss xmm1, xmm2

    movss dword[r13], xmm1

    add r15, 4
    add r14, 4
    add r13, 4

    dec rbx
    cmp rbx, 0
    jne SAXPY_LOOP

    pop rbp
    ret