#include <stdio.h>
#include <stdlib.h>
#include "../utils/config.h"
#include "highscores.h"
#include "../utils/utils.h"

List *load_highscores (Maze *maze) {
	char path[MAX_NAME_SIZE+20];
	FILE *file;
	List *list = NULL;
	char pseudo[MAX_PSEUDO_SIZE];
	int score;
	Highscore *previous;
	int elements, i;

	sprintf(path, "./saves/%s.score", maze->name);

	file = fopen(path, "r");
	if (file == NULL) {
		return NULL;
	}
	
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
		fprintf(stderr, "\n Error list is empty\n");
		return;
	}

	elements = nb_elements(list);
	tmp = list->best;

	sprintf(path, "./saves/%s.score", maze->name);

	file = fopen(path, "w+");
	if (file == NULL) {
		fprintf(stderr, "\n Error while opening the file\n");
		exit(1);
	}

	fprintf(file, "%d\n", elements);

	while (tmp != NULL) {
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

	tmp = get_highscore(list, index);
	
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
	Highscore *tmp = list->best;

	if (list == NULL || list->best == NULL) {
		return NULL;
	}

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
		printf("Pas encore de highscores !\n");
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
