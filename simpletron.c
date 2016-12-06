/*
	simpletron.c
	Andrew Hess
	12/6/2016
	A Simpletron computer
*/

#include <stdio.h>
#include <stdlib.h>

void dump (int acc, int instCount, int instReg, int opCode, int operand, int * mem);

int main() {
	// create the accumulator and memory
	int acc = 0;
	int * mem = malloc(100 * sizeof(mem));

	// create the other variables the simpletron will use
	int instCount = 0;
	int instReg = 0;
	int opCode = 0;
	int operand = 0;

	// start the computer
	printf("*** Welcome to Simpletron! ***\n");
	printf("*** Please enter your program one instruction ***\n");
	printf("*** (or data word) at a time. I will type the ***\n");
	printf("*** location number and a question mark (?).  ***\n");
	printf("*** You then type the word for that location. ***\n");
	printf("*** Type the sentinel -99999 to stop entering ***\n");
	printf("*** your program. ***\n");

	dump(acc, instCount, instReg, opCode, operand, mem);

	// read in the program from the user
	int inc = 0;
	int * wordptr = malloc(sizeof(wordptr));

	while (*wordptr != -99999) {
		printf("%02d ? ", inc++);
		scanf("%d", wordptr);
	
		if ((*wordptr < -9999 || *wordptr > 9999) && *wordptr != -99999) {
			pritnf("*** Invalid input ***\n");
			inc--;
		}
		else {
			mem[ind -1] = *wordptr;
		}
	}

	dump(acc, instCount, instReg, opCode, operand, mem);

	exit(0);
}

void dump (int acc, int instCount, int instReg, int opCode, int operand, int * mem) {
	printf("REGISTERS:\n");
	printf("accumulator		%04d\n", acc);
	printf("instructionCounter	%02d\n", instCount);
	printf("instructionRegister	%04d\n", instReg);
	printf("operationCode		%02d\n", opCode);
	pritnf("operand			%02d\n", operand);

	printf("\nMEMORY:\n\t");
	for (int i = 0; i < 10; i++) {
		printf("%d\t", i);
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\t", 10*i);
		for (int k = 0; i < 10; k++) {
			printf("%+04d\t", mem[10*i + k]);
		}
		printf("\n");
	}
}
		 
