; Problem : Write a code to find the summation of 1D array 

















.MODEL SMALL
.STACK 100H
.DATA
arr db 25, 25, 25
Total dw ?       

.code
Main proc
MOV AX, @DATA  ; initialization of data segment
MOV DS, AX   

MOV AX, 0
MOV SI, 0
MOV CX, 3


sum:
ADD AL, arr[SI]
INC SI
LOOP sum

      
 
 MOV AH, 2      ;output  
 ADD AL, 48   
 MOV DL, AL
 INT 21H
    
        
 MOV AH, 4CH    ; not mandatory and for convention
 INT 21H     
    
End Main
