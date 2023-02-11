;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB  DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB 0
data_segment ENDS

code_segment SEGMENT
ASSUME ss:stack_segment, ds:data_segment, cs:code_segment
begin:
ADD num, 2
ADD num, 5
ADD num, 1
code_segment ENDS
END begin