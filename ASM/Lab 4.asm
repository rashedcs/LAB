/*Problem Name : Write a program to swap two numbers */

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
    MOV BH, var2
                   
         
    XCHG BL, BH     ; swap of var1 and var2   

         
    ;for retruning decimal value but in this code ADD operation is not mandatory          
    ;ADD BL, 48     ; 
    ;ADD BH, 48     ;      
                
        
    
    MOV AH, 2      ;output
    MOV DL, BL
    INT 21H     
    MOV DL, BH
    INT 21H
    
        
    MOV AH, 4CH    ; not mandatory and for convention
    INT 21H     
 MAIN ENDP     
   
