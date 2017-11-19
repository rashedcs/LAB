; problem : Find a = c+d and b = 2a


.MODEL SMALL 
.STACK 100H 

.DATA 
A DB ? 
B DB ? 
C DB ? 
D DB ? 

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
 
 
 
MOV AL, C 
ADD AL, D 

MOV A, AL 

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
