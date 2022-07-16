bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...Given an array A of doublewords, build two arrays of bytes:  
    ;array B1 contains as elements the higher part of the higher words from A
    ;array B2 contains as elements the lower part of the lower words from A
    
    array dd 11223344h,22334455h,33445566h
    len equ ($-array)/4
    b1 times len db 0;11 22 33
    b2 times len db 0;44 55 66
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi,array
        mov edi,0
        mov ecx,len
        jecxz done
            myLoop:
                lodsw
                ;the low part of the low word will be in al 
                mov byte[b1+edi],al
                lodsw 
                ;the highpart of the high word will be in ah
                mov byte[b2+edi],ah                
                inc edi
            loop myLoop
        done:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
