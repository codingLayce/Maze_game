#ifndef GHOST_MOVER_H_GUARD
#define GHOST_MOVER_H_GUARD


#include "../maze/maze.h"
#include "../maze/player.h"

int move_ghost(Maze *maze, Player *ghost);
int move_ghost_up (Maze *maze, Player *ghost);
int move_ghost_right (Maze *maze, Player *ghost);
int move_ghost_down (Maze *maze, Player *ghost);
int move_ghost_left (Maze *maze, Player *ghost);

#endif
