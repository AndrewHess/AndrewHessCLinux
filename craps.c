/*
	craps.c
	Andrew Hess
	10/25/2016
	Prompt the user for how much they want to bet on a game of
	craps and simulate the game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
	int bet = 0;
	int isnum = 0;
	while (!isnum) {
		isnum = 1;
		printf("Enter the amount you want to bet: ");
		char ch = getchar();
		int overlimit = 0;
	
		while (ch != '\n') {
			if (ch >= '0' && ch <= '9') bet = bet*10 + ch - '0';
			else isnum = 0;

			if (bet < 0) overlimit = 1;

			ch = getchar();
		}

		if (!isnum) {
			printf("Invalid bet\n");
			bet = 0;
		}
		if (overlimit) {
			printf("Bet must be less than %d\n", INT_MAX);
			isnum = 0;
			bet = 0;
		}
	}
	
	int d1, d2, sum;
	srand(time(NULL));
	d1 = rand() % 6 + 1;
	d2 = rand() % 6 + 1;
	sum = d1 + d2;

	printf("Roll: %d %d\nSum: %d\n", d1, d2, sum);
	
	if (sum == 7 || sum == 11) {
		printf("You won %d dollars\n", bet);
		exit(0);
	}
	else if (sum == 2 || sum == 3 || sum == 12) {
		printf("You lost %d dollars\n", bet);
		exit(0);
	}
	else {
		int point = sum;
		sum = 0;
		while (point != sum && sum != 7) {
			d1 = rand() % 6 + 1;
			d2 = rand() % 6 + 1;
			sum = d1 + d2;	
			
			printf("Roll: %d %d\nSum: %d\n", d1, d2, sum);
		}
	
		if (point == sum) printf("You won %d dollars\n", bet);
		else printf("You lost %d dollars\n", bet);
	}

	exit(0);
}
