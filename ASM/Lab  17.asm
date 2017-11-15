; Check the number is either prime or not


.MODEL  SMALL
    .DATA
           num      DB     ?
           INPUT    DB     0AH,0DH,'ENTER NO:','$'
           MSG1     DB     0AH,0DH,'IT IS NOT PRIME','$'
           MSG2     DB     0AH,0DH,'IT IS PRIME','$'

           .CODE
    MAIN    PROC

            MOV AX,@DATA
            MOV DS,AX

            LEA DX, INPUT
            MOV AH,09H
            INT 21H
    
            MOV AH,1
            INT 21H
            SUB AL,30H
            MOV num, AL
            
            MOV AH,00
            MOV CL,2
            DIV CL
            MOV CL,AL

    FOR:
            CMP CL, 1                                            ; compare if the CL value is 1.
            JBE PRIME                                            ; Jump if CL=1 or CL=0.
        
            MOV AH,00                                           ; clear AH.
            MOV AL, num                                         ; move the value in VAL1 to AL.
            DIV CL                                              ; divides the loop.
            CMP AH,00                                           ; check if AH is 0.
            JZ NONPRIME                                          ; (Jump if Zero) if CMP returns false, jump to LBL2, else continue.
           
            DEC CL                                              ; decrea8se the value by 1.
            JMP FOR                                            ; jump to LBL1.
       
   
                
    NONPRIME :   
            MOV AH,09H
            LEA DX, MSG1
            INT 21H
            JMP EXIT  
   
    
    PRIME:
            MOV AH,09H
            LEA DX, MSG2
            INT 21H   
            JMP EXIT
    
    EXIT:
            MOV AH,4CH
            INT 21H
    
    MAIN    ENDP
            END     MAIN
    

;Daught : https://ideone.com/TnuXU1
