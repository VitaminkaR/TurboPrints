;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 32 DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB 10
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	MOV AX, num
	IMUL 10
	MOV num, AX

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin