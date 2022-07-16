checkPrime:

        mov eax, [esp + 4]; the parameter is always one byte
        cmp eax, 2
        je prime
        jl notPrime
        mov bl, 2
    myloop:
        div bl
        cmp ah, 0
        je notPrime
        mov eax, [esp + 4]
        
        inc bl
        cmp bl, al
        je prime
    jmp myloop
        
    notPrime:
        mov eax, 0
        jmp fin
    prime:
        mov eax, 1
    fin:
    ret