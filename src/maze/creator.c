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
#include <time.h>
#include <math.h>

#include "maze.h"
#include "creator.h"
#include "cell.h"

const int min_row = 1;
const int min_col = 1;

void generate_maze (Maze *maze, int difficulty) {
    /* The dif_offset is used when the difficulty is hard.
     * It allow to remove more walls when the maze is already perfect. */
	int dif_offset = 0;

	if (difficulty == 2) {
		dif_offset = (int)((maze->rows + maze->cols) * 0.1);
	}

	srand(time(NULL));

	while (check_for_perfect_labyrinthe(maze) == 1 || dif_offset > 0) {
		int row, col;
		int ok = 1;

		const int max_row = maze->rows - 2;
		const int max_col = maze->cols - 2;

		row = (rand() % (max_row - min_row + 1)) + min_row;
		col = (rand() % (max_col - min_col + 1)) + min_col;

		if (maze->board[row][col].type == WALL) {
			if (check_for_perfect_labyrinthe(maze) == 0) { /* If 0 means that we are on hard difficulty and trying to remove more walls */
				if (check_for_valid_wall_to_remove(maze, row, col, 0) == 0) {
					ok = 0;
					--dif_offset;
				}
			} else if (check_for_valid_wall_to_remove(maze, row, col, 1) == 0){
				ok = 0;
			}
			
			if (ok == 0) { /* Means that the wall can be replace by an empty cell. */
				maze->board[row][col].type = EMPTY;
				maze->board[row][col].value = get_first_value(maze, row, col);
				scan_neighbor(maze, row, col, maze->board[row][col].value);
			}
		}
	}
	/* Open the entrance and the exit that are always at the same position */
	maze->board[1][0].type = EMPTY;
	maze->board[maze->rows-2][maze->cols-1].type = EMPTY;

	generate_treasures(maze);
	generate_traps(maze);
}

void generate_treasures(Maze *maze) {
	Cell *c = malloc(sizeof(Cell));
	const int nb_empty_cells = (floor(maze->rows/2) * floor(maze->cols/2)) + (floor(maze->rows/2) * floor(maze->cols/2 - 1));
	const int nb_treasure = floor(nb_empty_cells * TREASURE_RATIO);
	int i;

	for (i = 0; i < nb_treasure; ++i) {
		c = get_random_cell_with_type(maze, EMPTY);
		c->type = TREASURE;
	}
}

void generate_traps(Maze *maze) {	
	Cell *c = malloc(sizeof(Cell));
	const int nb_empty_cells = (floor(maze->rows/2) * floor(maze->cols/2)) + (floor(maze->rows/2) * floor(maze->cols/2 - 1));
	const int nb_traps = floor(nb_empty_cells * TRAPS_RATIO);
	int i;

	for (i = 0; i < nb_traps; ++i) {
		c = get_random_cell_with_type(maze, EMPTY);
		c->type = TRAP;
	}
}

int check_for_valid_wall_to_remove(Maze *maze, int row, int col, int more) {
	int nb_neighbors = 0;

	/* UP  */
	if (row - 1 > 0) {
		if (maze->board[row-1][col].type == EMPTY) {
			nb_neighbors++;
		}
	}
	/* LEFT  */
	if (col - 1 > 0) {
		if (maze->board[row][col-1].type == EMPTY) {
			nb_neighbors++;
		}
	}	
	/* DOWN  */
	if (row + 1 < maze->rows-1) {
		if (maze->board[row+1][col].type == EMPTY) {
			nb_neighbors++;
		}
	}
	/* RIGHT  */
	if (col + 1 < maze->cols-1) {
		if (maze->board[row][col+1].type == EMPTY) {
			nb_neighbors++;
		}
	}

	if (nb_neighbors == 2) { /* Can have exactly 3 neighbors */
		if (maze->board[row-1][col].type == EMPTY && maze->board[row+1][col].type == EMPTY) { /* if neighbors are on the same col */
			if (maze->board[row-1][col].value != maze->board[row+1][col].value) { /* Check for different value */
				return 0;
			} else if (more == 0) { /* Means that we are trying to remove more walls (Hard difficulty) */
				return 0;
			}
			return 1;
		} else if (maze->board[row][col-1].type == EMPTY && maze->board[row][col+1].type == EMPTY) { /* if neighbors are on the same row */
			if (maze->board[row][col-1].value != maze->board[row][col+1].value) { /* Check for different value */
				return 0;
			} else if (more == 0) { /* Means that we are trying to remove more walls (Hard difficulty) */
				return 0;
			}
			return 1;
		}
	}
	return 1;
}

int check_for_perfect_labyrinthe (Maze *maze) {
	int row, col;
	int previous = maze->board[1][1].value; /* This cell is always an EMPTY one because of the board init  */

	for (row = 1; row < maze->rows-1; row++) {
		for (col = 1; col < maze->cols-1; col++) {
			if (maze->board[row][col].type == EMPTY) {
				if (maze->board[row][col].value != previous) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int get_first_value (Maze *maze, int row, int col) {
	int max = -1;
	/* UP  */
	if (row - 1 > 0) { /* If we are in the board  */
		if (maze->board[row-1][col].value > max) {
			max = maze->board[row-1][col].value;
		}
	}
	/* LEFT  */
	if (col - 1 > 0) { /* If we are in the board  */
		if (maze->board[row][col-1].value > max) {
			max = maze->board[row][col-1].value;
		}
	}	
	/* DOWN  */
	if (row + 1 < maze->rows-1) {
		if (maze->board[row+1][col].value > max) {
			max = maze->board[row+1][col].value;
		}
	}	
	/* RIGHT  */
	if (col + 1 < maze->cols-1) {
		if (maze->board[row][col+1].value > max) {
			max = maze->board[row][col+1].value;
		}
	}
	return max;
}

void scan_neighbor(Maze *maze, int row, int col, int value) {
	/* UP  */
	if (row - 1 > 0) { /* If we are in the board  */
		if (maze->board[row-1][col].type == EMPTY) {
			if (maze->board[row-1][col].value != value) {
				maze->board[row-1][col].value = value;
				scan_neighbor(maze, row-1, col, value);
			}
		}
	}
	/* LEFT  */
	if (col - 1 > 0) { /* If we are in the board  */
		if (maze->board[row][col-1].type == EMPTY) {
			if (maze->board[row][col-1].value != value) {
				maze->board[row][col-1].value = value;
				scan_neighbor(maze, row, col-1, value);
			}
		}
	}	
	/* DOWN  */
	if (row + 1 < maze->rows-1) {
		if (maze->board[row+1][col].type == EMPTY) {
			if (maze->board[row+1][col].value != value) {
				maze->board[row+1][col].value = value;
				scan_neighbor(maze, row+1, col, value);
			}
		}
	}	
	/* RIGHT  */
	if (col + 1 < maze->cols-1) {
		if (maze->board[row][col+1].type == EMPTY) {
			if (maze->board[row][col+1].value != value) {
				maze->board[row][col+1].value = value;
				scan_neighbor(maze, row, col+1, value);
			}
		}
	}
}
