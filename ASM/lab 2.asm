/* Problem Name : Write a program to add intefer number */

.MODEL SMALL
.STACK 100H
 
 .DATA
 var1 DB ?  
 var2 DB ?
         
         
.CODE
MAIN PROC             
    MOV AX, @DATA  ; initialization of data segment
    MOV DS, AX       
                      
                          
    MOV AH, 1      ; input  var1 and var2
    INT 21H
    MOV var1, AL  
    INT 21H   
    MOV var2, AL
    
  
    MOV BL, var1
    MOV CL, var2
    
         
    ADD BL, CL     ; addition of var1 and var2   
    SUB BL, 48     ; For returing decimal value
        
    
    MOV AH, 2      ;output
    MOV DL, BL
    INT 21H
    
        
    MOV AH, 4CH    ; not mandatory and for convention
    INT 21H     
 MAIN ENDP     

END MAIN
   
