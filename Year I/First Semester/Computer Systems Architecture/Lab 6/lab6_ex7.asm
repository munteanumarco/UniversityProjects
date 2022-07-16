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
    ;A string of doublewords is given. Obtain the list made out of the high bytes of the high words of each doubleword from the given list with the property that these bytes are multiple of 3.
    s DD 12345678h, 1A2B3C4Dh, 0FE98DC76h
    len equ ($-s)/4
    trei db 3
    result times len db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,len;move in ecx the length of s
        mov esi,s
        cld
        mov edi,0;index for result
        ;check for empty string
        jecxz done
            myLoop:
                lodsw
                lodsw
                ;keep a copy of the high byte in bl
                mov bl,ah
                
                ;move the high byte in al and in ah 0 so we can divide by 3
                mov al,bl
                mov ah,0
                div byte[trei]
                
                ;check the remainder if 0 add to result else skip
                cmp ah,0
                je add_number
                jmp next
                add_number:
                    mov byte[result+edi],bl
                    inc edi
                next:
            loop myLoop
        done:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
