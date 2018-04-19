;Problem Name : Write a assmebly code to convert a upper case to lower case letter 

.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC    
    MOV AH, 1      ;input
    INT 21H
    MOV BL, AL
    
    ADD BL, 32      ;upper to lower 
   ;SUB BL 32       ;lower to upper
                            
                    
                            
    MOV AH, 2       ;new line  
    MOV DL, 0AH
    INT 21H                 
    
    MOV DL, 0DH     ;curage return
    INT 21H
    
                
                
    MOV AH, 2       ;output
    MOV DL, BL
    INT 21H
    
        
    MOV AH, 4CH    ; not mandatory and for convention
    INT 21H     
 MAIN ENDP
