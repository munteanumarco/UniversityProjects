bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b-byte; c-word; e-doubleword; x-qword unsigned representation
    ; r = (a-b+c*128)/(a+b)+e-x;
    ; (10 - 7 + 25*128)/(10+7) + 8454 - 5538 = 3104
    a db 10
    b db 7
    c dw 25
    e dd 8454
    x dq 5538
    r resq 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;ax = c*128
        mov eax,0
        mov ax, word [c]
        mov bx,0
        mov bl, 128
        mul bx
        
        ;ax = (c*128+a-b)
        add al, byte [a]
        sub al, byte [b]
        
        ;bl = a+b
        mov bl, byte[a]
        add bl, byte[b]
        ;convert to word
        mov bh,0
        
        ;divide ax = (c*128+a-b)/(a+b)
        div bx   
        
        ;convert to qword ( edx:eax) eax was set initialy to 0 
        mov edx,0
       
       ;convert e to qword
       mov ebx, dword[e]
       mov ecx,0
       
       ;add e to edx:eax
       clc
       add eax,dword[e]
       adc ebx,ecx
       
       ;substract x from edx:eax
       clc
       sub eax, dword[x+0]
       sbb edx, dword[x+4]
       
       
        ;store result in r
        mov dword[r+0],eax
        mov dword[r+4],edx
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program