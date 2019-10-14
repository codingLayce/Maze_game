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
#include "../utils/config.h"
#include "highscores.h"
#include "../utils/utils.h"

List *load_highscores (Maze *maze) {
	char path[MAX_NAME_SIZE+20];
	char pseudo[MAX_PSEUDO_SIZE];
	FILE *file;
	List *list = NULL;
	int score, elements, i;
	Highscore *previous;

	sprintf(path, "./saves/%s.score", maze->name);

	file = fopen(path, "r");
	if (file == NULL) {
		return NULL;
	}

	/* The first line of the file is the number of elements written in the file */
	fscanf(file, "%d", &elements);

	for (i = 0; i < elements; i++){
		Highscore *tmp = malloc(sizeof(*tmp));

		fscanf(file, "%s", pseudo);
		fscanf(file, "%d", &score);

		copy_string(tmp->pseudo, pseudo, sizeof(pseudo));
		tmp->score = score;
		tmp->next_score = NULL;		

		if (list == NULL) {
			list = malloc(sizeof(*list));
			list->best = tmp;
			previous = list->best;
		} else {
			previous->next_score = tmp;
			previous = previous->next_score;
		}
	}

	fclose(file);

	return list;
}

void save_highscores (List *list, Maze *maze) {
	FILE *file;
	char path[MAX_NAME_SIZE+20];
	Highscore *tmp;
	int elements;

	if (list == NULL || list->best == NULL) {
		fprintf(stderr, "\n%s\n", ERROR_NULL_LIST);
		return;
	}

	elements = nb_elements(list);
	tmp = list->best;

	sprintf(path, "./saves/%s.score", maze->name);

	file = fopen(path, "w+");
	if (file == NULL) {
		fprintf(stderr, "\n%s\n", ERROR_OPENING_FILE);
		exit(1);
	}

	/* First i write the number of elements to facilitate the load function */
	fprintf(file, "%d\n", elements);

	while (tmp != NULL) {
		/* Then a loop through the scores and saves them 1 by line "<pseudo> <score>" */
		fprintf(file, "%s %d\n", tmp->pseudo, tmp->score);
		tmp = tmp->next_score;
	}

	fclose(file);
}

List *insert_highscore (List *list, Highscore *score, int index) {	
	Highscore *tmp;
	Highscore *last;

	if (list == NULL) {
		list = malloc(sizeof(*list));
		list->best = NULL;
	}

	tmp = get_highscore(list, index-1);

	if (tmp == NULL) {
		list->best = score;
	} else if (index == 0) {
		list->best = score;
		score->next_score = tmp;	
	} else {
		score->next_score = tmp->next_score;
		tmp->next_score = score;
	}

	if (nb_elements(list) > 10) {
		last = get_highscore(list, 10);
		last->next_score = NULL;
	}

	return list;
}

int nb_elements (List *list) {
	int i = 0;
	Highscore *tmp;

	if (list == NULL || list->best == NULL) {
		return -1;
	}

	tmp = list->best;

	while (tmp != NULL) {
		i++;
		tmp = tmp->next_score;
	}

	return i;
}

Highscore *get_highscore (List *list, int index) {
	int i = 0;
	Highscore *tmp;

	if (list == NULL || list->best == NULL) {
		return NULL;
	}

	tmp = list->best;

	while (i < index) {
		tmp = tmp->next_score;
		i++;
	}

	return tmp;
}

void display_list (List *list) {
	Highscore *tmp;
	int i = 1;

	if (list == NULL || list->best == NULL) {
		printf("%s\n", ERROR_NO_HIGHSCORE);
		return;
	}

	tmp = list->best;

	while (tmp != NULL) {
		printf("%d - %s: %d\n", i, tmp->pseudo, tmp->score);
		i++;
		tmp = tmp->next_score;
	}
}

void unload_list (List *list) {
	Highscore *next;
	Highscore *current;

	if (list == NULL) {
		return;
	}

	current = list->best;

	while (current != NULL) {
		next = current->next_score;
		free(current);
		current = next;
	}

	free(list);
}
int get_insertion_index(List *list, int score) {
	int i = 0;
	Highscore *tmp;

	if (list == NULL) {
		return 0;
	} else {
		if (nb_elements(list) == 0) {
			return 0;
		} else { /* Search the index where the highscore can be put */
			tmp = list->best;
			while (tmp != NULL) {
				if (score < tmp->score && i < 10) {
					return i;
				}
				tmp = tmp->next_score;
				i++;
			}
			if (nb_elements(list) < 10)  { /* If no index has been found, it means that the highscore is the worst one */
				return nb_elements(list) -1;
			}
		}
	}

	return -1;
}
