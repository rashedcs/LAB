; Problem : input array from user

.MODEL SMALL
.STACK
.DATA
   ARR DB 10 DUB (?)     
   
.CODE
 MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    XOR BX, BX
    MOV CX, 5
    
    FOR: 
      MOV AH, 1
      INT 21H
      MOV ARR[BX], AL
      INC BX
    LOOP FOR
    
    
    XOR BX, BX
    MOV CX, 10 
    
    PRINT:  
     MOV AX, ARR[BX] ;point to the  current index 
     ;SUB AX, 48      ;for converting decimal value
        
     MOV AH, 2       ;output
     MOV DL, AX  
     INT 21H     
     
     INC BX           ;move pointer to the next element 
    LOOP PRINT       ;loop until done
     
    
 MAIN ENDP
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
     
     INC BX
     ;ADD BX, 1       ;move pointer to the next element 
     LOOP FOR        ;loop until done
  
MAIN ENDP
