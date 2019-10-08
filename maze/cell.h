#ifndef CELL_H_GUARD
#define CELL_H_GUARD

#include "player.h"

/* Represents the type of the cell.
 * EMPTY: Nothing in it,
 * WALL: It's a wall,
 * TREASURE: There is a treasure in it,
 * TRAP: There is a trap in it.
 */
typedef enum {EMPTY, WALL, TREASURE, TRAP}cell_type;

/* Represents a Cell.
 * The field value is used for the maze generation.
 * A cell can point to a Player, which means there is a Player in it.
 */
typedef struct {
	cell_type type;
	int value;
	Player *player;
} Cell;

/* Initializes the given cell with the given values.
 * By default the pointer to a Player is set to NULL.
 * @param cell to initialize
 * @param type the cell type
 * @param value the initial value of the cell (see perfect maze algorithm)
 */
void new_cell (Cell *cell, cell_type type, int value);

/* Displays the cell information (ONLY FOR DEBUG)
 * @param cell to display
 */
void display_cell (Cell *cell);

/* Returns the skin (the representation with a character) of the given cell.
 * @param cell to get the skin
 * @return the skin of the cell.
 */
char get_cell_skin (Cell cell);

/* Determines the number of points to give to the player score
 * @param cell to determine
 * @return the number of points
 */
int get_points(Cell *cell);

/* Sets the pointer to a Player to the given player.
 * @param cell to change the player's pointer
 * @param player to point on
 */
void set_player(Cell *cell, Player *player);

/* Displays the player color (ex: "\033[35m;") this change the next text color.
 * @param cell to display the player's color
 */
void display_player_color(Cell cell);

#endif
