; Problem : Write a program to traverse the array 

.MODEL SMALL   

.STACK 100H  

.DATA
    ARR DB 2, 3, 6, 7  
    
 
.CODE
MAIN PROC
     MOV AX, @DATA  ; initilization of data segment
     MOV DS, AX         
  
     XOR AX, AX
     XOR BX, BX
     MOV CX, 4
  
  
  FOR:  
         
     MOV AH, 2
     MOV DL, ARR[BX]  
     ADD DL, 48  
     INT 21H
     ADD BX, 1  
     LOOP FOR
  

MAIN ENDP
