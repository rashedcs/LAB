; Problem : input array from user
INCLUDE 'EMU8086.INC'
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
    
    MOV CX, 5
    MOV DI, 0
    ADD DI, 4    
    
    MOV AH, 2       ;new line  
    MOV DL, 0AH
    INT 21H                 
    MOV DL, 0DH     ;curage return
    INT 21H   
  
    
   BACK: 
     MOV AL, ARR[DI]
     
     MOV AH, 2       ;output
     MOV DL, AL  
     INT 21H  

     DEC DI      
   LOOP BACK    
      
 MAIN ENDP
