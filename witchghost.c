/*
	witchghost.c
	Andrew Hess
	10/31/2016
	Get user input for a distance. The witch travels at 13mph but takes
	25 minutes to start. The ghost travels at 6mph. Print which one
	gets there first
*/

#include <stdio.h>
#include <stdlib.h>

float witchtime(float dist);
float ghosttime(float dist);
float othertime(float dist);

int main() {
	float dist = 0.0;
	printf("Enter the distance to travel: ");
	scanf("%f", &dist);
	float witch = witchtime(dist);
	float ghost = ghosttime(dist);
	float other = othertime(dist);

	float min = witch;
	char win = 'w';
	if (ghost < min) {
		min = ghost;
		win = 'g';
	}
	if (other < min) {
		min = other;
		win = 'o';
	}

	if (win == 'w') printf("Witch wins\n");
	else if (win == 'g') printf("Ghost wins\n");
	else if (win == 'o') printf("Other wins\n");

	exit(0);
}

float witchtime(float dist) {
	return 5.0/12 + dist/13.0;
}

float ghosttime(float dist) {
	return dist/6.0;
}

float othertime(float dist) {
	return 1.0/6 + dist/10.0;
}
