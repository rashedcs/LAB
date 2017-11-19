;1+2+3+4+5+.....+n
;Problem 1 : Write a program to sum of natural numbers
;series : 1+2+3+......+n
; Count
; (first term - las term)/difference 


;Source Code
.MODEL SMALL
.STACK  
.DATA
 b db ?
.CODE
MAIN PROC
MOV AX, 0 
MOV CX, 10

FOR: 
ADD AX, CX
LOOP FOR  

MOV BX, 10    

DIV BX
MOV b, DX


 MOV AH,2
 MOV DL, AX 
 ADD DL, 48
 INT 21H  
      
        
 MOV AH,2
 MOV DL, b   
 ADD DL, 48
 INT 21H

MAIN ENDP
























.MODEL SMALL
.STACK 100H
.DATA

    SUM DB 0
    N DB 10

.CODE


MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,0
    MOV AL,10
    XOR CX,CX                   
    MOV CX,AX
    
    TOP:
        ADD SUM,CL
        LOOP TOP
    
    MOV AL,SUM
    DIV N
    ADD AL,48
    ;MOV DL,AL  
    
    MOV AH,2 
    MOV DL,AL
    INT 21H
    SUB AL,48  
    
    MUL N
    SUB SUM,AL  
    
    MOV AH,2
    MOV DL,SUM
    ADD DL,48
    ;MOV AH,2
    INT 21H
    

    MOV AH,4CH
    INT 21H
    
    MAIN ENDP   

END MAIN

























.model small
.stack 100h 
.data 
    a db 49
    b db 48
 
.code       
main proc
     mov ax,@data
     mov ds,ax
     
     
    mov ax,0
    mov cx,10  
      
      
    FOR: 
         add al, a 

         mov ah,0 ; initialize zero for rid of garbaze
         aaa      ; for large addition
            
         add ah,48
         add al,48   
         
         
         mov dl,bh
         add b, dl
         sub b,48   
         
         mov bx, ax     
         inc a   
    LOOP FOR 
     
    mov ah,2 
    add bh, b
    mov dl,bh
    int 21h
     
    mov ah,2
    mov dl,bl
    int 21h   
    
main endp
