; Problem : Addition two digit. if sum is greater than 9
;Copied


.model small
.stack 100h
.data

       msg db "Enter 1st number: $" 
       msg2 db 10,13, "Enter 2nd number: $"
       msg3 db 10,13, "Sum=: $"
       
       
       a db 0
       b db 0
       c db 0
       
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
