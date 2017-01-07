/*
	friends.c
	Andrew Hess
	1/7/2017
	Read from, add to, and delete records from friends.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runCommand(char *, char);
void testStreamEnd(FILE *, FILE *);

int main() {
	char *filepath = "friends.txt";
	char command = 0;

	while (command != 'q') {
		printf("Enter 'a' to add a record.\nEnter 'm' to add multiple records.\nEnter 'd' to delete a record.\n");
		printf("Enter 'p' to print all records.\nEnter 'q' to quit.\n");

		do {
			command = getchar();
		}
		while (command == '\n');

		// go to the next line
		while (getchar() != '\n');

		// execute the appropriate command
		while (!(command == 'a' || command == 'm' || command == 'd' || command == 'p' || command == 'q')) {
			printf("Invalid command. Enter a command: ");
			command = getchar();
			while (getchar() != '\n') testStreamEnd(NULL, NULL);
		}
		
		if (command != 'q') {
			printf("\n");
			runCommand("friends.txt", command);
			printf("\n");
		}
	}

	exit(0);
}

void runCommand(char *filepath, char command) {
	char *mode = (command == 'a' || command == 'm') ? "a" : "r";
	FILE *in = fopen(filepath, mode);

	if (command == 'a' || command == 'm') {
		int repeat = -1;
		if (command == 'm') {
			while (repeat < 0) {
				printf("Enter the number of records to add: ");
				scanf("%d", &repeat);
				while (getchar() != '\n') testStreamEnd(in, NULL);
			}
		} else repeat = 1;

		while (repeat--) {
			char first[20] = {0};
			char last[20] = {0};
			int age = 0;
				
			printf("Enter a first name, last name, and age: ");
			int res = scanf("%s %s %d", first, last, &age);
			
			while (res != 3) {
				printf("Invalid input. Try again: ");
				res = scanf("%s %s %d", first, last, &age);

				if (getchar() == EOF) {
					printf("\n");
					fclose(in);
					exit(0);
				}
				while(getchar() != '\n');
			}

			fprintf(in, "%s %s %d\n", first, last, age);
		}
	} else {
		if (in == NULL) return;

		FILE *temp = NULL;
		char dFirst[20] = {0};
		char dLast[20] = {0};
		int dAge = -1;
		int found = 0;

		char first[20] = {0};
		char last[20] = {0};
		int age = -1;

		if (command == 'd') {
			temp = fopen("/tmp/temp.txt", "w+");
			
			printf("Enter the first name, last name, and age of the record you want to delete: ");
			int res = scanf("%s %s %d", dFirst, dLast, &dAge);

			while (res != 3) {
				testStreamEnd(in, temp);
				printf("Invalid input. Try again: ");
				res = scanf("%s %s %d", dFirst, dLast, &dAge);
			}
		}

		// read from the file
		while (fscanf(in, "%s %s %d", first, last, &age) == 3) {
			if (command == 'p') printf("%s %s %d\n", first, last, age);
			else {
				// if it is not the record to delete, write it to the temp file
				if (strcmp(first, dFirst) || strcmp(last, dLast) || age - dAge) {
					fprintf(temp, "%s %s %d\n", first, last, age);
				}
				else found = 1;
			}
		}

		if (command == 'd') {
			printf("%s %s %d was ", dFirst, dLast, dAge);
			found ? printf("deleted.\n") : printf("not found.\n");

			freopen("friends.txt", "w", in);
			
			// reset the file position indicator to the beginning of the stream
			rewind(temp);

			// copy temp to in
			int res = fscanf(temp, "%s %s %d", first, last, &age);
			while (res != EOF) {
				if (res == 3) fprintf(in, "%s %s %d\n", first, last, age);
				else printf("An error occurred while trying to delete the record.\n");

				res = fscanf(temp, "%s %s %d", first, last, &age);
			}
			
			fclose(temp);
		}
	}

	fclose(in);
}

void testStreamEnd(FILE *f1, FILE *f2) {
	if (getchar() == EOF) {
		printf("\n");

		fclose(f1);
		fclose(f2)
;
		exit(0);
	}
}
