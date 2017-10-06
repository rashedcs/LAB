;Problem : Write a program to sum of series 
; series : 1+4+7+.......
; Count
; (first term - las term)/difference 

.MODEL SMALL   
.STACK 100H  

.DATA
 SUM DB ?
  
.CODE         
MAIN PROC    
    
  MOV AX, @DATA  ; initialization of data segment
  MOV DS, AX        
    
           
  MOV AX, 1
  MOV BX, 1          
  MOV CX, 10 
  
  
  FOR:  
     ADD BX, 3
     ADD AX, BX
   LOOP FOR
      
     
     ;ADD AX, 48
     MOV SUM, AX  
     
    
     MOV AH, 2           ;output
     MOV DL, SUM  
     INT 21H   
     

     MOV AH, 4CH       
     INT 21H     

MAIN ENDP
