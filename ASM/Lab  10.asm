.model small
.stack
.data
a db "enter the first number : $"
b db "enter the second number: $"
d db "sum is=$" 


.code

mov ah,01h
int 21h
mov bl,al 
  


mov ah,01h
int 21h  


mov ah,00h
add al,bl  


aaa
mov bl, al
mov bh, ah  
   

;mov dl, bh
;add dl,30h 

       
MOV ah, 2
add bh, 48
MOV dl, bh
INT 21H      
    
        
mov ah,02 
add bl, 48
mov dl,bl  
int 21h


.exit
end













.code

       mov ax,@data
       mov ds,ax
       
       mov ah,9
       lea dx,msg
       int 21h
       
       mov ah,1 
       int 21h
       sub al,48
       mov a,al
       
       mov ah,9
       lea dx,msg2
       int 21h
       
       mov ah,1
       int 21h
       sub al,48
       mov b,al
       
       add al,a
       mov ah,0
       aaa
       
       add ah,48
       add al,48
       
       mov bx, ax
       
       mov ah,9
       lea dx,msg3
       int 21h
       
       mov ah,2
       mov dl,bh
       int 21h
       
       mov ah,2
       mov dl,bl
       int 21h
                
       ret
