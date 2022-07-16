; the program computes the factorial of a number and writes to the console the result
; the function factorial is defined in the file factorial.asm
bits 32

global start

import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll
extern printf, scanf, exit

; the code defined in factorial.asm will be written here
%include "isprime.asm"

segment data use32 class=data
	print_message db "Insert the number of elements:",10,0
    read_format db "%d",0
    print_format db "%d ",0
    len dd 0
    list times 100 dd 0
    current_number dd 0
    


segment code use32 class=code
start:
	push dword print_message
    call [printf]
    add esp,4
   
    
    push dword len
    push dword read_format
    call [scanf]
    add esp,4*2
    
    mov esi,0
    mov ecx,dword[len]
    myLoop:
        push ecx
        
        push dword current_number
        push dword read_format
        call [scanf]
        add esp,4*2
        
        mov eax,[current_number]
        mov dword [list+esi*4],eax
        
        pop ecx
        inc esi
    loop myLoop
    
    mov esi,0
    mov ecx,dword[len]
    secondLoop:
        push ecx
        
        push dword [list+esi*4]
        call checkPrime
        add esp,4
        
        cmp eax,0
        je skip
        cmp eax,1
        jne skip
        
        push dword [list+esi*4]
        push print_format
        call [printf]
        add esp,4*2
        
        skip:
            pop ecx
            inc esi
    loop secondLoop

	push 0
	call [exit]


