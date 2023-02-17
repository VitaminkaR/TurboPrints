;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 16 DUP(0)
stack_segment ENDS

data_segment SEGMENT
	var DW 25
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	MOV AX, var
	MOV BX, 2
	IMUL BX
	MOV var, AX
	MOV AX, var
	MOV BX, 10
	IDIV BX
	MOV var, AX
	MOV AX, var
	MOV BX, 3
IDIV BX
	MOV var, DX

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin