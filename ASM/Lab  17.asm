; Check the number is either prime or not
; Reference : Internet

.MODEL  SMALL
.DATA
     num   DB ?  
     INPUT DB 0AH,0DH,"Enter Number : $"    
     MSG1  DB 0AH,0DH,"Not Prime$"
     MSG2  DB 0AH,0DH,"Prime$"
           
.CODE
   MAIN  PROC

            MOV AX,@DATA
            MOV DS,AX

            LEA DX, INPUT
            MOV AH,09H
            INT 21H
    
            MOV AH,1
            INT 21H
            SUB AL,30H
            MOV num, AL
            
            MOV AH,00
            MOV CL,2
            DIV CL
            MOV CL,AL

    FOR:
            CMP CL, 1                                           
            JBE PRIME                                            
        
            MOV AH,0000H   ; To avoid Divide overflow error
                                                 
            MOV AL, num                                       
            DIV CL    
                                                   
            CMP AH,00                                         
            JZ NONPRIME                                        
           
            DEC CL                                             
    JMP FOR                                            
       
   
    NONPRIME:
            MOV AH,09H
            LEA DX, MSG1
            INT 21H   
            JMP EXIT           
 
    
    PRIME:
            MOV AH,09H
            LEA DX, MSG2
            INT 21H   
            JMP EXIT
    
    EXIT:
            MOV AH,4CH
            INT 21H
    
    MAIN    ENDP
END     MAIN
    
