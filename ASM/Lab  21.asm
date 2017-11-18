; Problem : traverse the inputed array from user
; Code are given below :
.MODEL SMALL
.STACK
.DATA
   ARR DB 10 DUP (?)     
   
.CODE
 MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    XOR BX, BX
    MOV CX, 5
    
    FOR: 
      MOV AH, 1
      INT 21H
      MOV ARR[BX], AL
      INC BX
    LOOP FOR
       
       
    MOV AH, 2       ;new line  
    MOV DL, 0AH
    INT 21H                 
    MOV DL, 0DH     ;curage return
    INT 21H   
    
       
       
    XOR AX, AX      ;clear ax register   
    MOV CX, BX
    XOR BX, BX
    
    
    PRINT:  
     MOV AX, ARR[BX]  ;point to the  current index 
        
     MOV AH, 2        ;output
     MOV DL, AX  
     INT 21H     
     
     INC BX           ;move pointer to the next element 
    LOOP PRINT        ;loop until done
      
 MAIN ENDP
 





; Daught : https://ideone.com/YSCl0w
; Daught : https://ideone.com/GVQ3vG 
