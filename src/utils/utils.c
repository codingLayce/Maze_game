/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* documents may be reproduced, copied or revised without written
* permission of the authors.
*
* @author Lucas Guilbert <lguilbert@ecole.ensicaen.fr>
* @version 1.0
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void copy_string (char *receiver, const char *sender, size_t nb_char) {
	size_t i;

	for (i = 0; i < nb_char; i++) {
		*receiver = *sender; /* assign the current value of sender to the current value of receiver */
		receiver++; /* move the pointer to the next table index */
		sender++; /* same here */
	}

	*receiver = '\0';
}

int read_int () {
	int input;
	int result = scanf("%d", &input);

	if (result == EOF) { /* Error */
		return -1;
	} else if (result == 0) { /* Not an int entered  */
		clear_buffer();
		return -1;
	}
	return input;
}

char read_key() {
	char input;

	input = getchar();
	clear_buffer();

	return input;
}

char read_char() {
	char input;

	scanf(" %c", &input);

	clear_buffer();

	return input;
}

void clear_buffer () {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
