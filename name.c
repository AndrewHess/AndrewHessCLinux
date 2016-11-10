/*
	name.c
	Andrew Hess
	11/8/2016
	Uses character array to read user's name. Print the number of 
	characters in the name. Dispaly the name in uppercase and 
	lowercase. Append "man" to the end of the name and print the 
	new name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
	char name[100] = {0};
	char copy[100] = {0};
	char *str;
	char *copystr;
	str = name;
	copystr = copy;

	printf("Enter your name: ");
	scanf("%s", str);
	
	strcpy(copystr, str);
	printf("Your name has %d characters\n", strlen(name));

	// display uppercase name
	for (int i = 0; i < strlen(name); i++) {
		copy[i] = toupper(copy[i]);
	}
	printf("Your name in uppercase: %s\n", copystr);

	// display lowercase name
	for (int i = 0; i < strlen(name); i++) {
		copy[i] = tolower(copy[i]);
	}
	printf("Your name in lowercase: %s\n", copystr);

	// append "man" to the end of the name and display
	strcat(str, "man");
	printf("Your name with \"man\" appended: %s\n", str);

	exit(0);
}
