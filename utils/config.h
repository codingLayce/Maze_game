#ifndef CONFIG_H_GUARD
#define CONFIG_H_GUARD

/* SOlution found on stackoverflow: https://stackoverflow.com/questions/5459868/concatenate-int-to-string-using-c-preprocessor  */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define PATH_TO_SAVES "./saves/"
#define MAZE_MAX_ROWS 39
#define MAZE_MAX_COLS 59

#define WALL_COLOR "\033[35;45m"
#define EMPTY_COLOR "\033[107m"
#define PLAYER_COLOR "\033[34;44m"
#define GHOST_COLOR "\033[36;46m"
#define TREASURE_COLOR "\033[32;42m"
#define TRAP_COLOR "\033[31;41m"
#define DEFAULT_COLOR "\033[39;49m"

#define MAX_NAME_SIZE 30
#define MAX_PSEUDO_SIZE 20

#define STEP_SCORE 10
#define TREASURE_SCORE -50
#define TRAP_SCORE 50
#define NUMBER_OF_TRAPS 2
#define NUMBER_OF_TREASURE 2

#if defined(_WIN32)
#define CLEAR_COMMAND "cls"

#else
#define CLEAR_COMMAND "clear"
#endif

/* TEXTS SECTION (All that are showing in the game are set below)  */
/* You have to define here FRENCH or ENGLISH  */
#define FRENCH

#if defined(FRENCH)
#define CREATE_MAZE_TEXT "Créer un labyrinthe"
#define LOAD_MAZE_TEXT "Charger un labyrinthe"
#define PLAY_TEXT "Jouer"
#define QUIT_TEXT "Quitter"
#define LOADED_MAZE_TEXT "Un labyrinthe a été chargé !\n"
#define ERROR_NO_MAZE_LOADED "Vous devez charger ou créer un labyrinthe avant de jouer !\n"
#define ENTER_MAZE_NAME_TEXT "Entrez un nom pour le labyrinthe (Max: " STR(MAX_NAME_SIZE) ", sans espaces):\n"
#define ENTER_MAZE_WIDTH_TEXT "Entrez la largeur du labyrinthe (Max: " STR(MAZE_MAX_COLS) "):\n"
#define ENTER_MAZE_HEIGHT_TEXT "Entrez la hauteur du labyrinthe (Max: " STR(MAZE_MAX_ROWS) "):\n"
#define GAME_SCORE_TEXT "Score actuel: "
#define TOP_OF_GAME_TEXT "Essayez d'optenir le score le plus petit !\n"
#define MAZE_NAME_TEXT "Vous jouez sur le labyrinthe "
#define MAZE_HIGHSCORE_TEXT "Le record sur ce labyrinthe est de "
#define NEW_HIGHSCORE_TEXT "Votre score fait parti des 10 meilleurs score !\n"
#define ENTER_PSEUDO_TEXT "Entrez votre pseudo (Max: " STR(MAX_PSEUDO_SIZE) "):\n"
#define ENTER_MAZE_DIFFICULTY_TEXT "Sélectionnez une difficultée (1: facile 2: difficile):\n"
#define PRESS_RETURN_TEXT "Appuyez sur entrée...\n"
#define DEFEAT_TEXT "Vous avez été attrapé par un monstre !\n"

#elif defined(ENGLISH)
#define CREATE_MAZE_TEXT "Create maze"
#define LOAD_MAZE_TEXT "Load maze"
#define PLAY_TEXT "Play"
#define QUIT_TEXT "Quit"
#define LOADED_MAZE_TEXT "A maze has been loaded !\n"
#define ERROR_NO_MAZE_LOADED "You have to load or create a maze before play !\n"
#define ENTER_MAZE_NAME_TEXT "Enter a name for the maze (Max: " STR(MAX_NAME_SIZE) ", no spaces):\n"
#define ENTER_MAZE_WIDTH_TEXT "Enter a width for the maze (Max: " STR(MAZE_MAX_COLS) "):\n"
#define ENTER_MAZE_HEIGHT_TEXT "Enter a height for the maze (Max: " STR(MAZE_MAX_ROWS) "):\n"
#define GAME_SCORE_TEXT "Current score: "
#define TOP_OF_GAME_TEXT "Try to get the minimum score !\n"
#define MAZE_NAME_TEXT "You are playing on the maze "
#define MAZE_HIGHSCORE_TEXT "The highscore on this maze is "
#define NEW_HIGHSCORE_TEXT "Your score is part of the highscores !\n"
#define ENTER_PSEUDO_TEXT "Enter your pseudo (Max: " STR(MAX_PSEUDO_SIZE) "):\n"
#define ENTER_MAZE_DIFFICULTY_TEXT "Select a difficulty (1: easy 2: hard)\n"
#define PRESS_RETURN_TEXT "Press enter...\n"
#define DEFEAT_TEXT "You've been hurt by a monster !\n"
#endif

#endif
