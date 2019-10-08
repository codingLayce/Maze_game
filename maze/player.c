#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void init_player (Player *player, Player_type type, int row, int col, char skin) {
	player->current_row = row;
	player->current_col = col;
	player->skin = skin;
	player->type = type;
}
