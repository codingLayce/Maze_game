#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "utils.h"

int check_for_config_params(int argc, char **argv) {
	char lang[4];

	if (argc > 1) {
		if (strcmp(argv[1], "-lang") == 0) {
			if (argc > 2) {
				copy_string(lang, argv[2], strlen(argv[2]));
				if (strcmp(lang, "fr") == 0) {
					load_lang_fr();	
					return 0;
				}
			}
		}
	}
	return 1;
}

void load_lang_fr() {
	CREATE_MAZE_TEXT = malloc(sizeof(char) * strlen("Créer un labyrinthe"));
	CREATE_MAZE_TEXT = "Créer un labyrinthe";

	LOAD_MAZE_TEXT = malloc(sizeof(char) * strlen("Charger un labyrinthe"));
	LOAD_MAZE_TEXT = "Charger un labyrinthe";

	PLAY_TEXT = malloc(sizeof(char) * strlen("Jouer"));
	PLAY_TEXT = "Jouer";

	QUIT_TEXT = malloc(sizeof(char) * strlen("Quitter"));
	QUIT_TEXT = "Quitter";

	LOADED_MAZE_TEXT = malloc(sizeof(char) * strlen("Un labyrinthe a été chargé !\n"));
	LOADED_MAZE_TEXT = "Un labyrinthe a été chargé !\n";

	ERROR_NO_MAZE_LOADED = malloc(sizeof(char) * strlen("Vous devez charger ou créer un labyrinthe avant de jouer !\n"));
	ERROR_NO_MAZE_LOADED = "Vous devez charger ou créer un labyrinthe avant de jouer !\n";

	ENTER_MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Entrez un nom pour le labyrinthe (sans espaces):\n"));
	ENTER_MAZE_NAME_TEXT = "Entrez un nom pour le labyrinthe (sans espaces):\n";

	ENTER_MAZE_WIDTH_TEXT = malloc(sizeof(char) * strlen("Entrez la largeur du labyrinthe:\n"));
	ENTER_MAZE_WIDTH_TEXT = "Entrez la largeur du labyrinthe:\n";

	ENTER_MAZE_HEIGHT_TEXT = malloc(sizeof(char) * strlen("Entrez la hauteur du labyrinthe:\n"));
	ENTER_MAZE_HEIGHT_TEXT = "Entrez la hauteur du labyrinthe:\n";

	GAME_SCORE_TEXT = malloc(sizeof(char) * strlen("Score actuel: "));
	GAME_SCORE_TEXT = "Score actuel: ";

	TOP_OF_GAME_TEXT = malloc(sizeof(char) * strlen("Essayez d'obtenir le score le plus petit !\n"));
	TOP_OF_GAME_TEXT = "Essayez d'obtenir le score le plus petit !\n";

	MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Vous jouez sur le labyrinthe "));
	MAZE_NAME_TEXT = "Vous jouez sur le labyrinthe ";

	MAZE_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Le record sur ce labyrinthe est de "));
	MAZE_HIGHSCORE_TEXT = "Le record sur ce labyrinthe est de ";

	NEW_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Votre score fait parti des 10 meilleurs !\n"));
	NEW_HIGHSCORE_TEXT = "Votre score fait parti des 10 meilleurs !\n";

	ENTER_PSEUDO_TEXT = malloc(sizeof(char) * strlen("Entrez votre pseudo:\n"));
	ENTER_PSEUDO_TEXT = "Entrez votre pseudo:\n";

	ENTER_MAZE_DIFFICULTY_TEXT = malloc(sizeof(char) * strlen("Sélectionnez une difficulté (1: facile 2: difficile):\n"));
	ENTER_MAZE_DIFFICULTY_TEXT = "Sélectionnez une difficulté (1: facile 2: difficile):\n";

	PRESS_RETURN_TEXT = malloc(sizeof(char) * strlen("Appuyez sur entrée...\n"));
	PRESS_RETURN_TEXT = "Appuyez sur entrée...\n";

	DEFEAT_TEXT = malloc(sizeof(char) * strlen("Vous avez été attrapé par un monstre !\n"));
	DEFEAT_TEXT = "Vous avez été attrapé par un monstre !\n";
}
