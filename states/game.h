#ifndef GAME_H_GUARD
#define GAME_H_GUARD
#include "../maze/maze.h"
#include "../maze/cell.h"
#include "../utils/config.h"
#include "../maze/highscores.h"

void play (Maze *maze);

int player_on_exit (Maze *maze, Player *player);

void update_score (Maze *maze, Player player, int *score);

void update_cell_type (Cell *cell, cell_type type);

List *check_for_best_score (Maze *maze, List *scores, int score);

void display_highscores(List *list);

void init_ghost(Maze *maze, Player *player);

int update_ghost(Maze *maze, Player *ghost, Player player);

#endif
