 ; EQUIVALENCIAS USADAS PARA LA ESTRUCTURA DE MATRIZ
 COLFILJUEGO   EQU 4
 TOTALCELDAS   EQU COLFILJUEGO*COLFILJUEGO 

 ;EQUIVALENCIAS DE COORDENADAS PARA PINTAR EN PANTALLA (FIL, COL)  
 FILMSJMODO    EQU 20  ; posicion msj modo inicial (DEMO o Juego) 
 COLMSJMODO    EQU 5 

 FILMSJPOT     EQU 22   ; posicion msj numero tope con el que jugar
 COLMSJPOT     EQU 5 

 FILENTPOT     EQU FILMSJPOT   ; posicion para pedir el numero tope con el que jugar
 COLENTPOT     EQU COLMSJPOT+60 

 FILPANTALLAJ  EQU 3   ; posicion para imprimir pantTablero
 COLPANTALLAJ  EQU 5
  
 FILMSJGNRAL   EQU 20  ; posicion msjs introduce un comando, ganar, perder y salir 
 COLMSJGNRAL   EQU 5    
 
 FILMSJINTR    EQU FILMSJGNRAL  ; posicion introducir comando (A,S,D,W,E,O)
 COLMSJINTR    EQU COLENTRADA+28  
 
 FILINICIOTAB  EQU 7   ; posicion contenido 1ra celda del tablero
 COLINICIOTAB  EQU 16  
 
 FILENTRADA    EQU FILMSJGNRAL  ; posicion de la peticion de cadena al usario
 COLENTRADA    EQU COLMSJGNRAL+5  
  

data segment  
   ;La estructura a usar es una matriz 4x4 
   TableroJuego      dw TOTALCELDAS dup(0) ;contien los datos del momento actual
   TableroJuegoDebug dw 2,2,2,2,4,0,4,2,8,2,0,8,4,2,2,0  ;matriz con datos precargados
   
   fil       db ? ; para ColocarCursor
   col       db ? 

   colMatrizJuego db ? ; para VectorAMatriz y MatrizAVector
   filMatrizJuego db ?            
   posMatrizJuego db ? 
   
   tope      dw ? ; valor maximo hasta el que se jugara 
      
   ;**************************CADENAS ********************************
   cad       db 5 dup(?)  ;para almacenar el numero de una celda tras convertirlo a cadena
   cadVacia  db "     $"  ;para borrar el numero de una celda
   cadTope db 7 dup ('$')    
         
   ;Mensajes de Interfaz                      
   msjModo    db "Entrar al juego en modo Debug (tablero precargado) o NO? (S/N)$"  
   msjIntPot  db "Introduce un valor potencia de 2, entre 16 y 2048 (incls.): $"  
   msjIntEnt  db "Introduce comando Entrada >> $"
    
   msjPartidaGanada      db "...ENHORABUENA! ... Has ganado la partida!  ;-)  $" 
   msjPartidaPerdida     db "...LO SIENTO!... Has perdido! ;-(  $"
   msjPartidaFinalizada  db " ...Juego finalizado...Hasta pronto $"                                                                         
   PantallaInicio DB 10, 13, 10  
DB " 222222222222222         000000000            444444444       888888888      ",10, 13
DB "2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88    ",10, 13
DB "2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88  ",10, 13
DB "2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8 ",10, 13
DB "            2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8 ",10, 13
DB "            2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8 ",10, 13
DB "         2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8  ",10, 13
DB "    22222::::::22   0:::::0     0:::::04::::444444::::444  8:::::::::::::8   ",10, 13
DB "  22::::::::222     0:::::0     0:::::04::::::::::::::::4 8:::::88888:::::8  ",10, 13
DB " 2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8 ",10, 13
DB "2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8 ",10, 13
DB "2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8 ",10, 13
DB "2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8 ",10, 13
DB "2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88  ",10, 13
DB "2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88    ",10, 13
DB "22222222222222222222     000000000             4444444444     888888888      ",10, 13, "$"
;
  
   pantTablero db "                                                     COMANDOS ",10,13
               db "                 1      2     3     4   " ,10,13
               db "               ³_____³_____³_____³_____³           Desplazar Dcha   :D",10,13
               db "               ³     ³     ³     ³     ³" ,10,13
               db "             A ³     ³     ³     ³     ³" ,10,13         
               db "               ³_____³_____³_____³_____³           Desplazar Izq.   :A",10,13
               db "               ³     ³     ³     ³     ³" ,10,13
               db "             B ³     ³     ³     ³     ³" ,10,13         
               db "               ³_____³_____³_____³_____³           Desplazar Abajo  :S",10,13
               db "               ³     ³     ³     ³     ³" ,10,13
               db "             C ³     ³     ³     ³     ³" ,10,13
               db "               ³_____³_____³_____³_____³           Desplazar Arriba :W",10,13
               db "               ³     ³     ³     ³     ³" ,10,13
               db "             D ³     ³     ³     ³     ³" ,10,13
               db "               ³_____³_____³_____³_____³           Otro Juego       :O",10,13          
               db "                                                   Salir            :E",10,13,'$'
data ends


code segment
;*************************************************************************************                                                                                                                        
;************************ procedimientos dados ***************************************                                                                                                                        
;*************************************************************************************                                                                                                                        

  ;F: Calcula un valor aleatorio entre 0 y un valor maximo dado-1
  ;E: BL valor maximo (1...100)
  ;S: AH valor aleatorio calculado (0...BL-1) par y AL pierde su valor
  NumAleatorio proc
    push cx
    push dx

    mov ah, 2Ch ;interrupcion que recupera la hora actual del sistema operativo
    int 21h
    ;ch=horas cl=minutos dh=segundos dl=centesimas de segundo, 1/100 secs

    xor ah, ah
    mov al, dl  
    div bl 
        
    finale:
    pop dx
    pop cx
    ret
  NumAleatorio endp  


  ;F: Imprime una cadena terminada en $ en la posicion donde se encuentre el cursor 
  ;E: DX direccion de comienzo de la cadena a imprimir    
  ImprimirCadena proc
    push ax

    mov ah, 9
    int 21h

    pop ax
    ret
  ImprimirCadena endp 


  ;F: Lee una cadena por teclado
  ;E: DX contiene la direccion de la cadena donde se almacenar  la cadena leida                        
  ;E: la posicion 0 de esa cadena debe contener el numero maximo de caracteres a leer
  LeerCadena proc
    push ax

    mov ah, 0ah
    int 21h

    pop ax
    ret
  LeerCadena endp

 
  ;Convierte una cadena de caracteres a un numero entero 
  ;E: DX contiene la direccion de la cadena a convertir (terminada en 13 o '$')
  ;S: AX contiene el resultado de la conversion
  CadenaANumero proc
    push bx
    push cx
    push dx ; cambia con MUL de 16bits
    push si 
    push di
    
    mov si, dx
    xor ax, ax    
    mov bx, 10  
    
    cmp [si], '-'
    jne BCadNum
    
    mov di, si  ;Ajustes si viene un '-' como primer caracter
    inc si

   BCadNum:
    mov cl, [si]          ;Controles de fin
    cmp cl, 13
    je compruebaNeg
    cmp cl, '$'
    je compruebaNeg
    
    mul bx
    sub cl, '0'
    xor ch, ch
    add ax, cx
    inc si     
    jmp BCadNum
        
   compruebaNeg:   
    cmp [di], '-'
    jne finCadenaANumero
    neg ax
   
   finCadenaANumero:
    pop di
    pop si
    pop dx
    pop cx
    pop bx
    ret
  CadenaANumero endp
 
 
  ;Convierte un numero entero a una cadena de caracteres terminada en $
  ;E: AX contiene el numero a convertir
  ;E: DX contiene la direccion de la cadena donde almacena la cadena resultado
  NumeroACadena proc 
    push ax
    push bx
    push cx
    push dx
    push di
    
    mov bx, 10
    mov di, dx
    
    xor cx, cx

    cmp ax, 0  
    jge BNumCad

    mov [di], '-'
    inc di 
    neg ax
    
   BNumCad:        ;Bucle que transforma cada digito a caracter, de menor a mayor peso     
    xor dx, dx
    div bx
    add dl, '0'
    push dx 
    inc cx
    cmp ax, 0
    jne BNumCad

   BInvertir:      ;Bucle para invertir los restos    
    pop [di]
    inc di
    loop BInvertir

    mov [di], '$'

    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    ret
  NumeroACadena endp 

                                              
  ;F: coloca el cursor en una determinada fila y colum de pantalla
  ;E: las variables fila y colum deben contener los valores de posicionamiento
  ColocarCursor proc
    push ax
    push bx
    push dx

    mov ah, 2
    mov dh, fil
    mov dl, col
    xor bh, bh
    int 10h

    pop dx
    pop bx
    pop ax
    ret         
  ColocarCursor endp                                                                                                   


  ;F: Borra la pantalla (la deja en negro)
  BorrarPantalla proc
    push ax
    push bx
    push cx
    push dx

    mov ah, 6h
    xor al, al
    mov bh, 7
    xor cx, cx
    mov dh, 24
    mov dl, 79
    int 10h 

    pop dx
    pop cx
    pop bx
    pop ax
    ret
  BorrarPantalla endp 

  
  ;F: Lee un caracter por teclado con/sin eco por pantalla
  ;S: AL caracter ASCII leido
  LeerTeclaSinEco proc  
    mov ah,8 ;1 para que sea con eco
    int 21h
     ret  
  LeerTeclaSinEco endp    
  

;*************************************************************************************                                                                                                                        
;****************** procedimientos implementados en clase ****************************                                                                                                                        
;************************************************************************************* 



                                                
;*************************************************************************************                                                                                                                        
;*****************     procedimientos implementados fuera de clase   *****************
;*************************************************************************************                                                                                                                        
 


;************************ PROGRAMA PRINCIPAL ***************
principal:
    mov ax, data
    mov ds, ax         
      

              
    mov ah, 4ch
    int 21h        
 ends 
end principal   
     