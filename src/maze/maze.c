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
#include <time.h>
#include <stdlib.h>

#include "maze.h"
#include "creator.h"
#include "cell.h"

void display_maze (Maze *maze) {
	int row, col;
	for (row = 0; row < maze->rows; row++) {
		for (col = 0; col < maze->cols; col++) {
			if (maze->board[row][col].player != NULL) { /* If the cell has a player on it */
				display_player_color(maze->board[row][col]);
				printf("%c%s", get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);	
			} else if (maze->board[row][col].type == WALL) {
				printf("%s%c%s", WALL_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].type == TREASURE){
				printf("%s%c%s", TREASURE_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].type == TRAP) {
				printf("%s%c%s", TRAP_COLOR, get_cell_skin(maze->board[row][col]), DEFAULT_COLOR);
			} else if (maze->board[row][col].player == NULL) { /* Otherwise it's an empty cell */
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
			if (row % 2 == 1 && col % 2 == 1) { /* This condition is true one cell in two */
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
