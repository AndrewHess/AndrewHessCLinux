/*
	pointers.c
	Andrew Hess
	11/2/2016
	The user enters a number. Create a pointer for that number and 
	allow the user to find the pointer value, pointer address, and
	integer value
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num = 0;
	int * ptr;
	ptr = &num;

	int done = 0;
	while (!done) {
		printf("Enter a integer: ");
		scanf("%d", ptr);
		getchar();
		
		printf("Enter 1 to get the pointer value\n");
		printf("Enter 2 to get the pointer address\n");
		printf("Enter 3 to get the integer value\n");
	
		char input = getchar();
		while (getchar() != '\n');

		switch (input) {
			case '1':
				printf("Pointer value: %p\n", ptr);
				break;
			case '2':
				printf("Pointer address: %p\n", &ptr);
				break;
			case '3':
				printf("Integer value: %d\n", *ptr);
				break;
			default:
				printf("Invalid option\n");
		}

		printf("Continue? (y/n): ");
		input = getchar();
		while (getchar() != '\n');

		if (input == 'n' || input == 'N') done = 1;
	}

	exit(0);
}
