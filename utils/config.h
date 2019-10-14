#ifndef CONFIG_H_GUARD
#define CONFIG_H_GUARD

#define MAZE_MAX_ROWS 101
#define MAZE_MAX_COLS 201

#define MAX_NAME_SIZE 30
#define MAX_PSEUDO_SIZE 20

/* The command to clear the console isn't the same on Unix system and Windows system */
#if defined(_WIN32)
#define CLEAR_COMMAND "cls"

#else
#define CLEAR_COMMAND "clear"
#endif

static const int STEP_SCORE = 10;
static const int TREASURE_SCORE = -50;
static const int TRAP_SCORE = 50;
static const double TRAPS_RATIO = 0.05;
static const double TREASURE_RATIO = 0.05;
static const double GHOST_RATIO = 0.002;

static const char PATH_TO_SAVES[8] = "./saves/";

/* Console colors constants */
static const char WALL_COLOR[11] = "\033[35;45m";
static const char EMPTY_COLOR[11] = "\033[107m";
static const char PLAYER_COLOR[11] = "\033[34;44m";
static const char GHOST_COLOR[11] = "\033[36;46m";
static const char TREASURE_COLOR[11] = "\033[32;42m";
static const char TRAP_COLOR[11] = "\033[31;41m";
static const char DEFAULT_COLOR[11] = "\033[39;49m";

/* All texts displayed on the console (will be initialized in the load_lang_<lang> function */
char *CREATE_MAZE_TEXT;
char *LOAD_MAZE_TEXT;
char *PLAY_TEXT;
char *QUIT_TEXT;
char *LOADED_MAZE_TEXT;
char *ERROR_NO_MAZE_LOADED;
char *ENTER_MAZE_NAME_TEXT;
char *ENTER_MAZE_WIDTH_TEXT;
char *ENTER_MAZE_HEIGHT_TEXT;
char *GAME_SCORE_TEXT;
char *TOP_OF_GAME_TEXT;
char *MAZE_NAME_TEXT;
char *MAZE_HIGHSCORE_TEXT;
char *NEW_HIGHSCORE_TEXT;
char *ENTER_PSEUDO_TEXT;
char *ENTER_MAZE_DIFFICULTY_TEXT;
char *PRESS_RETURN_TEXT;
char *DEFEAT_TEXT;
char *ERROR_NULL_LIST;
char *ERROR_OPENING_FILE;
char *ERROR_NO_HIGHSCORE;
char *MAZE_GENERATED_TEXT;
char *SAVING_MAZE_TEXT;
char *ERROR_WRITING_FILE;
char *SELECT_MAZE_TEXT;
char *ERROR_READING_FILE;

/* Checks if there is a "-lang" arguments, if so call the loading function corresponding to the lang or return.
 * @param argc number of arguments passed on startup
 * @param argv list of arguments passed on startup
 * @return 0 is a lang has been loaded, 1 otherwise
 */
int check_for_config_params(int argc, char **argv);

/* Loads the french texts.
 */
void load_lang_fr();

/* Loads the english texts.
 */
void load_lang_en();

/* Free the memory for the texts.
 */
void free_config();

#endif
