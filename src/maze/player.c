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
#include "player.h"

void init_player (Player *player, Player_type type, int row, int col, char skin) {
	player->current_row = row;
	player->current_col = col;
	player->skin = skin;
	player->type = type;
	player->start_row = row;
	player->start_col = col;
}
