#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "creator.h"
#include "../maze/maze.h"
#include "../utils/utils.h"
#include "../maze/creator.h"
#include "../utils/config.h"

void create_labyrinthe(Maze *maze) {
	int width, height, difficulty;
	char name[MAX_NAME_SIZE];
	
	width = ask_for_width();
	height = ask_for_height();
	difficulty = ask_for_difficulty();

	printf(ENTER_MAZE_NAME_TEXT);
	scanf("%30s", name);
	copy_string(maze->name, name, sizeof(name));

	init_maze(maze, width, height, difficulty);
	generate_maze(maze, difficulty);
	
	printf("This maze has been generated: \n");
	display_maze(maze);

	printf("Saving the maze in the file saves/%s.cfg\n", name);
	save_maze(maze, name);

	printf(PRESS_RETURN_TEXT);
	read_key();	
}

void save_maze (Maze *maze, char *name) {
	FILE *out;
	char path[MAX_NAME_SIZE+10];
	int n;

	sprintf(path, "saves/%s.cfg", name);
	
	out = fopen(path, "w+");
	if (out == NULL) {
		fprintf(stderr, "\nError while opening the file %s\n", path);
		exit(1);
	}

	n = fwrite(maze, sizeof(Maze), 1, out);
	if (n != 0) {
		printf("file saved !\n");
	} else {
		fprintf(stderr, "\nError while writing file !\n");
		exit(1);
	}

	fclose(out);
}

int ask_for_width() {
	int width;
	do {
		printf(ENTER_MAZE_WIDTH_TEXT);
		width = read_int();
	} while (check_for_valid_width(width) == 1);
	return width;
}

int check_for_valid_width(int width) {
	if (width % 2 == 0) { /* If width isn't an odd number  */
		return 1;
	}
	if (width < 0) {
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
		printf(ENTER_MAZE_HEIGHT_TEXT);
		height = read_int();
	} while (check_for_valid_height(height) == 1);
	return height;
}

int check_for_valid_height(int height) {
	if (height % 2 == 0) {
		return 1;
	}
	if (height < 0) {
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
		printf(ENTER_MAZE_DIFFICULTY_TEXT);
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
