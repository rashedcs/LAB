; Problem Name : Write a program to input a character and output that character

.MODEL SMALL
.STACK 100H        
.CODE
MAIN PROC             
                    
      
;input a character                    
    MOV AH, 1      
    INT 21H
    MOV BL, AL  

;go to new line 
    MOV AH, 2    ;display output function
    MOV DL, 0DH  ;carriage return 
    INT 21H      ;execute carriage return
    MOV DL, 0AH  ;line feed
    INT 21H       ;execute line feed
    
        
;display character
    MOV AH, 2      ;output
    MOV DL, BL
    INT 21H
    
;return to dos    
    MOV AH, 4CH    ; not mandatory and for convention
    INT 21H     
MAIN ENDP     

END MAIN
