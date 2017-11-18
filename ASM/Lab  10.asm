.model small
.stack 100h
.data
 var1 db ?  
 var2 db ? 
 str db 0ah,0dh,'sum: $'      
.code
main proc             
    mov ax, @data  ; initialization of data segment
    mov ds, ax       
                       
    mov ah, 1      ; input  var1 and var2
    int 21h
    mov var1, al  
    int 21h   
    mov var2, al
   
    add bl, var1        
    add bl, var2         
    
    mov al, bl           ;
    mov ah,0          
    aaa               
    
    mov bx,ax          
    add bh,30h
    add bl,30h
                       
    mov ah,9
    lea dx,str
    int 21h

    mov ah,2
    mov dl,bh       ;showing sum 
    int 21h  
   
    mov ah,2
    mov dl,bl
    int 21h   
 main endp     
