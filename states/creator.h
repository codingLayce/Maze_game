#ifndef CREATOR_H_GUARD
#define CREATOR_H_GUARD
#include "../maze/maze.h"

/* Function that creates a labyrinthe and saves it.
 * The user has to enter the labyrinthe size.
 */
void create_labyrinthe(Maze *maze);

/* Ask the user to enter the width of the labyrinthe (has to be an odd number)
 */
int ask_for_width();

/* Check if the width is an odd number, greather tha 0 and lesser than MAZE_MAX_COLS.
 * Return 1 if the conditions above are false, 0 otherwise.
 */
int check_for_valid_width(int width);

/* Ask the user to enter the height of the labyrinthe (hasto be an odd number)
 */
int ask_for_height();

/* Check if the height is an odd number, greather than 0 and lesser than MAZE_MAX_ROWS.
 * Return 1 if the conditions above are false, 0 otherwise.
 */
int check_for_valid_height(int height);

int ask_for_difficulty();
int check_for_valid_difficulty(int dif);

/* Function that save the maze in the file "<name>.cfg".
 */
void save_maze (Maze *maze, char *name);

#endif
