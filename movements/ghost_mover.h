#ifndef GHOST_MOVER_H_GUARD
#define GHOST_MOVER_H_GUARD


#include "../maze/maze.h"
#include "../maze/player.h"

/* This function is the ghost movements core.
 * It choose a random direction that the ghost is allowed to go and move it.
 * @param maze to update
 * @param ghost that is moving
 */
void move_ghost(Maze *maze, Player *ghost);

/* Moves the ghost to the UP direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_ghost_up (Maze *maze, Player *ghost);

/* Moves the ghost to the RIGHT direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_ghost_right (Maze *maze, Player *ghost);

/* Moves the ghost to the DOWN direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_ghost_down (Maze *maze, Player *ghost);

/* Moves the ghost to the LEFT direction if it's possible.
 * @param maze to update
 * @param ghost that is moving
 * @return O if the ghost moves, 1 otherwise
 */
int move_ghost_left (Maze *maze, Player *ghost);

#endif
