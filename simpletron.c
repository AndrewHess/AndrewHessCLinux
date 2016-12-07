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

	// read in the program from the user
	int inc = 0;
	int * wordptr = malloc(sizeof(wordptr));

	while (*wordptr != -99999) {
		printf("%02d ? ", inc++);
		scanf("%d", wordptr);
	
		if ((*wordptr < -9999 || *wordptr > 9999) && *wordptr != -99999) {
			printf("*** Invalid input ***\n");
			inc--;
		}
		else if (*wordptr != -99999) {
			mem[inc -1] = *wordptr;
		}
	}

	dump(acc, instCount, instReg, opCode, operand, mem);

	exit(0);
}

void dump (int acc, int instCount, int instReg, int opCode, int operand, int * mem) {
	printf("\nREGISTERS:\n");
	printf("accumulator		%+05d\n", acc);
	printf("instructionCounter	%+03d\n", instCount);
	printf("instructionRegister	%+05d\n", instReg);
	printf("operationCode		%+03d\n", opCode);
	printf("operand			%+03d\n", operand);

	printf("\nMEMORY:\n\t");
	for (int i = 0; i < 10; i++) {
		printf("%d\t", i);
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\t", 10*i);
		for (int k = 0; k < 10; k++) {
			printf("%+05d\t", mem[10*i + k]);
		}
		printf("\n");
	}
	printf("\n");
}
		 
