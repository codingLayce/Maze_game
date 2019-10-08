#ifndef STARTUP_H_GUARD
#define STARTUP_H_GUARD

#define MODE_CONSOLE "console"
#define MODE_GRAPHIC "graph"

/* Function that check if the argument "-mode" has been passed on startup.
 * The argument "-mode" can be of two values:
 * "console" the game will be display on the console,
 * "graph" the game will be display on a graphic window (not yet implemented).
 * Return 1 for "console" and 2 for "graph" (by default it returns 1).
 */
int check_for_display_type (int argc, char *argv[]);

#endif
