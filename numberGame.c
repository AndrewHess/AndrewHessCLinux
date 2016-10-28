/*
	numberGame.c
	Andrew Hess
	10/21/2016
	Generate a random number between 1 and 10. Then get the user's guess
	and either print "You win" if it is the same, or "Try again" if it is
	not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int num = 1 + (rand() % 10);
	
	int guess = 0;
	while (guess != num) {
		while (guess < 1 || guess > 10) {
			printf("Enter a number between 1 and 10\n");
			char str[10];
			scanf("%s", &str);
			int bad = 0;
	/*		for (int i = 0; i < sizeof(str); i++) {
			//	if (!isdigit(str[i])) bad = 1; 
				if (str[i] < 48 || str[i] > 58) {
					bad = 1;
					printf("str[i]: %c\n", str[i]);
				}
			}
	*/		if (!bad) {
				guess = atoi(str);
				//printf("guess: %d\n", guess);
			}
		}
		if (guess != num) {
			guess = 0;
			printf("Try again\n");
		}
	}

	printf("You win\n");
	

/*
	int guess = 0;
	while (guess != num) {
		printf("Enter a number between 1 and 10\n");
		while (1 > guess || guess > 11) {
			scanf("%d", &guess);
			if (!guess) {
			//	printf("Enter a number between 1 and 10\n");
				scanf("%s");
			}
		}
	
//		printf("guess: %d\n", guess);
		if (guess != num) printf("Try again");
	}

	printf("You win");
*/
	exit(0);
}
