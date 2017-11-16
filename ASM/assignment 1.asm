;1+2+3+4+5+.....+n

.model small
.stack 100h 
.data 
    a db 49
    b db 48
 
.code       
main proc
     mov ax,@data
     mov ds,ax
     
     
    mov ax,0
    mov cx,10  
      
      
    FOR: 
         add al, a 

         mov ah,0 ; initialize zero for rid of garbaze
         aaa      ; for large addition
            
         add ah,48
         add al,48   
         
         
         mov dl,bh
         add b, dl
         sub b,48   
         
         mov bx, ax     
         inc a   
    LOOP FOR 
     
    mov ah,2 
    add bh, b
    mov dl,bh
    int 21h
     
    mov ah,2
    mov dl,bl
    int 21h   
    
main endp
