bits 32 ; assembling for the 32 bits architecture

; declare external functions needed by our program
extern  _printf  

; declare the EntryPoint (a label defining the very first instruction of the program)
global _printDecimals        

  
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    formatfp db "The unsigned value is %d", 10, 0
    formatfn db "The signed value is %d", 10, 0

; our code starts here
segment code use32 class=code
_printDecimals:
    push ebp
    mov ebp, esp
    ;pushad
    mov eax, [ebp+8]
    mov ebx, [ebp+12]

    push dword eax
    push dword formatfp
    call _printf
    add ESP, 4*2

    push dword ebx
    push dword formatfn
    call _printf
    add ESP, 4*2

    ;popad

    ; restore the stack frame
    mov esp, ebp
    pop ebp
    ret 