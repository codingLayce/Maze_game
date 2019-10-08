all: maze

maze: labyrinthe.o utils.o cell.o maze.o startup.o menu.o creator.o mcreator.o load.o game.o player.o mover.o player_mover.o highscores.o ghost_mover.o
	gcc -o labyrinthe -g .pkg/*.o

ghost_mover.o: movements/ghost_mover.c
	gcc -o .pkg/ghost_mover.o -g -c movements/ghost_mover.c -W -Wall -ansi -pedantic

highscores.o: maze/highscores.c
	gcc -o .pkg/highscores.o -g -c maze/highscores.c -W -Wall -ansi -pedantic

player_mover.o: movements/player_mover.c
	gcc -o .pkg/player_mover.o -g -c movements/player_mover.c -W -Wall -ansi -pedantic

mover.o: movements/mover.c
	gcc -o .pkg/mover.o -g -c movements/mover.c -W -Wall -ansi -pedantic

player.o: maze/player.c
	gcc -o .pkg/player.o -g -c maze/player.c -W -Wall -ansi -pedantic

load.o: states/load.c
	gcc -o .pkg/load.o -g -c states/load.c -W -Wall -ansi -pedantic

game.o: states/game.c
	gcc -o .pkg/game.o -g -c states/game.c -W -Wall -ansi -pedantic

mcreator.o: maze/creator.c
	gcc -o .pkg/mcreator.o -g -c maze/creator.c -W -Wall -ansi -pedantic

creator.o: states/creator.c
	gcc -o .pkg/creator.o -g -c states/creator.c -W -Wall -ansi -pedantic

menu.o: states/menu.c
	gcc -o .pkg/menu.o -g -c states/menu.c -W -Wall -ansi -pedantic

startup.o: utils/startup.c
	gcc -o .pkg/startup.o -g -c utils/startup.c -W -Wall -ansi -pedantic

cell.o: maze/cell.c
	gcc -o .pkg/cell.o -g -c maze/cell.c -W -Wall -ansi -pedantic

maze.o: maze/maze.c
	gcc -o .pkg/maze.o -g -c maze/maze.c -W -Wall -ansi -pedantic

utils.o: utils/utils.c
	gcc -o .pkg/utils.o -g -c utils/utils.c -W -Wall -ansi -pedantic

labyrinthe.o: labyrinthe.c
	gcc -o .pkg/labyrinthe.o -g -c labyrinthe.c -W -Wall -ansi -pedantic

clean:
	rm -rf .pkg/*.o
