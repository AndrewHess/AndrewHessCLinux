/*
	simpletron.c
	Andrew Hess
	12/6/2016
	A Simpletron computer
*/

#include <stdio.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void dump (int acc, int instCount, int instReg, int opCode, int operand, int * mem);
void error (int acc, int instCount, int instReg, int opCode, int operand, int * mem);

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

	// start running the sml program
	int running = 1;
	while (running) {
		// put the next instruction into the register
		instReg = mem[instCount];

		// get opCode and operand
		opCode  = instReg / 100;
		operand = instReg % 100;

		// do the correct command
		switch (opCode) {
			case READ:
				printf("Enter a number: ");
				scanf("%d", mem + sizeof(int)*operand);
				printf("Done reading\n");
				break;
			case WRITE:
				printf("%d\n", mem[operand]);
				break;
			case LOAD:
				acc = mem[operand];
				break;
			case STORE:
				mem[operand] = acc;
			case ADD:
				acc += mem[operand];
			case SUBTRACT:
				acc -= mem[operand];
			case DIVIDE:
				if (mem[operand] == 0) {
					printf("*** Divide by zero ***\n");
					error(acc, instCount, instReg, opCode, operand, mem);
				}
				else {
					acc /= mem[operand];
				}
				break;	
			case MULTIPLY:
				acc *= mem[operand];
				break;
			case BRANCH:
				instCount = operand -1;
				break;
			case BRANCHNEG:
				if (acc < 0) {
					instCount = operand -1;
				}
				break;
			case BRANCHZERO:
				if (acc == 0) {
					instCount = operand -1;
				}
				break;
			case HALT:
				running = 0;
				break;
			default:
				printf("*** Unknown command: %02d ***\n", opCode);
				running = 0;
				error(acc, instCount, instReg, opCode, operand, mem);
		}

		instCount++;
	}

	dump(acc, instCount, instReg, opCode, operand, mem);

	exit(0);
}

void dump (int acc, int instCount, int instReg, int opCode, int operand, int * mem) {
	printf("\nREGISTERS:\n");
	printf("accumulator		%+05d\n", acc);
	printf("instructionCounter	%02d\n", instCount);
	printf("instructionRegister	%+05d\n", instReg);
	printf("operationCode		%02d\n", opCode);
	printf("operand			%02d\n", operand);

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

void error (int acc, int instCount, int instReg, int opCode, int operand, int * mem) {
	printf("*** Simpletron execution abnormally terminated ***\n");
	dump(acc, instCount, instReg, opCode, operand, mem);
}
