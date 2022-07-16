bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;a - byte, b - word, c - double word, d - qword - Unsigned representation
    ; x= (d+d-b)+(c-a)+d
    
    ; 23456+23456-2345+2345-23+23456 = 70345
    a db 23
    b dw 2345
    c dd 2345
    d dq 23456
    x resq 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;  edx:eax = d 
        mov eax, dword [d+0]
        mov edx, dword [d+4] 
        
        ;edx:eax + d 
        ;edx:eax = d+d
        clc
        add eax, dword[d+0]
        adc edx, dword[d+4]
        clc
        ;edx:eax - ecx:ebx 
        ;edx:eax = d+d-b
        mov ebx, 0
        mov bx, word[b]
        mov ecx, 0
        sub eax,ebx
        sbb edx,ecx
        
        ;ecx = c
        mov ecx, dword [c]
        
        ;ebx = a
        mov ebx,0
        mov bl, byte [a]
        
        ;ecx-ebx
        ;ecx = c-a
        sub ecx,ebx
        
        ;eax+ecx
        ;eax = (d+d-b) + (c-a)
        add eax,ecx
        
        ;eax + low d
        ;edx + high d
        ;edx:eax = (d+d-b) + (c-a) + d
        add eax,dword[d+0]
        adc edx,dword[d+4]
        
        ;x = edx:eax
        mov dword [x+0], eax
        mov dword [x+4], edx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program