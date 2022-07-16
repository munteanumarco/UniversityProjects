bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a - byte, b - word, c - double word, d - qword - Signed representation
    ; x = a-d+b+b+c
    ; 45-51267+423+423+4215 = -46161
    a db 45
    b dw 423
    c dd 4215
    d dq 51267
    x resq 1

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Convert a to qword , edx:eax = a
        mov al, byte[a]
        cbw 
        cwd 
        push dx
        push ax
        pop eax
        cdq 
        
        ;Put in ecx:ebx = a
        mov ebx, eax
        mov ecx, edx
        
        ;Substract d , ecx:ebx - d => ecx:ebx = a-d
        clc        
        sub ebx, dword[d+0]
        sbb ecx, dword[d+4]
        
        ;Convert b to qword , edx:eax = b
        mov ax, word[b]
        cwd 
        push dx 
        push ax
        pop eax
        cdq 
        
        ;Add b twice , ecx:ebx + b + b => ecx:ebx = a-d+b+b
        clc
        add ebx, eax
        adc ecx, edx
        clc
        add ebx, eax
        adc ecx, edx
        
        ;Convert c to qword , edx:eax = c
        mov eax, dword[c]
        cdq
        
        
        ;Add c , ecx:ebx + c => ecx:ebx = a-d+b+b+c
        clc
        add ebx, eax
        adc ecx, edx
        
        ;Store the result in x
        mov dword[x+0], ebx
        mov dword[x+4], ecx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
