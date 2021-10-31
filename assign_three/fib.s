;Fibonacci
	
	AREA     fibonacci, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg
		
	ENTRY 

__main FUNCTION
		MOV R9, #06			; printing fibonacci numbers
		MOV R0, #00			
		BL printMsg			; printing first number
		MOV R0, #01
		BL printMsg			; printing second number
		MOV R1, #00			
		MOV R2, #01

loop1    CMP R9, #00
		BLE stop       

		MOV R7, R2			
		ADD R2, R2, R1
		MOV R6, R2
		MOV R0, R2
		BL printMsg			; printing subsequent numbers
		MOV R2, R6
		MOV R1, R7
		SUB R9, #01
		B loop1         

stop B stop 		; stop program
	ENDFUNC
	
	END