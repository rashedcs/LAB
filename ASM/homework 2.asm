;Problem Name : Write a program to add integer number 
; input : 2 7
; Output : SUM OF 2 AND 7 is 9

.MODEL SMALL
.STACK 100H
 
 .DATA
 var1 DW ?  
 var2 DW ?
 MSG DB "SUM OF $" 
 BOTH DB " AND $"  
 IS   DB " IS $"
         
         
.CODE
MAIN PROC             
     MOV AX, @DATA  ; initialization of data segment
     MOV DS, AX       
                      
                          
     MOV AH, 1      ; input  var1 and var2
     INT 21H
     MOV var1, AL 
     INT 21H   
     MOV var2, AL
    
  
     MOV BL, var1
     MOV CL, var2
    
         
     ADD BL, CL     ; addition of var1 and var2   
     SUB BL, 48     ; For returing decimal value        
             
             
             
     MOV AH, 2                    ; carriage return
     MOV DL, 0DH               
     INT 21H                           
     
     MOV DL, 0AH                  ; line feed
     INT 21H
         
         
    
     LEA DX,MSG                        
     MOV AH,09H                     
     INT 21H       
     
     
     MOV AH, 2      
     MOV DL, var1
     INT 21H
         
       
     LEA DX,BOTH                     
     MOV AH,09H                     
     INT 21H     
             
          
     MOV AH, 2      
     MOV DL, var2
     INT 21H      
     
     
     LEA DX,IS                     
     MOV AH,09H                     
     INT 21H  
               
                  
   
     MOV AH, 2      ; output
     MOV DL, BL
     INT 21H
    
        
     MOV AH, 4CH    ; not mandatory and for convention
     INT 21H                    
    
 MAIN ENDP     

END MAIN
