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
				} else if (strcmp(lang, "en") == 0) {
				    load_lang_english();
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

void load_lang_english() {
CREATE_MAZE_TEXT = malloc(sizeof(char) * strlen("Create a maze"));
	CREATE_MAZE_TEXT = "Create a maze";

	LOAD_MAZE_TEXT = malloc(sizeof(char) * strlen("Load a maze"));
	LOAD_MAZE_TEXT = "Load a maze";

	PLAY_TEXT = malloc(sizeof(char) * strlen("Play"));
	PLAY_TEXT = "Play";

	QUIT_TEXT = malloc(sizeof(char) * strlen("Quit"));
	QUIT_TEXT = "Quit";

	LOADED_MAZE_TEXT = malloc(sizeof(char) * strlen("A maze has been loaded!\n"));
	LOADED_MAZE_TEXT = "A maze has been loaded !\n";

	ERROR_NO_MAZE_LOADED = malloc(sizeof(char) * strlen("You have to create or load a maze before play !\n"));
	ERROR_NO_MAZE_LOADED = "You have to create or load a maze before play !\n";

	ENTER_MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Enter a name for the maze (no spaces):\n"));
	ENTER_MAZE_NAME_TEXT = "Enter a name for the maze (no spaces):\n";

	ENTER_MAZE_WIDTH_TEXT = malloc(sizeof(char) * strlen("Enter the maze width:\n"));
	ENTER_MAZE_WIDTH_TEXT = "Enter the maze width:\n";

	ENTER_MAZE_HEIGHT_TEXT = malloc(sizeof(char) * strlen("Enter the maze height:\n"));
	ENTER_MAZE_HEIGHT_TEXT = "Enter the maze height:\n";

	GAME_SCORE_TEXT = malloc(sizeof(char) * strlen("Current score: "));
	GAME_SCORE_TEXT = "Current score: ";

	TOP_OF_GAME_TEXT = malloc(sizeof(char) * strlen("Try to get the lowest score !\n"));
	TOP_OF_GAME_TEXT = "Try to get the lowest score !\n";

	MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("You are playing the maze "));
	MAZE_NAME_TEXT = "You are playing the maze ";

	MAZE_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("The maze record is "));
	MAZE_HIGHSCORE_TEXT = "The maze record is ";

	NEW_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Your score is part of the 10 best !\n"));
	NEW_HIGHSCORE_TEXT = "Your score is part of the 10 best !\n";

	ENTER_PSEUDO_TEXT = malloc(sizeof(char) * strlen("Enter your pseudo:\n"));
	ENTER_PSEUDO_TEXT = "Enter your pseudo:\n";

	ENTER_MAZE_DIFFICULTY_TEXT = malloc(sizeof(char) * strlen("Select a difficulty (1: EASY 2: HARD):\n"));
	ENTER_MAZE_DIFFICULTY_TEXT = "Select a difficulty (1: EASY 2: HARD):\n";

	PRESS_RETURN_TEXT = malloc(sizeof(char) * strlen("Press enter key...\n"));
	PRESS_RETURN_TEXT = "Press enter key...\n";

	DEFEAT_TEXT = malloc(sizeof(char) * strlen("A monster caught you !\n"));
	DEFEAT_TEXT = "A monster caught you !\n";
}