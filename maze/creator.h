#ifndef MAZECREATOR_H_GUARD
#define MAZECREATOR_H_GUARD
#include "maze.h"

void generate_maze (Maze *maze, int difficulty);

/* Function that check if the labyrinthe can be done.
 * It check if every EMPTY cell of the maze has a the same value.
 * Returns 0 if so, 1 otherwise.
 */
int check_for_perfect_labyrinthe (Maze *maze);

/* Function that scan all the cell of a way and set there value to same has the others. 
 */
void scan_neighbor(Maze *maze, int row, int col, int value);

/* Function that return the value to give to the slected cell. 
 */
int get_first_value(Maze *maze, int row, int col);

/* Function that check if the cell at the position (row;col) can be remove.
 * A Wall can be removed if there is exactly 2 near by empty cells, those one are on the same row or the same col and there value are different.
 * Returns 0 if the cell can be removed, 1 otherwise.
 *
 * ####### Here 1,2 and 3 are walls. 1 cannot be removed, because he is surronded by walls.
 * # 2 # # 2 can be removed, because he is surronded by exaclty 2 empty cells and they are on the same row.
 * #3##1## 3 can be removed, because he is surronded by exaclty 2 empty cells and they are on the same col.
 * # # # #
 * #######
 */
int check_for_valid_wall_to_remove(Maze *maze, int row, int col, int more);

/* Function that put randomly some treasures on empty cells.
 */
void generate_treasures(Maze *maze);

/* Function that put randomly some traps on empty cells.
 */
void generate_traps(Maze *maze);

#endif
