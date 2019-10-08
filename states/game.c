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
#include <errno.h>

#include "game.h"
#include "../maze/maze.h"
#include "../maze/player.h"
#include "../movements/player_mover.h"
#include "../movements/ghost_mover.h"
#include "../utils/utils.h"
#include "../maze/cell.h"
#include "../maze/highscores.h"

void play (Maze *maze) {
	Player player;
	Player ghost;
	char c;
	int score = 0;
	int res;
	int exit = 1;
	List *scores = load_highscores(maze);

	system(CLEAR_COMMAND);

	init_player(&player, PLAYER, 1, 0, '%');
	set_player(&maze->board[1][0], &player);
	init_ghost(maze, &ghost);

	do {
		printf("%s%s\n", MAZE_NAME_TEXT, maze->name);
		printf("\n");
		display_list(scores);
		printf("\n");
		printf(TOP_OF_GAME_TEXT);
		printf("%s%d\n", GAME_SCORE_TEXT, score);
		display_maze(maze);
		c = read_char();

		switch (c) {
			case 'z':
				res = move_player_up(maze, &player);
				break;
			case 'd':
				res = move_player_right(maze, &player);
				break;
			case 's':
				res = move_player_down(maze, &player);
				break;
			case 'q':
				res = move_player_left(maze, &player);
				break;
			default:
				res = 1;
				break;
		}

		if (res == 0) { /* Update the score only if the player has moved.  */
			update_score(maze, player, &score);
			if (maze->difficulty == 2 && exit != 0) {
				if (update_ghost(maze, &ghost, player) == 0) {
					exit = 0;
				}
			}
		}	

		system(CLEAR_COMMAND);
	} while (player_on_exit(maze, &player) != 0 && exit != 0);

	if (exit == 0) { /* Player hit a monster  */
		printf(DEFEAT_TEXT);	
	} else {
		scores = check_for_best_score(maze, scores, score);
	}

	display_maze(maze);	
	display_list(scores);
	unload_list(scores);
	printf(PRESS_RETURN_TEXT);
	read_key();
}	

List *check_for_best_score (Maze *maze, List *list, int score) {
	char pseudo[MAX_PSEUDO_SIZE];
	int ok = 1;
	int i = 0;
	int index = 0;
	Highscore *tmp;
	Highscore *new = malloc(sizeof(Highscore));

	if (list == NULL) {
		ok = 0;
	} else {
		if (nb_elements(list) < 10)  {
			index = nb_elements(list) -1;
			ok = 0;
		}
		tmp = list->best;
		while (tmp != NULL) {
			if (ok == 1 && score < tmp->score) {
				ok = 0;
				index = i;
			}
			tmp = tmp->next_score;
			i++;
		}
		if (index >= 10) { /* In case of the index is out of the array size  */
			ok = 1;
		}
	}

	if (ok == 0) {
		printf(NEW_HIGHSCORE_TEXT);
		printf(ENTER_PSEUDO_TEXT);
		scanf("%20s", pseudo);

		new->score = score;
		copy_string(new->pseudo, pseudo, sizeof(pseudo));
		new->next_score = NULL;

		list = insert_highscore(list, new, index);
		save_highscores(list, maze);
	}

	return list;
}

void display_highscores(List *list) {
	Highscore *score = list->best;

	if (list == NULL) {
		return;
	}

	while (score != NULL) {
		printf("%s: %d\n", score->pseudo, score->score);
		score = score->next_score;
	}
}

void update_score (Maze *maze, Player player, int *score) {
	switch (maze->board[player.current_row][player.current_col].type) {
		case TREASURE:
			*score += TREASURE_SCORE;
			update_cell_type (&maze->board[player.current_row][player.current_col], EMPTY);
			break;
		case TRAP:
			*score += TRAP_SCORE;
			update_cell_type (&maze->board[player.current_row][player.current_col], EMPTY);
			break;
		default:
			*score += STEP_SCORE;
	}
}

int update_ghost(Maze *maze, Player *ghost, Player player) {
	if (player.current_row == ghost->current_row && player.current_col == ghost->current_col) {
		return 0;
	}
	move_ghost(maze, ghost);	
	if (player.current_row == ghost->current_row && player.current_col == ghost->current_col) {
		return 0;
	}
	return 1;
}

void update_cell_type (Cell *cell, cell_type type) {
	cell->type = type;
}

int player_on_exit (Maze *maze, Player *player) {
	if (player->current_row == maze->rows-2 && player->current_col == maze->cols-1) {
		return 0;
	}
	return 1;
}

void init_ghost(Maze *maze, Player *ghost) {
	int row, col;

	const int max_row = maze->rows - 2;
	const int max_col = maze->cols - 2;
	const int min_row = 1;
	const int min_col = 1;

	if (maze->difficulty == 2) {
		srand(time(NULL));

		do {
			row = (rand() % (max_row - min_row + 1)) + min_row;
			col = (rand() % (max_col - min_col + 1)) + min_col;
		} while (maze->board[row][col].type != EMPTY);

		init_player(ghost, GHOST, row, col, 'G');
		set_player(&maze->board[row][col], ghost);
	}
}
