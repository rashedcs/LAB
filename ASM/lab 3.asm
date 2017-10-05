/* Problem Name : Write a assembly program to find out the maximum between two numbers */

.MODEL SMALL
.STACK 100H    

.DATA 
     NUM1 DB ?
     NUM2 DB ? 

.CODE       
MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
    
     
        MOV AH, 1       ; input num1
        INT 21H
        MOV NUM1, AL
     
     
        MOV AH, 1       ; input num2
        INT 21H
        MOV NUM2,AL
     
     
        MOV BL, NUM1 
        MOV BH, NUM2
     
        CMP BL, BH    ; 
        JG FIRST     
                   
                   
                   
        MOV AH, 2       ;new line  
        MOV DL, 0AH
        INT 21H                 
    
        MOV DL, 0DH     ;curage return
        INT 21H                   
                   
      
FIRST:  MOV AH,2
        MOV DL, BH   
        INT 21H   

        
        JMP EXIT   
     
SECOND: MOV AH,2
        MOV DL,BL
        INT 21H   

  
EXIT:   MOV AH,4CH
        INT 21H     
MAIN ENDP
