bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...A list of doublewords is given. Obtain the list made out of the low bytes of the high words of each doubleword from the given list with the property that these bytes are palindromes in base 10.
    s DD 12345678h, 1A2C3C4Dh, 98FCDC76h
    len equ ($-s)/4
    zece db 10
    numar times len db 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, s
        cld
        mov ecx,len
        mov edi,numar
        repeta:
            lodsw
            lodsw
            ;pastram bitii low
            mov ah,0;and ax,0xFF
            ;pastram o copie a numarului in bl
            mov bl,al 
            
            ;luam cifrele in baza 10
            div byte[zece]
            
            ;daca catul ramas e mai mare ca 9 inseamna ca mai trebuie impartit odata
            cmp al,0xA
            jl verifica_nr2cifre
            jmp verifica_nr3cifre
            
            verifica_nr2cifre:
                cmp al,ah
                jz adauga_numar
                jmp final
                
            verifica_nr3cifre:
                ;pastram in dl cifra 3
                mov dl,ah
                mov ah,0
                div byte[zece]
                ;in al avem cifra 1 si in ah avem cifra 2
                ;verificam cifra 1 cu cifra 3
                cmp al,dl
                jz adauga_numar
                jmp final
                
            adauga_numar:
                mov al,bl
                stosb
            final:
        loop repeta    
        
 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
