; Problem : check the number is either positive or negtive


;Problem : Write a program to check the odd or even number 

.MODEL SMALL
.STACK 100H   

.DATA
 str1  db "positive number $"
 str2  db "negative number $"
 
 
.CODE  
 MAIN PROC     
    
 MOV AX, @data ; initialization of variable
 MOV DS, AX   
  
 MOV AH, 01 ; input number
 INT 21H
 MOV DL, AL     
 
 
 ; CMP AL, 0 
 ; JZ ZERO  
 ; JG POSTIVE
 ; JL NEGATIVE
 
 SHL AX, -1
 JC  NEGATIVE   

 
 
POSITIVE : 
         LEA DX,  str1
         MOV AH, 09 
         INT 21H
         JMP EXIT
 
NEGATIVE:
         LEA DX,  str2
         MOV AH, 09
         INT 21H
   
    
 EXIT:
         MOV AH, 4CH
         INT 21H  
          MAIN ENDP
 END MAIN    
 
 
 ;Take the ith number in any of the registers.  
 ;And rotate it left throughout carry. 
 ;The status of carry flag, for example the most significant bit of the number will give 
 ;the information regarding the sign of the number. 
 ;If CF is 1, the number is negative; or else, it is positiv
