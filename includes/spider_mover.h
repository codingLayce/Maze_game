#ifndef SPIDER_MOVER_H_GUARD
#define SPIDER_MOVER_H_GUARD

#include "maze.h"
#include "player.h"

/* This function is the spider movements core.
 * It choose a random direction that the spider is allowed to go and move it.
 * @param maze to update
 * @param spider that is moving
 */
void move_spider(Maze *maze, Player *spider);

/* Moves the spider to the UP direction if it's possible.
 * @param maze to update
 * @param spider that is moving
 * @return O if the spider moves, 1 otherwise
 */
int move_spider_up (Maze *maze, Player *spider);

/* Moves the spider to the RIGHT direction if it's possible.
 * @param maze to update
 * @param spider that is moving
 * @return O if the spider moves, 1 otherwise
 */
int move_spider_right (Maze *maze, Player *spider);

/* Moves the spider to the DOWN direction if it's possible.
 * @param maze to update
 * @param spider that is moving
 * @return O if the spider moves, 1 otherwise
 */
int move_spider_down (Maze *maze, Player *spider);

/* Moves the spider to the LEFT direction if it's possible.
 * @param maze to update
 * @param spider that is moving
 * @return O if the spider moves, 1 otherwise
 */
int move_spider_left (Maze *maze, Player *spider);

#endif