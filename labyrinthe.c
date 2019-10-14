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

#include "states/menu.h"
#include "utils/config.h"

int main (int argc, char *argv[]) {
	if (check_for_config_params(argc, argv) == 1) { /* If no arguments the default lang is FRENCH  */
		load_lang_fr();
	}

	menu_logic();

	free_config();

	return 0;
}
