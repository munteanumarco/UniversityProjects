bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b-byte; c-word; e-doubleword; x-qword signed representation
    ; r = (a-b+c*128)/(a+b)+e-x;
    ; (-20 + 27 + 2*128)/(-20-27) + 3454 - 28538 = -25079
    a db -20
    b db -27
    c dw -2
    e dd 3454
    x dq 28538
    r resq 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;ax = c*128
        mov ax, word [c]
        mov bl, 128
        imul bx
        
        ;ax = (c*128+a-b)
        add al, byte [a]
        sub al, byte [b]
        
        ; bx = (c*128+a-b)
        mov bx,ax
        
        ;al = a+b
        mov al,byte[a]
        add al,byte[b]
        ; ax = a+b
        cbw
        ; cx=a+b
        mov cx,ax
        ;ax = (c*128+a-b)
        mov ax,bx
        ; ax = (c*128+a-b)/(a+b)
        idiv cx
        
        ; to dword
        cwde
        ; to qword
      
        cdq
        
        ;move result in ecx:ebx
        mov ebx,eax
        mov ecx,edx
        
        ;convert e to qword
        push dword[e+2]
        push dword[e+0]
        pop eax 
        cdq
        ;add e to ecx:ebx = (c*128+a-b)/(a+b)+e 
        clc
        add ebx,eax
        adc ecx,edx
        ;substract x from ecx:ebx = (c*128+a-b)/(a+b)+e-x
        clc
        sub ebx,dword[x+0]
        sbb ecx,dword[x+4]
        
        ;store result in r
        mov dword[r+0],ebx
        mov dword[r+4],ecx
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
