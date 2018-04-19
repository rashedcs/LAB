.MODEL SMALL
.STACK 2000
.DATA
                                                                                                                                                                                      


MSGA DB 13,10,"Input first number: ","$"
MSGB DB 13,10,"Input second number: ","$"
MSGC DB 13,10,"The quotient is: ","$"
MSGD DB 13,10,"The modulo is: ","$"

NUM1 db ?
NUM2 db ?

.CODE

MAIN PROC NEAR

MOV AX, @DATA
MOV DS, AX

; get first number
LEA DX, MSGA
MOV AH, 09h
INT 21h

MOV AH, 01
INT 21H
SUB AL, '0'

MOV BL, AL

; get second number
LEA DX, MSGB
MOV AH, 09h
INT 21h

MOV AH, 01
INT 21H
SUB AL, '0'

MOV CL, AL

; divide
MOV AH, 0 ; prepare dividend
MOV AL, BL
DIV CL
MOV NUM1, AL
ADD NUM1, '0'
MOV NUM2, AH
ADD NUM2, '0'

; output quotient
LEA DX, MSGC
MOV AH, 09h
INT 21h

MOV DL, NUM1
MOV AH, 02H
INT 21h

; output remainder/modulo
LEA DX, MSGD
MOV AH, 09h
INT 21h

MOV DL, NUM2
MOV AH, 02H
INT 21h

MOV AH, 4Ch
INT 21h

MAIN ENDP
END MAIN
