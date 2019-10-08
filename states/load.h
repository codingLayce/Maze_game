#ifndef LOAD_H_GUARD
#define LOAD_H_GUARD

#include "../maze/maze.h"

void load_maze (Maze *maze);

/* Function that count the number of files in the directory.
 * Return the number of files (excluding . and ..).
 */
int get_nb_of_files_in_dir (char *path);


void load_file (Maze *maze, char *name);

#endif
