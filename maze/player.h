#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

typedef enum {PLAYER, GHOST}Player_type;

typedef struct {
	int current_row;
	int current_col;
	char skin;
	Player_type type;
} Player;

void init_player (Player *player, Player_type type, int row, int col, char skin);

#endif
