; Problem : Write a code to find the summation of 1D array 



.MODEL SMALL
.STACK 100H    

.DATA
ARR db 1,2,3
TOTAL db ?       

.code
MAIN proc
MOV AX, @DATA  ; initialization of data segment
MOV DS, AX   

XOR AX, AX    ; AX holds sum
LEA SI,  ARR  ; SI points to array ARR
MOV CX, 3     ; CX has number of elements


sum:
ADD AX, ARR[SI]    ; sum += ARR[i]
INC SI             ; move element to the next pointer
LOOP sum           ; loop until CX=3
           
ADD AX, 48         ; for returning decimal value
MOV total, AX      ; Move AX value into total  

 
MOV AH, 2          ;output  
MOV DL, TOTAL
INT 21H
    
        
MOV AH, 4CH       ; not mandatory and for convention
INT 21H     
   
MAIN ENDP
