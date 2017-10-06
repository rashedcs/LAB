; Problem : Write a program to traverse the array 

.MODEL SMALL   

.STACK 100H  

.DATA
    ARR DB 2, 3, 6, 7  
    
 
.CODE
MAIN PROC 
    
     MOV AX, @DATA   ;initilization of data segment
     MOV DS, AX         
              
              
     XOR AX, AX      ;clear ax register
     XOR BX, BX      ;clear base register
     MOV CX, 4       ;number of elements
  
  
  FOR:  
     MOV AX, ARR[BX] ;point to the  current index 
     ADD AX, 48      ;for converting decimal value
        
     MOV AH, 2       ;output
     MOV DL, AX  
     INT 21H     
     
     ADD BX, 1       ;move pointer to the next element 
     LOOP FOR        ;loop until done
  
MAIN ENDP
