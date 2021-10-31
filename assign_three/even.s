;Even Odd	
	AREA even, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION
	MOV R0, #0x20000000
    MOV R2, #01          ; Storing 0x01 for AND operation
	MOV R5, #05				; size of array
	MOV R7, #06
	
LOOP1	SUBS R5, R5, #01
		STR R7, [R0]
		ADD R7, #01
		ADD R0, #04
		CMP R5, #00
		BNE LOOP1

		MOV R0, #0x20000000
		LDR R1, [R0]
		MOV R5, #05

LOOP	TST R1, R2
		BNE INCR
		ADD R12, #01
INCR	ADD R0, #04
		LDR R1, [R0]
		SUBS R5, R5, #01
		CMP R5, #00
		BNE LOOP
		MOV R0, R12
		BL printMsg
stop	B stop
		ENDFUNC
		END