#ifndef HIGHSCORE_H_GUARD
#define HIGHSCORE_H_GUARD

#include "maze.h"
#include "config.h"

typedef struct Highscore Highscore;
typedef struct List List;

/* Represents a highscore.
 * It store the score and the pseudo of the player.
 * It's also an element of a list, that's why the field
 * next_score is pointing to an other highscore
 */
struct Highscore {
	int score;
	char pseudo[MAX_PSEUDO_SIZE];
	Highscore *next_score;
};

/* Represents a linked list.
 * It store the best highscore.
 */
struct List {
	Highscore *best;
};

/* Load all the highscores (if they exists), from the file named:
 * saves/<maze_name>.score, and store them in the list List.
 * @param maze to load the highscores
 * @return the list generated with the highscores
 */
List *load_highscores (Maze *maze);

/* Inserts a highscore in a list at the given index.
 * @param list to update
 * @param score to insert
 * @param index position of the score to insert
 * @return the list updated
 */
List *insert_highscore (List *list, Highscore *score, int index);

/* Checks if the score can be put in the 10 best list.
 * @param list containing the 10 best highscores
 * @param score the score value
 * @return -1 if the score can't be put in the list otherwise the index [0-9]
 */
int get_insertion_index(List *list, int score);

/* Counts the number of elements inside the list
 * @param list to count
 * @return the number of elements
 */
int nb_elements (List *list);

/* Search for the highscore at the given index in the given list.
 * @param list to search
 * @param index position of the highscore to return
 * @return the highscore at the given position
 */
Highscore *get_highscore (List *list, int index);

/* Saves the highscore list in the file named:
 * saves/<maze_name>.score.
 * @param list to save
 * @param maze which contains the maze name
 */
void save_highscores (List *list, Maze *maze);

/* Display the list of highscores.
 * @param list to display
 */
void display_list (List *list);

/* Unloads the given list by free each of the highscore inside an it self.
 * @param list to free in memory
 */
void unload_list (List *list);

#endif
