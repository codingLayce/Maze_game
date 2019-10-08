#ifndef MOVER_H_GUARD
#define MOVER_H_GUARD

#include "../maze/maze.h"
#include "../maze/player.h"

typedef enum {UP, RIGHT, DOWN, LEFT}Direction;

void move_up (Maze *maze, Player *player, int step);
void move_right (Maze *maze, Player *player, int step);
void move_down (Maze *maze, Player *player, int step);
void move_left (Maze *maze, Player *player, int step);
Direction get_random_dir();

#endif
