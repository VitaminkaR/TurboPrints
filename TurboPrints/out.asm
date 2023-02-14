;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 32 DUP(0)
stack_segment ENDS

data_segment SEGMENT
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	MOV BX, 
	CMP BX, 
	je L_0
	jmp L_1

L_0:
	ADD , 
	jmp L_2

L_1:
	SUB , 

L_2:

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin