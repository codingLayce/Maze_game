#ifndef PLAYERMOVER_H_GUARD
#define PLAYERMOVER_H_GUARD

#include "maze.h"
#include "player.h"

/* Moves the player to the UP direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_player_up (Maze *maze, Player *player);

/* Moves the player to the RIGHT direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_player_right (Maze *maze, Player *player);

/* Moves the player to the DOWN direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_player_down (Maze *maze, Player *player);

/* Moves the player to the LEFT direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_player_left (Maze *maze, Player *player);

#endif
