;CREATED BY TURBOPRINTS

stack_segment segment stack "stack"
	db 256 DUP(0)
stack_segment ends

data_segment segment
	name db 'lol'
	sizez db 0
data_segment ends

code_segment segment
assume ss:stack_segment, ds:data_segment, cs:code_segment
begin:
code_segment ends
end begin