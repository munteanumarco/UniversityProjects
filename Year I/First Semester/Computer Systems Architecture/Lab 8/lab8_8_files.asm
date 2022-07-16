; Codul de mai jos va deschide un fisier numit "input.txt" din directorul curent si va citi intregul text din acel fisier, in etape, cate 100 de caractere intr-o etapa.
; Deoarece un fisier text poate fi foarte lung, nu este intotdeauna posibil sa citim fisierul intr-o singura etapa pentru ca nu putem defini un sir de caractere suficient de lung pentru intregul text din fisier. De aceea, prelucrarea fisierelor text in etape este necesara.
; Programul va folosi functia fopen pentru deschiderea fisierului, functia fread pentru citirea din fisier si functia fclose pentru inchiderea fisierului creat.
; Deoarece in apelul functiei fopen programul foloseste modul de acces "r", daca un fisier numele dat nu exista in directorul curent,  apelul functiei fopen nu va reusi (eroare). Detalii despre modurile de acces sunt prezentate in sectiunea "Suport teoretic".

bits 32 

global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll 
import fopen msvcrt.dll 
import fread msvcrt.dll 
import fclose msvcrt.dll
import printf msvcrt.dll 

; our data is declared here 
segment data use32 class=data
    nume_fisier db "input.txt", 0   
    mod_acces db "r", 0             
    descriptor_fis dd -1            
    nr_car_citite dd 0              
    len equ 100                    
    buffer resb len                 
    max_freq db 0
    max_letter db 0
    format db "Max letter: %c Frequency: %d", 0

; our code starts here
segment code use32 class=code
    start:
        ; apelam fopen pentru a deschide fisierul
        ; functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0                  
        je final
        
        mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        bucla:
            ; citim o parte (100 caractere) din textul in fisierul deschis folosind functia fread
            ; eax = fread(buffer, 1, len, descriptor_fis)
            push dword [descriptor_fis]
            push dword len
            push dword 1
            push dword buffer
            call [fread]
            add esp, 4*4
            
            ; eax = numar de caractere / bytes citite
            cmp eax, 0          ; daca numarul de caractere citite este 0, am terminat de parcurs fisierul
            je cleanup
            
          
           
            push eax
            
            mov esi,buffer
            ;index for first loop
            mov edx,0
            mov bl,0
            myLoop:
                lodsb
                inc edx
                cmp al,0
                je myfinal
                cmp al,'a'
                jb next
                cmp al,'z'
                ja next
                mov edi,edx
                mov cl,al
                ;store the apperances for this letter
                mov bl,1
                secondLoop:
                    mov al,[buffer+edi]
                    cmp al,0
                    je next
                    cmp al,cl
                    je adauga
                    jmp next_inner
                    adauga:
                       inc bl
                       cmp bl,byte[max_freq]
                       ja new_max
                       jmp next_inner
                       new_max:
                        mov byte[max_freq],bl
                        mov byte[max_letter],cl
                    next_inner:
                    inc edi
                jmp secondLoop
                next:
        jmp myLoop
        myfinal:
                
            ; reluam bucla pentru a citi alt bloc de caractere
            pop eax
            jmp bucla
        
      cleanup:
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
      final:  
        mov eax,0
        mov al,byte[max_freq]
        mov ebx,0
        mov bl,byte[max_letter]
        push dword eax
        push dword ebx
        push dword format
        call [printf]
        add esp, 4*3

        
        ; exit(0)
        push    dword 0      
        call    [exit]       

