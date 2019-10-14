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

#include "mover.h"
#include "../maze/maze.h"
#include "../maze/player.h"

void move_up (Maze *maze, Player *player, int step) {
	int p_row = player->current_row;
	int p_col = player->current_col;
	
	set_player(&maze->board[p_row][p_col], NULL);
	set_player(&maze->board[p_row-step][p_col], player);
	player->current_row -= step;
}

void move_right (Maze *maze, Player *player, int step) {
	int p_row = player->current_row;
	int p_col = player->current_col;

	set_player(&maze->board[p_row][p_col], NULL);
	set_player(&maze->board[p_row][p_col+step], player);
	player->current_col += step;
}

void move_down (Maze *maze, Player *player, int step) {
	int p_row = player->current_row;
	int p_col = player->current_col;

	set_player(&maze->board[p_row][p_col], NULL);
	set_player(&maze->board[p_row+step][p_col], player);
	player->current_row += step;
}

void move_left (Maze *maze, Player *player, int step) {
	int p_row = player->current_row;
	int p_col = player->current_col;

	set_player(&maze->board[p_row][p_col], NULL);
	set_player(&maze->board[p_row][p_col-step], player);
	player->current_col -= step;
}

Direction get_random_dir() {
	int dir;
	const int max_dir = 3;
	const int min_dir = 0;

	srand(time(NULL));

	dir = (rand() % (max_dir - min_dir + 1)) + min_dir;
	
	switch (dir) {
		case 0:
			return UP;
		case 1:
			return RIGHT;
		case 2:
			return DOWN;
		case 3:
			return LEFT;
		default:
			return LEFT;	
	}
}
