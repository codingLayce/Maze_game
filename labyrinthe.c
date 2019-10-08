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

