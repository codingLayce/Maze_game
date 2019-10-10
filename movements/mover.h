#ifndef MOVER_H_GUARD
#define MOVER_H_GUARD

#include "../maze/maze.h"
#include "../maze/player.h"

/* Represents the direction where an entity can move.
 * It's mainly used for the monsters movements.
 */
typedef enum {UP, RIGHT, DOWN, LEFT}Direction;

/* Moves the entity UP.
 * @param maze to update
 * @param player that is moving
 * @param step that the entity is doing
 */
void move_up (Maze *maze, Player *player, int step);

/* Moves the entity UP.
 * @param maze to update
 * @param player that is moving
 * @param step that the entity is doing
 */
void move_right (Maze *maze, Player *player, int step);

/* Moves the entity UP.
 * @param maze to update
 * @param player that is moving
 * @param step that the entity is doing
 */
void move_down (Maze *maze, Player *player, int step);

/* Moves the entity UP.
 * @param maze to update
 * @param player that is moving
 * @param step that the entity is doing
 */
void move_left (Maze *maze, Player *player, int step);

/* Choose a random direction.
 * @return a random direction.
 */
Direction get_random_dir();

#endif
