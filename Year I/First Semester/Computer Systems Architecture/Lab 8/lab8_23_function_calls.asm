bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern exit, printf, scanf            
import exit msvcrt.dll     
import printf msvcrt.dll     ; indicating to the assembler that the printf fct can be found in the msvcrt.dll library
import scanf msvcrt.dll                         ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Read a hexadecimal number with 2 digits from the keyboard. 
    ;Display the number in base 10, in both interpretations: as an unsigned number and as an signed number (on 8 bits).
    hexa dd 0x0
    ten db 10
    sixteen db 16
    result resb 1
    p db 1
    message db "Insert hexa=",0
    read_format db "%x",0
    print_format db "The hexa as an unsigned number is: %d in base 10",10,0
    print_format_signed db "The hexa as an signed number is: -%d in base 10",0
    print_message_positive db "The hexa as an signed number is the same as unsigned",0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        push dword message
        call [printf]
        add esp , 4*1
        
        push dword hexa
        push dword read_format
        call [scanf]
        add esp, 4*2
        
        
        mov eax,[hexa]
        push eax
        push dword print_format
        call [printf]
        add esp,4*2
        
       
        mov eax,dword[hexa]
        div byte[ten]
        cmp al,7
        jg negative
        jmp positive
        negative:
            
            mov eax,0
            mov al,[hexa]
            not al
            add al,1
        
            push eax
            push dword print_format_signed
            call [printf]
            add esp,4*2
            jmp end_program
        positive:
            push dword print_message_positive
            call [printf]
            add esp,4*1
            
        end_program:
            
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
