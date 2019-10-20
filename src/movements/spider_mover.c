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

#include "spider_mover.h"
#include "maze.h"
#include "player.h"
#include "mover.h"
#include "config.h"

void move_spider(Maze *maze, Player *spider) {
    Direction dir;
    int res;

    dir  = get_random_dir();

    do {
        switch (dir) {
            case UP:
                res = move_spider_up(maze, spider);
                dir = RIGHT;
                break;
            case RIGHT:
                res = move_spider_right(maze, spider);
                dir = DOWN;
                break;
            case DOWN:
                res = move_spider_down(maze, spider);
                dir = LEFT;
                break;
            case LEFT:
                res = move_spider_left(maze, spider);
                dir = UP;
                break;
            default:
                res = 1;
                break;

        }
    } while (res == 1);
}

int move_spider_up (Maze *maze, Player *spider) {
    int range;
    int row = spider->current_row;
	int col = spider->current_col;
	
	if (spider->start_row < row) {
	    range = row - spider->start_row;
	} else {
	    range = spider->start_row - row;
	}

	if (row - 1 < 0) {
		return 1;
	}

	if (maze->board[row-1][col].type == WALL) {
        return 1;
    }

    if (range < SPIDER_MOBILITY_RANGE) {
        move_up(maze, spider, 1);

        return 0;
	}

	return 1;
}


int move_spider_right (Maze *maze, Player *spider) {
    int range;
    int row = spider->current_row;
	int col = spider->current_col;
	
	if (spider->start_col < col) {
	    range = col - spider->start_col;
	} else {
	    range = spider->start_col - col;
	}

	if (col + 1 > maze->cols - 1) {
		return 1;
	}

	if (maze->board[row][col+1].type == WALL) {
        return 1;
    }

    if (range < SPIDER_MOBILITY_RANGE) {
        move_right(maze, spider, 1);

        return 0;
	}

	return 1;
}


int move_spider_down (Maze *maze, Player *spider) {
    int range;
    int row = spider->current_row;
    int col = spider->current_col;
	
	if (spider->start_row < row) {
	    range = row - spider->start_row;
	} else {
	    range = spider->start_row - row;
	}

    if (row + 1 > maze->rows - 1) {
        return 1;
    }

    if (maze->board[row+1][col].type == WALL) {
        return 1;
    }

    if (range < SPIDER_MOBILITY_RANGE) {
        move_down(maze, spider, 1);

        return 0;
    }

    return 1;
}


int move_spider_left (Maze *maze, Player *spider) {
    int range;
    int row = spider->current_row;
	int col = spider->current_col;
	
	if (spider->start_col < col) {
	    range = col - spider->start_col;
	} else {
	    range = spider->start_col - col;
	}

	if (col - 1 < 0) {
		return 1;
	}

	if (maze->board[row][col-1].type == WALL) {
        return 1;
    }

    if (range < SPIDER_MOBILITY_RANGE) {
        move_left(maze, spider, 1);

        return 0;
	}

	return 1;
}