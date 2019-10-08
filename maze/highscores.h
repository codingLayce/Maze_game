#ifndef HIGHSCORE_H_GUARD
#define HIGHSCORE_H_GUARD

#include "maze.h"
#include "../utils/config.h"

typedef struct Highscore Highscore;
typedef struct List List;

struct Highscore {
	int score;
	char pseudo[MAX_PSEUDO_SIZE];
	Highscore *next_score;
};

struct List {
	Highscore *best;
};

List *load_highscores (Maze *maze);
List *insert_highscore (List *list, Highscore *score, int index);
int nb_elements (List *list);
Highscore *get_highscore (List *list, int index);
void save_highscores (List *list, Maze *maze);
void display_list (List *list);
void unload_list (List *list);

#endif
