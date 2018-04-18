; wite a program to print hello world in assembly 8080 programming language 

.MODEL SMALL 
.STACK 100H
                           
.DATA                                  
        MSG DB "HELLO WORLD$"            

.CODE   
 MAIN PROC                                 
        MOV AX,@DATA                 
        MOV DS,AX                      
                                        
        LEA DX,MSG                     
        MOV AH,09H                     
        INT 21H                         

        MOV AH,4CH                     
        INT 21H   
 MAIN ENDP   
 END      
