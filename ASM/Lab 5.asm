;Problem : Write a program to check the odd or even number 

.MODEL SMALL
.STACK 100H   

.DATA
 even db "even number $"
 odd  db "odd number $"
 
 
.CODE  
 MAIN PROC     
    
 MOV AX, @data ; initialization of variable
 MOV DS, AX   
  
 MOV AH, 01 ; input number
 INT 21H
 MOV DL, Al     
 
 MOV BL, 2
 DIV BL
 
 CMP AH, 0
 JNE SECOND
 
 FIRST : 
         LEA DX, even
         MOV AH, 09 
         INT 21H
         JMP EXIT
 
 SECOND:
         LEA DX, ODD
         MOV AH, 09
         INT 21H
   
    
 EXIT:
         MOV AH, 4CH
         INT 21H  
          MAIN ENDP
 END MAIN
