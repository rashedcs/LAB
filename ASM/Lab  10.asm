.MODEL SMALL
.STACK 100H
 
 .DATA
 VAR1 DB ?  
 VAR2 DB ?
         
         
.CODE
MAIN PROC             
    MOV AX, @DATA  ; INITIALIZATION OF DATA SEGMENT
    MOV DS, AX       
                      
                          
    MOV AH, 1      ; INPUT  VAR1 AND VAR2
    INT 21H
    MOV VAR1, AL  
    INT 21H   
    MOV VAR2, AL
    
  
    MOV BL, VAR1
    MOV CL, VAR2   
          
    ADD BL, CL     ; ADDITION OF VAR1 AND VAR2     
    
    
    
    MOV AL, BL           ;
    MOV AH,0          
    AAA               
    
    MOV BX,AX          
    ADD BH,30H
    ADD BL,30H
              
              
    MOV AH,2
    MOV DL,0AH          
    INT 21H
    MOV DL,0DH
    INT 21H

    
    MOV AH,2
    MOV DL,BH       ;SHOWING SUM 
    INT 21H  
    
    MOV AH,2
    MOV DL,BL
    INT 21H

     
        
    MOV AH, 4CH    ; NOT MANDATORY AND FOR CONVENTION
    INT 21H     
 MAIN ENDP     
