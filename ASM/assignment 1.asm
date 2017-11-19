;1+2+3+4+5+.....+n
;Problem 1 : Write a program to sum of natural numbers
;series : 1+2+3+......+n
; Count
; (first term - las term)/difference 

;Source Code
.MODEL SMALL
.STACK  
.DATA
 b db ?
.CODE
MAIN PROC
MOV AX, 0 
MOV CX, 10

FOR: 
ADD AX, CX
LOOP FOR  

MOV BX, 10    

DIV BX
MOV b, DX


 MOV AH,2
 MOV DL, AX 
 ADD DL, 48
 INT 21H  
      
        
 MOV AH,2
 MOV DL, b   
 ADD DL, 48
 INT 21H

MAIN ENDP
