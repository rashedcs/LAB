;Problem 1 : Write a program to sum of natural numbers
;series : 1+2+3+......+n
; Count
; (first term - las term)/difference 


;Source Code
.MODEL SMALL
.STACK
.CODE
MAIN PROC
MOV AX, 0 
MOV CX, 5

FOR: 
ADD AX, CX
LOOP FOR      

MOV AH,00H
AAA           

MOV BL, AL
MOV BH, AH

MOV AH, 02
ADD BH, 48
MOV DL, BH
INT 21H     

MOV AH, 02 
ADD BL, 48
MOV DL, BL 
INT 21H  

MAIN ENDP








;Problem 2 : Write a program to sum of series 
; series : 1+4+7+.......
; Count
; (first term - las term)/difference 

;Source Code
.MODEL SMALL   
.STACK 100H  

.DATA
 SUM DW ?
  
.CODE         
MAIN PROC    
    
  MOV AX, @DATA  ; initialization of data segment
  MOV DS, AX        
    
           
  MOV AX, 1
  MOV BX, 1          
  MOV CX, 1 
  
  
  FOR:  
     ADD BX, 3
     ADD AX, BX
   LOOP FOR
      
     
     ADD AX, 48
     MOV SUM, AX  
     
     
    
     MOV AH, 2           ;output
     MOV DL, SUM  
     INT 21H   
     

     MOV AH, 4CH       
     INT 21H     

MAIN ENDP
