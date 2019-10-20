#ifndef LOAD_H_GUARD
#define LOAD_H_GUARD

#include "maze.h"

/* Loads the maze that the user will select in a list displayed on the console.
 * @param maze to fill up
 * @return 1 if a maze has been load, 0 otherwise
 */
int load_maze (Maze *maze);

/* Counts the number of files in the directory.
 * @param the saves folder path
 * @return the number of files (extension .cfg)
 */
int get_nb_of_files_in_dir (char *path);

/* Fills up the maze structure with the one in the given file.
 * @param maze to fill up
 * @param name of the file to load
 */
void load_file (Maze *maze, char *name);

#endif
