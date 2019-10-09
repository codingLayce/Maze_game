#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

/* Represents the player type.
 * PLAYER: Control by a real person
 * GHOST: IA that moves around the maze and go through walls
 */
typedef enum {PLAYER, GHOST}Player_type;

/* Represents an entity that can move around the maze. Fields:
 * Current_row: The current row position of the entity
 * Current_col: The current col position of the entity
 * Skin: The representation of the entity
 * Type: The player type
 */
typedef struct {
	int current_row;
	int current_col;
	char skin;
	Player_type type;
} Player;

/* Initializes the player structure with the given values.
 * @param player to initialize
 * @param type of the entity
 * @param row initial row position of the entity
 * @param col initial col position of the entity
 * @param skin the representation of the entity on display
 */
void init_player (Player *player, Player_type type, int row, int col, char skin);

#endif
