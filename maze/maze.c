#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "maze.h"
#include "creator.h"
#include "cell.h"

void display_maze (Maze *maze) {
	int row, col;
	for (row = 0; row < maze->rows; row++) {
		for (col = 0; col < maze->cols; col++) {
			if (maze->board[row][col].player != NULL) {
				display_player_color(maze->board[row][col]);
				printf("%c%s", get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);	
			} else if (maze->board[row][col].type == WALL) {
				printf("%s%c%s", WALL_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].type == TREASURE){
				printf("%s%c%s", TREASURE_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].type == TRAP) {
				printf("%s%c%s", TRAP_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].player == NULL) {
				printf("%s%c%s", EMPTY_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			}
		}
		printf("\n");
	}
}

void init_maze(Maze *maze, int width, int height, int difficulty) {
	int row, col;
	int i = 0;
	
	maze->cols = width;
	maze->rows = height;
	maze->difficulty = difficulty;

	for (row = 0; row < maze->rows; row++) {
		for (col = 0; col < maze->cols; col++) {
			Cell c;
			if (row % 2 == 1 && col % 2 == 1) {
				new_cell(&c, EMPTY, i);
				i++;
			} else {
				new_cell(&c, WALL, -1);
			}
			maze->board[row][col] = c;
		}
	}
}

Cell *get_random_cell_with_type (Maze *maze, cell_type type) {
	int row, col;

	const int max_row = maze->rows - 2;
	const int max_col = maze->cols - 2;
	const int min_row = 1;
	const int min_col = 1;

	srand(time(NULL));

	do {
		row = (rand() % (max_row - min_row + 1)) + min_row;
		col = (rand() % (max_col - min_col + 1)) + min_col;
	} while (maze->board[row][col].type != type);

	return &maze->board[row][col];
}
