INCLUDES=-Iincludes/
FLAGS = $(INCLUDES) -lm -W -Wall -ansi -pedantic
BIN=bin/
BINO=$(BIN).objects/

all: maze

maze: labyrinthe.o config.o utils.o cell.o maze.o menu.o creator.o mcreator.o load.o game.o player.o mover.o player_mover.o highscores.o ghost_mover.o spider_mover.o
	gcc $(INCLUDES) -o $(BIN)labyrinthe -g $(BINO)*.o -lm

config.o: src/utils/config.c
	gcc -o $(BINO)config.o -g -c src/utils/config.c $(FLAGS)

ghost_mover.o: src/movements/ghost_mover.c
	gcc -o $(BINO)ghost_mover.o -g -c src/movements/ghost_mover.c $(FLAGS)

spider_mover.o: src/movements/spider_mover.c
	gcc -o $(BINO)spider_mover.o -g -c src/movements/spider_mover.c $(FLAGS)

highscores.o: src/maze/highscores.c
	gcc -o $(BINO)highscores.o -g -c src/maze/highscores.c $(FLAGS)

player_mover.o: src/movements/player_mover.c
	gcc -o $(BINO)player_mover.o -g -c src/movements/player_mover.c $(FLAGS)

mover.o: src/movements/mover.c
	gcc -o $(BINO)mover.o -g -c src/movements/mover.c $(FLAGS)

player.o: src/maze/player.c
	gcc -o $(BINO)player.o -g -c src/maze/player.c $(FLAGS)

load.o: src/states/load.c
	gcc -o $(BINO)load.o -g -c src/states/load.c $(FLAGS)

game.o: src/states/game.c
	gcc -o $(BINO)game.o -g -c src/states/game.c $(FLAGS)

mcreator.o: src/maze/creator.c
	gcc -o $(BINO)mcreator.o -g -c src/maze/creator.c $(FLAGS)

creator.o: src/states/creator.c
	gcc -o $(BINO)creator.o -g -c src/states/creator.c $(FLAGS)

menu.o: src/states/menu.c
	gcc -o $(BINO)menu.o -g -c src/states/menu.c $(FLAGS)

cell.o: src/maze/cell.c
	gcc -o $(BINO)cell.o -g -c src/maze/cell.c $(FLAGS)

maze.o: src/maze/maze.c
	gcc -o $(BINO)maze.o -g -c src/maze/maze.c $(FLAGS)

utils.o: src/utils/utils.c
	gcc -o $(BINO)utils.o -g -c src/utils/utils.c $(FLAGS)

labyrinthe.o: src/labyrinthe.c
	gcc -o $(BINO)labyrinthe.o -g -c src/labyrinthe.c $(FLAGS)

clean:
	rm -rf $(BINO)*.o
