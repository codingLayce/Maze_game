#ifndef MAZE_H_GUARD
#define MAZE_H_GUARD

#include "cell.h"
#include "../utils/config.h"

typedef struct {
	int rows;
	int cols;
	char name[MAX_NAME_SIZE];
	Cell board[MAZE_MAX_ROWS][MAZE_MAX_COLS];
	int difficulty;
} Maze;

void init_maze(Maze *maze, int width, int height, int difficulty);
void display_maze (Maze *maze);
Cell *get_random_cell_with_type (Maze *maze, cell_type type);

#endif
