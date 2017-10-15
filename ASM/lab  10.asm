


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
