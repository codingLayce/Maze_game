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
#include <unistd.h>

#include "menu.h"
#include "creator.h"
#include "../utils/utils.h"
#include "load.h"
#include "game.h"
#include "../utils/config.h"

const char* CHOICES[4] = {
	CREATE_MAZE_TEXT,
	LOAD_MAZE_TEXT,
	PLAY_TEXT,
	QUIT_TEXT
};

void menu_logic () {
	int choice;
	int load = 0, quit = 1;
	char name[MAX_NAME_SIZE+20];
	Maze loaded_maze;

	do {
		do {
			display_choices();
			choice = read_int();
		} while (choice < 0 || choice > (int)(sizeof(CHOICES) / sizeof(CHOICES[0])));

		switch (choice) {
		case 1:
			create_labyrinthe(&loaded_maze);
			load = 1;
			system(CLEAR_COMMAND);
			printf(LOADED_MAZE_TEXT);
			break;
		case 2:
			load_maze(&loaded_maze);
			load = 1;
			system(CLEAR_COMMAND);
			printf(LOADED_MAZE_TEXT);
			break;
		case 3:
			if (load != 1) {
				system(CLEAR_COMMAND);
				printf(ERROR_NO_MAZE_LOADED);
			} else {
				play(&loaded_maze);
				sprintf(name, "%s.cfg",loaded_maze.name);
				load_file(&loaded_maze, name);
				system(CLEAR_COMMAND);
			}
			break;
		case 4:
			quit = 0;
			break;
		default: /* Normaly can't happen  */
			menu_logic();
			break;
		}
	} while (quit == 1);

	exit(0);
}

void display_choices() {
	size_t nb_choice = sizeof(CHOICES) / sizeof(CHOICES[0]);
	size_t i;
	for (i = 0; i < nb_choice; i++) {
		printf("%ld - %s\n", i+1, CHOICES[i]);
	}	
}
