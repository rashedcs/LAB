;Problem : Find the max value in array 

.MODEL SMALL
.STACK 100H
.DATA
ARR DB 2, 5, 7, 1 ,4
MAX DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV CX, 5
    MOV DI, 0
    MOV AL, 0
       
     
    FOR:
        CMP AL, ARR[DI]
        JG NOCHANGE     
        JNLE CHANGE  
       
      CHANGE :      
        MOV AL, ARR[DI]  
        INC DI
        LOOP FOR  
          
          
      NOCHANGE:
        INC DI
        LOOP FOR  
       
         
        
    MOV AH, 2   ;output
    ADD AL, 48
    MOV DL, AL
    INT 21H    
      
        
MAIN ENDP
