#ifndef CREATOR_H_GUARD
#define CREATOR_H_GUARD
#include "../maze/maze.h"

/* Creates a maze and saves it.
 * The user has to enter the maze size, name and difficulty.
 * @param maze structure that will contains the maze
 */
void create_labyrinthe(Maze *maze);

/* Ask the user to enter the width of the maze (has to be an odd number).
 * @return the maze width
 */
int ask_for_width();

/* Check if the width is an odd number, greater than 0 and lesser than MAZE_MAX_COLS.
 * @param width to check
 * @return 1 if the conditions above are false, 0 otherwise.
 */
int check_for_valid_width(int width);

/* Ask the user to enter the height of the maze (has to be an odd number).
 * @return the maze height
 */
int ask_for_height();

/* Check if the height is an odd number, greater than 0 and lesser than MAZE_MAX_ROWS.
 * @param height to check
 * @return 1 if the conditions above are false, 0 otherwise.
 */
int check_for_valid_height(int height);

/* Ask the user to enter difficulty of the maze (1: EASY 2: HARD)
 * @return the maze difficulty enter 1 or 2
 */
int ask_for_difficulty();

/* Check is the difficulty is valid (1 or 2)/
 * @param dif difficulty enter by the user
 * @return 1 if the difficulty isn't valid, 0 otherwise
 */
int check_for_valid_difficulty(int dif);

/* Saves the maze in the file "<name>.cfg".
 * @param maze to save
 * @param name maze name (file name too)
 */
void save_maze (Maze *maze, char *name);

#endif
