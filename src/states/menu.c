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
#include "creator_state.h"
#include "utils.h"
#include "load.h"
#include "game.h"
#include "config.h"

void menu_logic () {
	int choice;
	int load = 0, quit = 1;
	char name[MAX_NAME_SIZE+20];
	Maze loaded_maze;

	do {
		do {
			display_choices();
			choice = read_int();
		} while (choice < 0 || choice > 4);

		switch (choice) {
		case 1:
			create_labyrinthe(&loaded_maze);
			load = 1;
			system(CLEAR_COMMAND);
			printf("%s", LOADED_MAZE_TEXT);
			break;
		case 2:
			load = load_maze(&loaded_maze);
			system(CLEAR_COMMAND);
			if (load == 1) {
			    printf("%s", LOADED_MAZE_TEXT);
			}
			break;
		case 3:
			if (load != 1) {
				system(CLEAR_COMMAND);
				printf("%s", ERROR_NO_MAZE_LOADED);
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
		default: /* Normally can't happen  */
			menu_logic();
			break;
		}
	} while (quit == 1);
}

void display_choices() {
	printf("%d - %s\n", 1, CREATE_MAZE_TEXT);
	printf("%d - %s\n", 2, LOAD_MAZE_TEXT);
	printf("%d - %s\n", 3, PLAY_TEXT);
	printf("%d - %s\n", 4, QUIT_TEXT);
}
