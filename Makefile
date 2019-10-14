FLAGS = -lm -W -Wall -ansi -pedantic

all: maze

maze: labyrinthe.o config.o utils.o cell.o maze.o menu.o creator.o mcreator.o load.o game.o player.o mover.o player_mover.o highscores.o ghost_mover.o
	gcc -o labyrinthe -g .pkg/*.o -lm

config.o: utils/config.c
	gcc -o .pkg/config.o -g -c utils/config.c $(FLAGS)

ghost_mover.o: movements/ghost_mover.c
	gcc -o .pkg/ghost_mover.o -g -c movements/ghost_mover.c $(FLAGS)

highscores.o: maze/highscores.c
	gcc -o .pkg/highscores.o -g -c maze/highscores.c $(FLAGS)

player_mover.o: movements/player_mover.c
	gcc -o .pkg/player_mover.o -g -c movements/player_mover.c $(FLAGS)

mover.o: movements/mover.c
	gcc -o .pkg/mover.o -g -c movements/mover.c $(FLAGS)

player.o: maze/player.c
	gcc -o .pkg/player.o -g -c maze/player.c $(FLAGS)

load.o: states/load.c
	gcc -o .pkg/load.o -g -c states/load.c $(FLAGS)

game.o: states/game.c
	gcc -o .pkg/game.o -g -c states/game.c $(FLAGS)

mcreator.o: maze/creator.c
	gcc -o .pkg/mcreator.o -g -c maze/creator.c $(FLAGS)

creator.o: states/creator.c
	gcc -o .pkg/creator.o -g -c states/creator.c $(FLAGS)

menu.o: states/menu.c
	gcc -o .pkg/menu.o -g -c states/menu.c $(FLAGS)

cell.o: maze/cell.c
	gcc -o .pkg/cell.o -g -c maze/cell.c $(FLAGS)

maze.o: maze/maze.c
	gcc -o .pkg/maze.o -g -c maze/maze.c $(FLAGS)

utils.o: utils/utils.c
	gcc -o .pkg/utils.o -g -c utils/utils.c $(FLAGS)

labyrinthe.o: labyrinthe.c
	gcc -o .pkg/labyrinthe.o -g -c labyrinthe.c $(FLAGS)

clean:
	rm -rf .pkg/*.o
