#ifndef PLAYERMOVER_H_GUARD
#define PLAYERMOVER_H_GUARD

#include "../maze/maze.h"
#include "../maze/player.h"

int move_player_up (Maze *maze, Player *player);
int move_player_right (Maze *maze, Player *player);
int move_player_down (Maze *maze, Player *player);
int move_player_left (Maze *maze, Player *player);

#endif
