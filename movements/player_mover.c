#include "player_mover.h"
#include "mover.h"
#include "../maze/maze.h"

int move_player_up (Maze *maze, Player *player) {
	int p_row = player->current_row;
	int p_col = player->current_col;

	if (p_row - 1 < 0) {
		return 1;
	}

	if (maze->board[p_row-1][p_col].type == WALL) {
		return 1;
	}

	move_up(maze, player, 1);
	return 0;
}

int move_player_right (Maze *maze, Player *player) {
	int p_row = player->current_row;
	int p_col = player->current_col;
	
	if (p_col + 1 > maze->cols - 1) {
		return 1;
	}

	if (maze->board[p_row][p_col+1].type == WALL) {
		return 1;
	}

	move_right(maze, player, 1);
	return 0;
}

int move_player_down (Maze *maze, Player *player) {
	int p_row = player->current_row;
	int p_col = player->current_col;
	
	if (p_row + 1 > maze->rows - 1) {
		return 1;
	}

	if (maze->board[p_row+1][p_col].type == WALL) {
		return 1;
	}

	move_down(maze, player, 1);
	return 0;
}

int move_player_left (Maze *maze, Player *player) {
	int p_row = player->current_row;
	int p_col = player->current_col;
	
	if (p_col - 1 < 0) {
		return 1;
	}

	if (maze->board[p_row][p_col-1].type == WALL) {
		return 1;
	}

	move_left(maze, player, 1);
	return 0;	
}
