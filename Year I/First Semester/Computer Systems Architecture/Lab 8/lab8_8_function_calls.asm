bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;A natural number a (a: dword, defined in the data segment) is given. 
    ;Read a natural number b from the keyboard and calculate: a + a/b. 
    ;Display the result of this operation. 
    ;The values will be displayed in decimal format (base 10) with sign.
    a dd 20123241
    b dd 0
    read_message db "b=",0
    read_format db "%d",0
    print_format db "a+a/b = %d",0
    
; our code starts here
segment code use32 class=code
    start:
        push dword read_message
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword read_format
        call [scanf]
        add esp, 4*2
       
        mov eax,dword[a]
        cdq
        idiv dword[b]
        add eax,dword[a]
        
        push dword eax
        push dword print_format
        call [printf]
        add esp, 4*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the programs