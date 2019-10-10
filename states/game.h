#ifndef GAME_H_GUARD
#define GAME_H_GUARD
#include "../maze/maze.h"
#include "../maze/cell.h"
#include "../utils/config.h"
#include "../maze/highscores.h"

/* Executes the game logic.
 * This function contains the main loop of the game.
 */
void play (Maze *maze);

/* Checks if the player is on the exit cell.
 * @param maze played
 * @param player to be inspected
 * @return 0 if the player is on the exit cell, 1 otherwise
 */
int player_on_exit (Maze *maze, Player *player);

/* Updates the score when the player has moved depending of the new cell types.
 * @param maze played
 * @param player to be inspected
 * @param score pointer to the score variable to update it
 */
void update_score (Maze *maze, Player player, int *score);

/* Updates the given cell with the given cell type.
 * Mainly used to convert traps & treasures to empty cells.
 * @param cell to update
 * @param type the new cell type of the given cell
 */
void update_cell_type (Cell *cell, cell_type type);

/* Checks if the score made by the player can be part of the highscores.
 * If so, update the list and returns it. (i return it because even if i passed
 * a list pointer, the list isn't changed, whereas when i return it, it works..)
 * @param maze played
 * @param scores list that contains the 10 best highscores
 * @param score made by the player
 * @return the list updated
 */
List *check_for_best_score (Maze *maze, List *scores, int score);

/* Displays the best highscores on the console.
 * @param list of the best highscores
 */
void display_highscores(List *list);

/* Initializes the ghost starting position randomly if the difficulty is set to HARD.
 * @param maze to update
 * @param ghost to initialize
 */
void init_ghost(Maze *maze, Player *ghost);

/* Updates the ghost position and checks before moving and after moving if the ghost and the player are on the same cell.
 * If so, the player is killed and the game ends.
 * @param maze played
 * @param ghost that is moving
 * @param player to check his position
 * @return 0 if the player is killed, 1 otherwise
 */
int update_ghost(Maze *maze, Player *ghost, Player player);

#endif
