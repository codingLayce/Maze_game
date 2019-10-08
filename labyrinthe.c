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

#include "utils/startup.h"
#include "states/menu.h"

int main (int argc, char *argv[]) {
	int display_type = check_for_display_type(argc, argv);
	if (display_type == 1) {
		menu_logic();
	}

	return 0;
}
