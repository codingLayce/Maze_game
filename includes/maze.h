#ifndef MAZE_H_GUARD
#define MAZE_H_GUARD

#include "cell.h"
#include "config.h"

/* Represents the maze. Fields:
 * Rows: The height of the maze
 * Cols: The width of the maze
 * Name: The name of the maze (not included the file extension)
 * Board: A matrix of Cell that represents each cell of the board
 * Difficulty: 1 or 2 (1 EASY; 2 HARD)
 */
typedef struct {
	int rows;
	int cols;
	char name[MAX_NAME_SIZE];
	Cell board[MAZE_MAX_ROWS][MAZE_MAX_COLS];
	int difficulty;
} Maze;

/* Fills up the structure with the given parameters.
 * The board is initialize as follow:
 * #########
 * # # # # #
 * #########
 * # # # # #
 * #########
 *
 * @param maze to update
 * @param width to set to the cols field
 * @param height to set to the rows field
 * @param difficulty to set
 */
void init_maze(Maze *maze, int width, int height, int difficulty);

/* Displays the maze in the console
 */
void display_maze (Maze *maze);

/* Chooses a random cell of the given type in the maze.
 * @param maze to choose from
 * @param type the cell type of the random one
 * @return a random cell of type <type>
 */
Cell *get_random_cell_with_type (Maze *maze, cell_type type);

#endif
