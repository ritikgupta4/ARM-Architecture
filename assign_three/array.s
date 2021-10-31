	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY


__main  FUNCTION
	MOV R0, #0x20000000
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

	

L1		ADD R0,R0,#0x4
        LDR R3,[R0] ;get next data
		CMP R2,R3
		BGT L2
		MOV R2,R3  ;R2 = R3 as R3 is larger
		
L2   	SUBS R1,R1,#01  ;Decrement the Counter
		CMP R1,#00
		BNE L1
		MOV R0,R2
		BL printMsg
stop    B stop ; stop program
	 ENDFUNC
	 END