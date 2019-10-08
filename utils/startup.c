#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "startup.h"
#include "utils.h"

int check_for_display_type (int argc, char *argv[]) {
	if (argc > 1) {
		char cmd[sizeof(argv[1])];
		copy_string(cmd, argv[1], strlen(argv[1]));
		
		if (strcmp(cmd, "-mode") == 0) {
			if (argc > 2) {
				char value[sizeof(argv[2])];
				copy_string(value, argv[2], strlen(argv[2]));

				if (strcmp(cmd, MODE_CONSOLE) == 0) {
					printf("Mode console sélectionné\n");
				} else if (strcmp(cmd, MODE_GRAPHIC) == 0) {
					printf("Mode graphique pas encore pris en charge !\n");
					return 1;
				}
			}
		}
	}

	return 1;
}
