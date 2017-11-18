; Problem : input array from user
INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK
.DATA
   ARR DB 10 DUB (?)   
   ;STR DB 0AH,0DH,'OUTPUT: $' 
   
.CODE
 MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    XOR BX, BX
    MOV CX, 0
    
  FOR: 
      MOV AH, 1
      INT 21H  
          
      CMP AL,0DH
      JE  PRINT   
      
      MOV ARR[BX], AL
      INC BX 
      INC CX
   JMP FOR
        
              
 PRINT:  
    MOV AH, 2       ;new line  
    MOV DL, 0AH
    INT 21H                 
    MOV DL, 0DH     ;curage return
    INT 21H   
  
    
  BACK: 
     CMP CX, 0
     JE FINISH
     DEC CX
     DEC BX  
     
     MOV AL, ARR[BX]
     
     MOV AH, 2       
     MOV DL, AL  
     INT 21H            
   JMP BACK
   
 FINISH:
    MOV AH,4CH
    INT 21H   
      
 MAIN ENDP
 
 ;Daught : https://ideone.com/fXkSIl
