;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 32 DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB 0
	i DB 0
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

L_0:
	ADD num, 1
	INC 10
	MOV BX, i
	CMP BX, 10
	JE L_1
	JMP L_0

L_1:
	SUB i, 10

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin