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
					load_lang_en();
					return 0;
				}
			}
		}
	}
	return 1;
}

void load_lang_fr() {
	CREATE_MAZE_TEXT = malloc(sizeof(char) * strlen("Créer un labyrinthe") + 1);
	strcpy(CREATE_MAZE_TEXT, "Créer un labyrinthe");

	LOAD_MAZE_TEXT = malloc(sizeof(char) * strlen("Charger un labyrinthe") + 1);
	strcpy(LOAD_MAZE_TEXT, "Charger un labyrinthe");

	PLAY_TEXT = malloc(sizeof(char) * strlen("Jouer") + 1);
	strcpy(PLAY_TEXT, "Jouer");

	QUIT_TEXT = malloc(sizeof(char) * strlen("Quitter") + 1);
	strcpy(QUIT_TEXT, "Quitter");

	LOADED_MAZE_TEXT = malloc(sizeof(char) * strlen("Un labyrinthe a été chargé !\n") + 1);
	strcpy(LOADED_MAZE_TEXT, "Un labyrinthe a été chargé !\n");

	ERROR_NO_MAZE_LOADED = malloc(sizeof(char) * strlen("Vous devez charger ou créer un labyrinthe avant de jouer !\n") + 1);
	strcpy(ERROR_NO_MAZE_LOADED, "Vous devez charger ou créer un labyrinthe avant de jouer !\n");

	ENTER_MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Entrez un nom pour le labyrinthe (sans espaces):\n") + 1);
	strcpy(ENTER_MAZE_NAME_TEXT, "Entrez un nom pour le labyrinthe (sans espaces):\n");

	ENTER_MAZE_WIDTH_TEXT = malloc(sizeof(char) * strlen("Entrez la largeur du labyrinthe:\n") + 1);
	strcpy(ENTER_MAZE_WIDTH_TEXT, "Entrez la largeur du labyrinthe:\n");

	ENTER_MAZE_HEIGHT_TEXT = malloc(sizeof(char) * strlen("Entrez la hauteur du labyrinthe:\n") + 1);
	strcpy(ENTER_MAZE_HEIGHT_TEXT, "Entrez la hauteur du labyrinthe:\n");

	GAME_SCORE_TEXT = malloc(sizeof(char) * strlen("Score actuel: ") + 1);
	strcpy(GAME_SCORE_TEXT, "Score actuel: ");

	TOP_OF_GAME_TEXT = malloc(sizeof(char) * strlen("Essayez d'obtenir le score le plus petit !\n") + 1);
	strcpy(TOP_OF_GAME_TEXT, "Essayez d'obtenir le score le plus petit !\n");

	MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Vous jouez sur le labyrinthe ") + 1);
	strcpy(MAZE_NAME_TEXT, "Vous jouez sur le labyrinthe ");

	MAZE_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Le record sur ce labyrinthe est de ") + 1);
	strcpy(MAZE_HIGHSCORE_TEXT, "Le record sur ce labyrinthe est de ");

	NEW_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Votre score fait parti des 10 meilleurs !\n") + 1);
	strcpy(NEW_HIGHSCORE_TEXT, "Votre score fait parti des 10 meilleurs !\n");

	ENTER_PSEUDO_TEXT = malloc(sizeof(char) * strlen("Entrez votre pseudo:\n") + 1);
	strcpy(ENTER_PSEUDO_TEXT, "Entrez votre pseudo:\n");

	ENTER_MAZE_DIFFICULTY_TEXT = malloc(sizeof(char) * strlen("Sélectionnez une difficulté (1: facile 2: difficile):\n") + 1);
	strcpy(ENTER_MAZE_DIFFICULTY_TEXT, "Sélectionnez une difficulté (1: facile 2: difficile):\n");

	PRESS_RETURN_TEXT = malloc(sizeof(char) * strlen("Appuyez sur entrée...\n") + 1);
	strcpy(PRESS_RETURN_TEXT, "Appuyez sur entrée...\n");

	DEFEAT_TEXT = malloc(sizeof(char) * strlen("Vous avez été attrapé par un monstre !\n") + 1);
	strcpy(DEFEAT_TEXT, "Vous avez été attrapé par un monstre !\n");

	ERROR_NULL_LIST = malloc(sizeof(char) * strlen("Erreur: La liste est vide") + 1);
	strcpy(ERROR_NULL_LIST, "Erreur: La liste est vide");

	ERROR_OPENING_FILE = malloc(sizeof(char) * strlen("Error: Impossible d'ouvrir le fichier") + 1);
	strcpy(ERROR_OPENING_FILE, "Error: Impossible d'ouvrir le fichier");

	ERROR_NO_HIGHSCORE = malloc(sizeof(char) * strlen("Erreur: Pas de highscore") + 1);
	strcpy(ERROR_NO_HIGHSCORE, "Erreur: Pas de highscore");

	MAZE_GENERATED_TEXT = malloc(sizeof(char) * strlen("Ce labyrinthe a été généré: ") + 1);
	strcpy(MAZE_GENERATED_TEXT, "Ce labyrinthe a été généré: ");

	SAVING_MAZE_TEXT = malloc(sizeof(char) * strlen("Sauvegarde du labyrinthe dans le fichier saves/") + 1);
    	strcpy(SAVING_MAZE_TEXT, "Sauvegarde du labyrinthe dans le fichier saves/");

    	ERROR_WRITING_FILE = malloc(sizeof(char) * strlen("Erreur: Ecriture dans le fichier") + 1);
    	strcpy(ERROR_WRITING_FILE, "Erreur: Ecriture dans le fichier");

    	SELECT_MAZE_TEXT = malloc(sizeof(char) * strlen("Choisissez un labyrinthe parmis les fichiers suivants:") + 1);
    	strcpy(SELECT_MAZE_TEXT, "Choisissez un labyrinthe parmis les fichiers suivants:");

    	ERROR_READING_FILE = malloc(sizeof(char) * strlen("Erreur: Lecture du fichier") + 1);
    	strcpy(ERROR_READING_FILE, "Erreur: Lecture du fichier");
}

void load_lang_en() {
	CREATE_MAZE_TEXT = malloc(sizeof(char) * strlen("Create maze") + 1);
	strcpy(CREATE_MAZE_TEXT, "Create maze");

	LOAD_MAZE_TEXT = malloc(sizeof(char) * strlen("Load a maze") + 1);
	strcpy(LOAD_MAZE_TEXT, "Load a maze");

	PLAY_TEXT = malloc(sizeof(char) * strlen("Play") + 1);
	strcpy(PLAY_TEXT, "Play");

	QUIT_TEXT = malloc(sizeof(char) * strlen("Quit") + 1);
	strcpy(QUIT_TEXT, "Quit");

	LOADED_MAZE_TEXT = malloc(sizeof(char) * strlen("A maze has been loaded !\n") + 1);
	strcpy(LOADED_MAZE_TEXT, "A maze has been loaded !\n");

	ERROR_NO_MAZE_LOADED = malloc(sizeof(char) * strlen("You have to create or load a maze before play !\n") + 1);
	strcpy(ERROR_NO_MAZE_LOADED, "You have to create or load a maze before play !\n");

	ENTER_MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("Enter a name for the maze (no spaces):\n") + 1);
	strcpy(ENTER_MAZE_NAME_TEXT, "Enter a name for the maze (no spaces):\n");

	ENTER_MAZE_WIDTH_TEXT = malloc(sizeof(char) * strlen("Enter the maze width:\n") + 1);
	strcpy(ENTER_MAZE_WIDTH_TEXT, "Enter the maze width:\n");

	ENTER_MAZE_HEIGHT_TEXT = malloc(sizeof(char) * strlen("Enter the maze height:\n") + 1);
	strcpy(ENTER_MAZE_HEIGHT_TEXT, "Enter the maze height:\n");

	GAME_SCORE_TEXT = malloc(sizeof(char) * strlen("Current score: ") + 1);
	strcpy(GAME_SCORE_TEXT, "Current score: ");

	TOP_OF_GAME_TEXT = malloc(sizeof(char) * strlen("Try to get the lowest score !\n") + 1);
	strcpy(TOP_OF_GAME_TEXT, "Try to get the lowest score !\n");

	MAZE_NAME_TEXT = malloc(sizeof(char) * strlen("You are playing the maze ") + 1);
	strcpy(MAZE_NAME_TEXT, "You are playing the maze ");

	MAZE_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("The maze record is ") + 1);
	strcpy(MAZE_HIGHSCORE_TEXT, "The maze record is ");

	NEW_HIGHSCORE_TEXT = malloc(sizeof(char) * strlen("Your score is part of the 10 best !\n") + 1);
	strcpy(NEW_HIGHSCORE_TEXT, "Your score is part of the 10 best !\n");

	ENTER_PSEUDO_TEXT = malloc(sizeof(char) * strlen("Enter your pseudo:\n") + 1);
	strcpy(ENTER_PSEUDO_TEXT, "Enter your pseudo:\n");

	ENTER_MAZE_DIFFICULTY_TEXT = malloc(sizeof(char) * strlen("Select a difficulty (1: EASY 2: HARD):\n") + 1);
	strcpy(ENTER_MAZE_DIFFICULTY_TEXT, "Select a difficulty (1: EASY 2: HARD):\n");

	PRESS_RETURN_TEXT = malloc(sizeof(char) * strlen("Press enter key...\n") + 1);
	strcpy(PRESS_RETURN_TEXT, "Press enter key...\n");

	DEFEAT_TEXT = malloc(sizeof(char) * strlen("A monster caught you !\n") + 1);
	strcpy(DEFEAT_TEXT, "A monster caught you !\n");

	ERROR_NULL_LIST = malloc(sizeof(char) * strlen("Error: Empty list") + 1);
	strcpy(ERROR_NULL_LIST, "Error: Empty list");

	ERROR_OPENING_FILE = malloc(sizeof(char) * strlen("Error: Impossible to open the file") + 1);
	strcpy(ERROR_OPENING_FILE, "Error: Impossible to open the file");

	ERROR_NO_HIGHSCORE = malloc(sizeof(char) * strlen("Error: No highscore") + 1);
	strcpy(ERROR_NO_HIGHSCORE, "Error: No highscore");

	MAZE_GENERATED_TEXT = malloc(sizeof(char) * strlen("This maze has been generated: ") + 1);
	strcpy(MAZE_GENERATED_TEXT, "This maze has been generated: ");

	SAVING_MAZE_TEXT = malloc(sizeof(char) * strlen("Saving the maze in the file saves/") + 1);
	strcpy(SAVING_MAZE_TEXT, "Saving the maze in the file saves/");

   	ERROR_WRITING_FILE = malloc(sizeof(char) * strlen("Error: Writing in the file") + 1);
    	strcpy(ERROR_WRITING_FILE, "Error: Writing in the file");

    	SELECT_MAZE_TEXT = malloc(sizeof(char) * strlen("Select a maze from the list below:") + 1);
    	strcpy(SELECT_MAZE_TEXT, "Select a maze from the list below:");

    	ERROR_READING_FILE = malloc(sizeof(char) * strlen("Error: Reading the file") + 1);
	strcpy(ERROR_READING_FILE, "Error: Reading the file");
}

void free_config() {
	free(CREATE_MAZE_TEXT);
	free(LOAD_MAZE_TEXT);
	free(PLAY_TEXT);
	free(QUIT_TEXT);
	free(LOADED_MAZE_TEXT);
	free(ERROR_NO_MAZE_LOADED);
	free(ENTER_MAZE_NAME_TEXT);
	free(ENTER_MAZE_WIDTH_TEXT);
	free(ENTER_MAZE_HEIGHT_TEXT);
	free(GAME_SCORE_TEXT);
	free(TOP_OF_GAME_TEXT);
	free(MAZE_NAME_TEXT);
	free(MAZE_HIGHSCORE_TEXT);
	free(NEW_HIGHSCORE_TEXT);
	free(ENTER_PSEUDO_TEXT);
	free(ENTER_MAZE_DIFFICULTY_TEXT);
	free(PRESS_RETURN_TEXT);
	free(DEFEAT_TEXT);
	free(ERROR_NULL_LIST);
	free(ERROR_OPENING_FILE);
	free(ERROR_NO_HIGHSCORE);
	free(MAZE_GENERATED_TEXT);
	free(SAVING_MAZE_TEXT);
	free(ERROR_WRITING_FILE);
	free(SELECT_MAZE_TEXT);
	free(ERROR_READING_FILE);
}
