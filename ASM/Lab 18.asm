;Declaration Part
.MODEL SMALL
.DATA
RES DB ?
CNT DB 0AH       ; Initialize the counter for the no of Fibonacci No needed
.CODE
START: MOV AX,@DATA
MOV DS,AX
LEA SI,RES
MOV CL,CNT       ; Load the count value for CL for looping
MOV AX,00H       ; Default No
MOV BX,01H       ; Default No

;Fibonacci Part
L1:ADD AX,BX
DAA              ; Used to Present the value in Decimal Form
MOV [SI],AX
MOV AX,BX
MOV BX,[SI]
INC SI
LOOP L1

INT 3H           ; Terminate the Program
END START

