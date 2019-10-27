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
#include <string.h>

#include "creator_state.h"
#include "maze.h"
#include "utils.h"
#include "creator.h"
#include "config.h"

void create_labyrinthe(Maze *maze) {
	int width, height, difficulty;
	char name[MAX_NAME_SIZE];
	
	width = ask_for_width();
	height = ask_for_height();
	difficulty = ask_for_difficulty();

	do {
		printf("%s", ENTER_MAZE_NAME_TEXT);
		scanf("%30s", name);
		copy_string(maze->name, name, sizeof(name));
	} while(strrchr(name, '/') != NULL);

	init_maze(maze, width, height, difficulty);
	generate_maze(maze, difficulty);
	
	printf("%s\n", MAZE_GENERATED_TEXT);
	display_maze(maze);

	printf("%s%s.cfg\n", SAVING_MAZE_TEXT, name);
	save_maze(maze, name);

	printf("%s", PRESS_RETURN_TEXT);
	read_key();	
}

void save_maze (Maze *maze, char *name) {
	FILE *out;
	char path[MAX_NAME_SIZE+10];
	int n;

	sprintf(path, "%s%s.cfg", PATH_TO_SAVES, name);
	
	out = fopen(path, "w+");
	if (out == NULL) {
        fprintf(stderr, "\n%s %s\n", ERROR_OPENING_FILE, path);
        exit(1);
	}

	n = fwrite(maze, sizeof(Maze), 1, out);
	if (n != 0) {
		printf("file saved !\n");
	} else {
		fprintf(stderr, "\n%s\n", ERROR_WRITING_FILE);
		exit(1);
	}

	fclose(out);
}

int ask_for_width() {
	int width;
	do {
		printf("%s (%d-%d)\n", ENTER_MAZE_WIDTH_TEXT, MAZE_MIN_COLS, MAZE_MAX_COLS);
		width = read_int();
	} while (check_for_valid_width(width) == 1);
	return width;
}

int check_for_valid_width(int width) {
	if (width % 2 == 0) { /* If width isn't an odd number  */
		return 1;
	}
	if (width < MAZE_MIN_COLS) {
		return 1;
	}
	if (width > MAZE_MAX_COLS) {
		return 1;
	}
	return 0;
}

int ask_for_height() {
	int height;
	do {
		printf("%s (%d-%d)\n", ENTER_MAZE_HEIGHT_TEXT, MAZE_MIN_ROWS, MAZE_MAX_ROWS);
		height = read_int();
	} while (check_for_valid_height(height) == 1);
	return height;
}

int check_for_valid_height(int height) {
	if (height % 2 == 0) {
		return 1;
	}
	if (height < MAZE_MIN_ROWS) {
		return 1;
	}
	if (height > MAZE_MAX_ROWS) {
		return 1;
	}
	return 0;
}

int ask_for_difficulty() {
	int dif;
	do {
		printf("%s", ENTER_MAZE_DIFFICULTY_TEXT);
		dif = read_int();
	} while (check_for_valid_difficulty(dif) == 1);
	return dif;
}

int check_for_valid_difficulty(int dif) {
	if (dif == 1 || dif == 2) {
		return 0;
	}
	return 1;
}
