;CREATED BY TURBOPRINTS

stack_segment SEGMENT STACK "stack"
	DB 32 DUP(0)
stack_segment ENDS

data_segment SEGMENT
	num DB '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
data_segment ENDS

function_segment SEGMENT
ASSUME SS:stack_segment, DS:data_segment, CS:function_segment
	write_func PROC FAR
		PUSH AX
		ADD DX, 2
		MOV AH, 09H
		INT 21H
		POP AX
		RET
	write_func ENDP

	read_func PROC FAR
		PUSH AX
		PUSH SI
		PUSH BX
		MOV BX, DX
		MOV SI, 0
	RFL_0:
		MOV AH, 01H		
		INT 21H
		CMP AL, 13
		JE RFL_1
		MOV BYTE PTR[BX + SI], AL
		INC SI
		JMP RFL_0
	RFL_1:		
		POP BX
		POP SI
		POP AX
		RET
	read_func ENDP

function_segment ENDS

code_segment SEGMENT
ASSUME SS:stack_segment, DS:data_segment, CS:code_segment
begin:
	MOV ax, data_segment
	MOV ds, ax

	PUSH DX
	LEA DX, num
	CALL read_func
	POP DX
	PUSH DX
	LEA DX, num
	CALL write_func
	POP DX

EXIT:
	MOV ah, 4Ch
	INT 21h

code_segment ENDS
END begin