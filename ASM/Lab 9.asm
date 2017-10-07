; Problem : input array from user

.MODEL SMALL
.STACK
.DATA
   ARR DB 10 DUB (?)     
   
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
    
    
    XOR BX, BX
    MOV CX, 10 
    
    PRINT:  
     MOV AX, ARR[BX] ;point to the  current index 
     ;SUB AX, 48      ;for converting decimal value
        
     MOV AH, 2       ;output
     MOV DL, AX  
     INT 21H     
     
     INC BX           ;move pointer to the next element 
    LOOP PRINT       ;loop until done
     
    
 MAIN ENDP
