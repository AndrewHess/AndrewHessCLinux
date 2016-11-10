/*
	substrings.c
	Andrew Hess
	11/8/2016
	Read in two stings a and b. Print the index of the last occurence of 
	b in a. Print the number of times b appears in a.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[100] = {0};
	char b[100] = {0};
	int count = -1;
	int last = -1; // index of last occurence of b in a

	char *astr = a;
	char *bstr = b;

	printf("Enter two strings: ");
	scanf("%s %s", astr, bstr);

	while (astr != NULL) {
		astr = strstr(astr, bstr);
		count++;

		if (astr != NULL) {
			last = astr - a;
			astr += 1;
		}
	}

	astr = a;

	printf("Index of last occurance of \"%s\" in \"%s\": %d\n", bstr, astr, last);
	printf("Number of times \"%s\" appears in \"%s\": %d\n", bstr, astr, count);

	exit(0);
}
