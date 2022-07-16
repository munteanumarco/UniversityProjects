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
    ;Given the words A and B, compute the byte C as follows:
    ;   the bits 0-5 are the same as the bits 5-10 of A
    ;   the bits 6-7 are the same as the bits 1-2 of B.
    ;Compute the doubleword D as follows:
    ;   the bits 8-15 are the same as the bits of C
    ;   the bits 0-7 are the same as the bits 8-15 of B
    ;   the bits 24-31 are the same as the bits 0-7 of A
    ;   the bits 16-23 are the same as the bits 8-15 of A.
    
    a dw 1011010110111010b
    b dw 1000100111010111b
    c db 0 ;should be 1110 1101
    d dd 0 ;should be 1011 1010 1011 0101 1110 1101 1000 1001 
   
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        
        ;form c as given
        mov ax, word[a]
        and ax, 0000011111100000b
        mov cl, 5
        ror ax, cl
        mov bx, ax
        
        mov ax, word[b]
        and ax, 0000000000000110b
        mov cl, 5
        rol ax, cl
        or bx,ax
        
        ;store c
        mov byte[c],bl
        
        mov ebx, 0
        
        ;form d as given
        
        mov eax,0
        mov al, byte[c]
        and eax, 00000000000000000000000011111111b
        mov cl, 8
        rol eax, cl
        or ebx, eax
        
        mov eax, 0 
        mov ax, word[b]
        and eax, 00000000000000001111111100000000b
        mov cl, 8
        ror eax, cl
        or ebx, eax
        
        mov eax, 0
        mov ax, word[a]
        and eax, 00000000000000000000000011111111b
        mov cl, 24
        rol eax, cl
        or ebx, eax
        
        mov eax, 0
        mov ax, word[a]
        and eax, 00000000000000001111111100000000b
        mov cl, 8
        rol eax, cl
        or ebx, eax
            
        ;store d
        mov dword[d],ebx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program