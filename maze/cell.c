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
#include "cell.h"
#include "../utils/config.h"

void new_cell (Cell *cell, cell_type type, int value) {
	cell->type = type;
	cell->value = value;
	cell->player = NULL;
}

void display_cell (Cell *cell) {
	printf("{Cell| type:%d, value:%d}\n", cell->type, cell->value);
}

void display_player_color(Cell cell) {
	switch (cell.player->type) {
		case PLAYER:
			printf("%s", PLAYER_COLOR);
			break;
		case GHOST:
			printf("%s", GHOST_COLOR);
			break;
	}
}

char get_cell_skin (Cell cell) {
	if (cell.player != NULL) {
		return cell.player->skin;
	} else if (cell.type == TREASURE) {
		return '$';
	} else if (cell.type == TRAP) {
		return '~';
	} else if (cell.type == WALL) {
		return '#';
	} else {
		return ' ';
	}
}

int get_points(Cell *cell) {
	switch (cell->type) {
		case EMPTY:
			return STEP_SCORE;
		case TREASURE:
			return TREASURE_SCORE;
		case TRAP:
			return TRAP_SCORE;
		default:
			return 0;
	}
}

void set_player(Cell *cell, Player *player) {
	cell->player = player;
}
