#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ghost_mover.h"
#include "../maze/maze.h"
#include "../maze/player.h"
#include "mover.h"

int move_ghost(Maze *maze, Player *ghost) {
	Direction dir;
	int res;
	dir  = get_random_dir();

	do {
		switch (dir) {
			case UP:
				res = move_ghost_up(maze, ghost);
				dir = RIGHT;
				break;
			case RIGHT:
				res = move_ghost_right(maze, ghost);
				dir = DOWN;
				break;
			case DOWN:
				res = move_ghost_down(maze, ghost);
				dir = LEFT;
				break;
			case LEFT:
				res = move_ghost_left(maze, ghost);
				dir = UP;
				break;
			default:
				res = 1;
				break;

		}
	} while (res == 1);
	
	return 1;
}

int move_ghost_up (Maze *maze, Player *ghost) {
	int row = ghost->current_row;
	int col = ghost->current_col;

	if (row - 1 < 0) {
		return 1;
	}

	if (maze->board[row-1][col].type == WALL) {
		if (row - 2 < 0 || maze->board[row-2][col].type == WALL) {
			return 1;	
		} else {
			move_up(maze, ghost, 2);
			return 0;
		}
		return 1;
	}

	move_up(maze, ghost, 1);
	return 0;
}

int move_ghost_right (Maze *maze, Player *ghost) {
	int row = ghost->current_row;
	int col = ghost->current_col;

	if (col + 1 > maze->cols - 1) {
		return 1;
	}

	if (maze->board[row][col+1].type == WALL) {
		if (col + 2 > maze->cols - 1 || maze->board[row][col+2].type == WALL) {
			return 1;	
		} else {
			move_right(maze, ghost, 2);	
			return 0;
		}
		return 1;
	}

	move_right(maze, ghost, 1);
	return 0;
}

int move_ghost_down (Maze *maze, Player *ghost) {
	int row = ghost->current_row;
	int col = ghost->current_col;

	if (row + 1 < 0) {
		return 1;
	}

	if (maze->board[row+1][col].type == WALL) {
		if (row + 2 > maze->rows - 1 || maze->board[row+2][col].type == WALL) {
			return 1;	
		} else {
			move_down(maze, ghost, 2);	
			return 0;
		}
		return 1;
	}

	move_down(maze, ghost, 1);
	return 0;
}

int move_ghost_left (Maze *maze, Player *ghost) {
	int row = ghost->current_row;
	int col = ghost->current_col;

	if (col - 1 < 0) {
		return 1;
	}

	if (maze->board[row][col-1].type == WALL) {
		if (col - 2 < 0 || maze->board[row][col-2].type == WALL) {
			return 1;	
		} else {
			move_left(maze, ghost, 2);	
			return 0;
		}
		return 1;
	}

	move_left(maze, ghost, 1);
	return 0;
}
