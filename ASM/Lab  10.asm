
.model small
.stack 100h
.data
    a db ?
    b db ?

.code
main proc
    mov ah,1
    int 21h          
    mov a,al
    
    mov ah,1
    int 21h
    mov b,al
    
    add al,a           ;
    mov ah,0          
    aaa               
    
    mov bx,ax          
    add bh,30h
    add bl,30h
    
    mov ah,2
    mov dl,0ah          ;
    int 21h
    mov dl,0dh
    int 21h

    
    mov ah,2
    mov dl,bh           ;showing sum 
    int 21h  
    
    mov ah,2
    mov dl,bl
    int 21h
    

main endp
