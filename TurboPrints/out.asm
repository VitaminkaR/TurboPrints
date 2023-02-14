;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB  DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB 5
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	MOV BX, num
	CMP BX, 5
