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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ghost_mover.h"
#include "maze.h"
#include "player.h"
#include "mover.h"

void move_ghost(Maze *maze, Player *ghost) {
	Direction dir;
	int res;

	dir  = get_random_dir();

    /* Here my first approach was to pick a random direction while the movement isn't possible.
     * The problem was that, in lot of cases (when only 1 or 2 directions are possibles), the function was very slow (2 or 3 seconds to return)
     * So i've decided, instead of repicking a random direction each time it doesn't work, to pick one time a random direction
     * and look for the next one until it's possible to move. The function is now so much faster and stay random.
     */
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
