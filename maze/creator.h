#ifndef MAZECREATOR_H_GUARD
#define MAZECREATOR_H_GUARD
#include "maze.h"

/* Generates a random perfect maze depending of the difficulty and initializes the structure.
 * @param maze to generate
 * @param difficulty 1 (EASY) or 2 (HARD); EASY: Generates a perfect maze; HARD: Generates a perfect maze plus some others ways.
 */
void generate_maze (Maze *maze, int difficulty);

/* Checks if the labyrinth can be done.
 * It check if every EMPTY cell of the maze has a the same value.
 * @param maze to check
 * @return 0 if so, 1 otherwise.
 */
int check_for_perfect_labyrinthe (Maze *maze);

/* Scan all the cells of a way and set there value to same has the others recursively.
 * @param maze to update
 * @param row the x position of the cell to update
 * @param col the y position of the cell to update
 * @param value the value that all the cells of the way needs to have
 */
void scan_neighbor(Maze *maze, int row, int col, int value);

/* Determines the value that a new cell will get.
 * The algorithm takes the highest value of the cell's neighbors.
 * @param maze to update
 * @param row the x position of the cell to update
 * @param col the y position of the cell to update
 * @return the value to give to the cell
 */
int get_first_value(Maze *maze, int row, int col);

/* Checks if the given cell at the position (row;col) can be remove.
 * A Wall can be removed if there is exactly 2 near by empty cells, those one are on the same row or the same col and their value are different.
 *
 * ####### Here 1,2 and 3 are walls. 1 cannot be removed, because he is surrounded by walls.
 * # 2 # # 2 can be removed, because he is surrounded by exactly 2 empty cells and they are on the same row.
 * #3##1## 3 can be removed, because he is surrounded by exactly 2 empty cells and they are on the same col.
 * # # # #
 * #######
 *
 * @param maze to update
 * @param row the x position of the cell to check
 * @param col the y position of the cell to check
 * @param more 1 or 0, if 1 a Wall can be remove even if the maze is still perfect (used for the hard difficulty)
 * @return 0 if the cell can be remove, 1 otherwise
 */
int check_for_valid_wall_to_remove(Maze *maze, int row, int col, int more);

/* Generates randomly some treasures on empty cells.
 * @param maze to update
 */
void generate_treasures(Maze *maze);

/* Generates randomly some traps on empty cells.
 * @param maze to update
 */
void generate_traps(Maze *maze);

#endif
