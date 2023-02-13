;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 32 DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB 3
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	MOV BX, num
	CMP BX, 5
	je L_0
tjmp L_1

L_0:
	SUB num, 2
	jmp L_2

L_1:
	ADD num, 3
	SUB num, 2

L_2:
	ADD num, 6

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin