# Maze_game

Student project at ENSICAEN. Make a console maze game in C.

## First state

Create a maze generator of size 9x23 where a player can move and reach the end.

## Second state:

Show a menu on startup like below: 
- Create a maze; 
- Load a maze; 
- Play; 
- Quit.

### Create a maze

The player can choose the maze size (odd width and height) and a name. After being generated, the maze is 
saved in a file with the extension .cfg, and loaded. The player is redirected to menu.

### Load a maze

The player is invited to select a saved maze. The maze is load and the player is redirected to the menu.

### Play

A game is started with the loaded maze. The player can move in the maze with the keys Z, Q, S, D followed by 
the RETURN key. When the player reach the end he is redirected to menu.

## Third state

2 kings of objects appear randomly in the maze: 
- Treasures, gives a score bonus; 
- Traps, gives a score malus. 
Those objects are added to maze when created a new one. A score will be given to the player base on 
the number of step he made to reach the end. If his score is part of the 10 best one, the game ask him to 
enter a pseudo and save the highscores in a file with the extension .score.

## Fourth state
There is now 2 difficulties: 
- Easy, same as the third state. 
- Hard, the maze has now multiples paths to reach the end. 
In hard mode there is now some monsters that are moving in the maze. There "IA" will be 
working on 2 parameters: 
- Mobility, define by rules (for example ghost can go through walls, and gobelins 
stay near to treasures); 
- Range of mobility: The range of mobility is based on the malus the monster gives 
to the player (the bigger is the malus, the bigger is the range mobility).
