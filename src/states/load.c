/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* documents may be reproduced, copied or revised without written
* permission of the authors.
*
* @author Lucas Guilbert <lguilbert@ecole.ensicaen.fr>
* @version 1.0
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#include "load.h"
#include "maze.h"
#include "utils.h"
#include "config.h"

int load_maze (Maze *maze) {
	DIR *saves_folder;
	int i = 0;
	int choice;
	/* I am counting the number of existing files in the saves folder to allocate the memory.  */
	int nb_saves = get_nb_of_files_in_dir(PATH_TO_SAVES);
	/* I reserve the right space to save the dirent structure. 
	 * I doing it this way because for me it's easier to understand.
	 * And to retrieve the file i'll just have to make "saves[<choice>-1]". 
	 */
	struct dirent **saves = calloc(nb_saves, sizeof(struct dirent*));

    if (nb_saves > 0) {
        do {
            system(CLEAR_COMMAND);
            printf("%s\n", SELECT_MAZE_TEXT);
            i = 0;

            saves_folder = opendir(PATH_TO_SAVES);
            if (saves_folder) {
                struct dirent *file;
                while ((file = readdir(saves_folder)) != NULL) { /* For each file in the folder */
                    if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) { /* Exclude . and .. */
                        char *point = file->d_name + sizeof(file->d_name);
                        if ((point = strrchr(file->d_name, '.')) != NULL) { /* Move the cursor point to the '.' character if exist */
                            if (strcmp(point, ".cfg") == 0) { /* Check for .cfg extension */
                                printf("%d - %s\n", i+1, file->d_name);
                                saves[i] = file;
                                i++;
                            }
                        }
                    }
                }
                closedir(saves_folder);
            }

            choice = read_int();
        } while (choice < 1 || choice > nb_saves);

        load_file(maze, saves[choice-1]->d_name);

	    free(saves);

	    return 1;
	}

    printf("%s\n", NO_SAVES_TEXT);
    printf("%s", PRESS_RETURN_TEXT);
    read_key();

    return 0;

}

void load_file (Maze *maze, char *name) {
	FILE *file;
	char path[40];

	sprintf(path, "%s%s", PATH_TO_SAVES, name);

	file = fopen(path, "r");
	if (file == NULL) {
		fprintf(stderr, "\n%s\n", ERROR_OPENING_FILE);
		exit(1);
	}

	fread(maze, sizeof(Maze), 1, file);
	if (maze == NULL) {
		fprintf(stderr, "\n%s\n", ERROR_READING_FILE);
		exit(1);
	}

	fclose(file);
}

int get_nb_of_files_in_dir (char *path) {
	int n = 0;
	DIR *dir;

    /* Same logic that in the load_maze function */
	dir = opendir(path);
	if (dir) {
		struct dirent *f;
		while ((f = readdir (dir)) != NULL) {
			if (strcmp(f->d_name, ".") != 0 && strcmp(f->d_name, "..") != 0) {
				char *point = f->d_name + strlen(f->d_name);
				if ((point = strrchr(f->d_name, '.')) != NULL) {
					if (strcmp(point, ".cfg") == 0) {
						++n;
					}
				}
			}
		}
		closedir(dir);
	}

	return n;
}
