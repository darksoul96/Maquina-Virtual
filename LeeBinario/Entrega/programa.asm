XOR FX,FX
MOV [2],0
MOV AX,%0001
MOV DX,1
MOV CX,1
OTRO: SYS 1
CMP [1],0
JN SIGUE
ADD [2],[1]
ADD FX,1
JMP OTRO
SIGUE: CMP 0,FX
JZ FIN
DIV [2],FX
FIN: MOV DX,2
SYS 2
STOP