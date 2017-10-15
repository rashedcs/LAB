; problem : Find a = c+d and b = 2a


.MODEL SMALL 
.STACK 100H 

.DATA 
A DW ? 
B DW ? 
C DW ? 
D DW ? 

.CODE 
MAIN PROC 

MOV AX, @data ; initialization of variable 
MOV DS, AX 

MOV AH, 01 ; input number 
INT 21H 
MOV C, AL 

MOV AH, 01 ; input number 
INT 21H 
MOV D, AL 

MOV AX, C 
ADD AX, D 

MOV A, AX 

MOV AH, 2 
MOV DL, A 
SUB DL, 48 
INT 21H 

ADD AX, AX 
MOV B, AX 

MOV AH, 2 
MOV DL, B 
SUB DL, 48 
INT 21H 



MOV AH, 4CH 
INT 21H 
MAIN ENDP  
