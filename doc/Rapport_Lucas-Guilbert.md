# Rapport projet labyrinthe en C

Le projet consiste à réaliser un programme permettant de créer des labyrinthes parfaits, les
 sauvegarder, les charger et jouer dessus.
 
Plusieurs grandes étapes étaient obligatoires durant la réalisation:

1) Création d'un labyrinthe parfait de taille fixe;
2) Ajout d'un menu permettant de créer, charger, jouer sur un labyrinthe et de quitter; 
3) Ajout de bonus et malus sur les labyrinthes avec un système de scoring et de meilleurs scores;
4) Ajout d'un mode "difficile" ajoutant plus de chemins dans un labyrinthe et des monstres
 rendant la progression plus difficile.

Le projet présenté à été réalisé en monome en C.

Les outils utilisés pour le développement ont été:
- make
- git (un peu tardivement) [repository](https://github.com/codingLayce/Maze_game)
- vim
- intellij (pour quelques refactoring et l'écriture du rapport en markdown)
- valgrind (pour les fuites mémoire uniquement)

## Ce que fait le programme
Actuellement le programme remplit toutes les exigences pour valider l'étape n°4.

- Un menu permettant de créer, charger, jouer ou quitter est affiché au démarrage.
- Lors de la création, l'utilisateur est invité à rentrer la taille, le nom et la difficulté du
 labyrinthe, il est ensuite sauvegardé et chargé.
- Lors du chargement, l'utilisateur est invité à choisir parmi la liste des labyrinthes lequel
 charger.
- Lors du jeu, l'utilisateur peut se déplacer, son score est mit à jour à chaque tour en fonction
 de la case sur laquelle il se trouve. Si son score fait parti des 10 meilleurs en fin de jeu, il
  est invité à entrer son pseudo, son score sera ainsi sauvegardé.
- En mode difficile, plusieurs murs sont cassés en plus afin de créer plusieurs chemins et des
 monstres jonchent le labyrinthe.

# Manuel utilisateur

## Lancement
Afin de lancer le programme, l'utilisateur doit se placer dans le répertoire "bin" et exécuter le
 binaire "labyrinthe".

Le programme possède une configuration permettant de le lancer en français ou en anglais (par
 défaut il se lance en français). Il suffit d'ajouter en option de lancement "-lang en" ou
  "-lang fr" afin de modifier la langue du programme.

## Menu
Une fois le programme lancé, l'utilisateur arrive sur le menu du jeu:

![](img/menu.png)

Il peut donc choisir parmi les différentes options en renseignant le numéro indiqué.

## Créer un labyrinthe
Lors de la création d'un labyrinthe, l'utilisateur est invité à renseigner la taille du
 labyrinthe, la difficulté ainsi que le nom de celui-ci.
 
![](img/creation.png)

## Charger un labyrinthe
Lors du chargement d'un labyrinthe, l'utilisateur est amené à renseigner le numéro correspondant
 au labyrinthe sur lequel il souhaite jouer parmi la liste de ceux sauvegardés.
 
![](img/chargement.png)

## Jouer
Afin de pouvoir jouer, l'utilisateur doit avoir chargé un labyrinthe (ou créé un) auparavant.

![](img/jeu.png)

Les 10 meilleurs highscore sont affichés au dessus du labyrinthe. Le score est affiché en
 permanence.
 
Le joueur doit se déplacer via les commandes Z Q S D (Z: Monter Q: Gauche S: Descendre D: Droite).
 
- Les blocs violets représentent les murs,
- Le 'o' bleu représente le joueur,
- Les '$' verts représentent les trésors,
- Les '^' rouges représentent les pièges.

En mode difficile:

![](img/jeu_difficile.png)

- Le 'S' bleu représente une araignée, elle se déplace de façon aléatoire sur le labyrinthe en
 fonction d'un paramètre de mobilité, c'est-à-dire qu'elle ne peut aller plus loin que 5 cases
  autour de la case où elle commence.
- Le 'G' bleu représente un fantôme, il se déplace de façon aléatoire sur tout le labyrinthe, il
 peut traverser les murs.

Quand le joueur rencontre un monstre, 1000 points sont ajoutés au score (il faut en avoir le
 moins possible).

# Manuel programmeur
Le programme est séparé en 3 grandes parties:

- Maze: modèle,
- Movements: logique de movements des différentes entités,
- States: vue assemblant le modèle et les mouvements.
- (Utils: quelques fonctions utilitaires).

## Modèle
J'ai décidé de représenter mon labyrinthe par une matrice de Cell car cela me permet de définir
 le type de chaque cellule ainsi que la valeur de la cellule pour l'algorithme de génération.

Dans le modèle se trouve aussi les fonctions de création du labyrinthe, le système de highscore
 (par des listes chaînées) ainsi que le joueur.
 
Pour le joueur, j'ai décidé de ne faire qu'une structure représentant un joueur humain mais aussi
 un joueur monstre. Cela me permet de faire des fonctions plus génériques mais rend certaines tâches
 plus compliquées (voir améliorations possibles).

Pour la création de mon labyrinthe en mode difficile, il faut casser des murs en plus une fois le
 labyrinthe parfait trouvé. Pour choisir le nombre de murs à casser, j'utilise une formule:
- **10% de la largeur + la hauteur du labyrinthe**

Ex: 10+5 = 15 * 0.1 = 1.5 -> 1 mur.
Ex: 33+13 = 46 * 0.1 = 4.6 -> 4 murs.

De même que pour les murs en mode difficile, il faut choisir un nombre de piège et de trésors à générer 
sur le labyrinthe :
- **Le nombre de cellules vides x un ratio (0.05 par défaut) arrondi à l'entier inférieur**

Ex: 25 x 0.05 = 1.25 -> 1 piège et 1 trésor.
Ex: 150 x 0.05 = 7.5 -> 7 pièges et 7 trésors.

Le système est le même pour les monstres mais avec un ratio différent (0.001 par défaut).

## Mouvements
Pour les mouvements il était demandé dans le sujet d'utiliser des pointeurs de fonction, hors mon architecture ne me permettait pas d'en utiliser à cause d'inclusions cycliques. J'ai donc décidé de créer un module dédié aux mouvements et la bonne fonction de mouvement sera appelée en fonction du type de joueur.

Le module se découpe donc en 4 parties (une partie générale et une pour chaque type de joueur "PLAYER", "GHOST", "SPIDER").

La partie générale se contente de déplacer l'entitée vers la direction souhaitée, elle ne fait aucune vérification.

Comme pour chaque type de joueur la logique est differente, les fonctions sont donc differentes et ne vérifient pas les mêmes paramètres. En effet le fantôme peut traverser les mûrs alors que les autres joueurs non, l'araîgnéee ne peut pas se déplacer à plus de 5 cases (par défaut) de son point d'apparition.

## Etats
Afin de matérialiser les enchaînements entre les différentes parties du programme, j'ai utilisé une sorte de "machine d'état".
Ce n'est pas à proprement parlé une machine d'état mais chaque état représente une grande partie du programme. Voici les états:
- Menu (boucle principale + choix de création, chargement et jeu),
- Creator (état représentant la création d'un labyrinthe),
- Load (état représentant le chargement d'un labyrinthe),
- Game (état représentant le jeu).

Ce n'est pas à proprement parlé une "machine d'état" car les fonctions représentant un état ne retourne pas l'état suivant, mais l'appelle directement.

La boucle principale du programme se trouve donc dans l'état Menu, le programme tourne tant que l'utilisateur n'a pas choisi l'option "Quitter".

Dans la mesure du possible mes états ne font que l'intermédiaire entre l'utilisateur et le modèle, c'est-à-dire qu'ils affichent les informations et récupèrent les entrées de l'utilisateur. J'ai essayé le plus possible de considérer mes étas comme des controlleurs.

## Configuration
Afin de rendre modulaire mon programme j'ai mis en place un système de configuration. Le `.h` est dans les includes et le `.c` dans `utils/config.c`.

Le `.h` va contenir toutes les constantes du programme, notamment le score que donne chacune des entités, la taille maximale des entrées mais il définit aussi la fonction système à appeler pour "clear" l'écran en fonction du système d'exploitation.

On peut voir en fin de ce fichier un certain nombre de pointeur de char, se sont les constantes de texte utilisées dans le programme. Elles sont définies dynamiquement dans le `.c`.

Libre à vous de modifier certaines des constantes afin de voir le comportement du programme notamment en modifiant le ratio d'apparition des monstres ou en ajoutant une nouvelle langue comme l'espagnol ?

De plus la configuration permet de palier à un problème lié au dossier de sauvegarde. En effet imaginons que mes sauvegardes se trouvent dans le dossier `bin/saves/` et que mon exécutation est lui aussi dans le `bin/`. Si je navigue jusque dans le `bin/` et lance le programme, celui-ci pourra accéder au dossier `saves/` afin de récupérer les sauvegardes. Mais si je lance le programme depuis la racine de mon projet en faisant comme suis: `./bin/labyrinthe` il essaiera d'accéder aux sauvegardes `saves/` mais ne trouvera rien.

Afin de régler ce problème je me base sur la valeur de argv[0] que tout programme possède. Dans le premier cas énoncé précédement, `argv[0] = "labyrinthe"` je peux donc en déduire que le dossier de sauvegardes a pour chemin (par rapport au pwd du shell parent) `./saves/`. Pour le deuxième cas énoncé `argv[0] = "bin/labyrinthe` il me suffit d'isoler le nom de l'exécutable `bin/` et d'y ajouter le dossier de sauvegardes `bin/saves/`. Grâce à ça il est possible d'accéder aux sauvegardes peut importe d'où est lancé le programme.

## Tests
J'ai effectué très peu de tests (pas une bonne pratique je reconnais) mais ils m'ont permis de régler un problème avec les highscores.

Les tests se trouvent sous `src/tests/` et possèdent un Makefile qui leur est propre.

## Bugs
Actuellement aucun bug n'est connu.

Toutes les entrées de l'utilisateur sont protégées:
- Vérification des bornes quand on demande la taille du labyrinthe,
- Impossible de rentrer le chemin vers un dossier quand on demande le nom du labyrinthe,
- Pour le déplacement le premier caractère est celui qui indique la direction ("qqqq" déplacera
 une fois vers la gauche; "aqqq" ne déplacera pas le joueur).

## Améliorations possibles
De mon point de vue, la partie à revoir dans mon code est la partie "Player" et la logique dans
 mon état "game".
 
En effet, comme expliqué plus haut, j'ai voulu faire qu'une seule structure pouvant regrouper toutes les entités (Player) afin de créer des fonctions plus génériques. Mais au moment d'ajouter les araîgnées je me suis rendu compte que j'avais besoin d'autres attributs dans la structure et donc de modifier le comportement du joueur et du fantôme. Cela m'a rendu la tâche pénible et la logique de scoring du fantôme et de l'araîgnée étant la même, il y a pas mal de duplication de code dans le fichier `game.c` (fonctions: `update_ghosts`, `update_spiders`, `init_ghosts`, `init_spiders`).
