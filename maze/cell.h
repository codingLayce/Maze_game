#ifndef CELL_H_GUARD
#define CELL_H_GUARD

#include "player.h"

typedef enum {EMPTY, WALL, TREASURE, TRAP}cell_type;

typedef struct {
	cell_type type;
	int value;
	Player *player;
} Cell;

void new_cell (Cell *cell, cell_type type, int value);
void display_cell (Cell *cell);
char get_cell_skin (Cell cell);
int get_points(Cell *cell);
void set_player(Cell *cell, Player *player);
void display_player_color(Cell cell);

#endif
