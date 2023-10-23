# Projet Logiciel Transversal (PLT)
> Réalisé par Mathieu ROCANCOURT, Margot LALEU et Alexis RONDEAU.


[![Actions Status](https://github.com/cbares/plt/workflows/PLT%20build/badge.svg)](https://github.com/cbares/plt/actions)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

# Monopoly France (Vers. 2008)
## Règles du jeu
Nous allons implémenter un Monopoly sur le modèle du Monopoly France de la version 2008. Les principales modifications par rapport à la règle original sont l'absence d'hypothèque et d'enchère. Les autres modifications apportées sont détaillées dans le fichier suivant: https://github.com/MathieuROCANCOURT/plt/blob/master/rapport/Regles_MonopolyFrance_Adaptees.pdf.

## Ressources
Les ressources visuelles de notre projet sont constituées de logo représentant une gare, une tour symbolisant la carte propriété de service télécoms, une antenne parabolique symbolisant la carte de propriété de service satellite, des dés, un appartement, un hôtel. Nous disposons également de deux planches de 3 pions. 
Ensuite, nous disposons d'une photo du plateau de jeu, une photo du recto des cartes caisse de communauté et chance, des photos de chacun des versos de ces mêmes cartes, des photos de chacune des cartes de propriétés (villes classiques, gares et services).

L'ensemble de ces photos et images se trouvent dans le dossier https://github.com/MathieuROCANCOURT/plt/tree/master/res.

Afin de représenter quelles sont les propriétés possédées par un joueur, nous souhaitons représenter une grille, telle que sur la "ProprietesMonopoly.drawio.png", où chaque case correspond à une des propriétés disponibles dans le jeu. Les 3 premières lignes de case représentent les propriétés classiques. Sur la dernière ligne, les deux cases de gauches représentent les services et les quatre cases de droite représentent les gares.
Cette grille de case sera disponible pour chaque joueur correspondant à ce qu'il possède. Si un des autres joueurs possède une propriété, alors l'intérieur de la case correspondante est grisé. Si le joueur possède une des propriétés classiques, l'intérieur de la case correspondante se colore de la couleur de la case. Si le joueur possède un service ou une gare, la case se rempli avec le logo correspondant présenté ci-dessus.

# Description et conception des états

Un état de notre jeu de Monopoly est constitué de différents éléments pouvant être dans des états différents. Ils sont détaillés ci-dessous en essayant d’être exhaustif.

Un état du jeu est toujours constitué d’un visuel du plateau. Ce visuel ne change jamais.

## State

Il y a un nombre de joueurs compris entre 2 et 6 et ne variant pas au cours d’une même partie.
Chaque joueur possède donc un statut : il a gagné, il a perdu, il est en train de jouer et n’est pas en prison, il est en train de jouer mais est en prison.
À tout moment du jeu correspond le tour d’un des joueurs ou un état d'absence de joueur (avant le démarrage d’une partie) ou de jeu terminé.

Enfin, à chaque tour de chaque joueur est associé une valeur obtenue aux dés valant entre 2 et 12 ainsi qu’un booléen indiquant s’il s’agit d’un double ou non.

L’état du jeu conserve également le nombre de double fait lors d’un tour d’un joueur (le troisième double d’affilé conduit le joueur directement en prison).

## Banque

Une autre entité étant présente à tout moment de la partie est la banque. Cette dernière possède un nombre d'appartements, un nombre d'hôtels et une liste de propriétés. En effet, au début de chaque partie, la banque est en possession de la totalité des propriétés, des 32 appartements et des 12 hôtels, ces valeurs ne peuvent être négatives. A chaque état suivant, la banque possède l’intégralité des propriétés, appartements et hôtels non encore vendu ou retourné à la banque.

## Joueur 

Pour une même partie, un joueur possède un nom fixé ainsi qu’un pion qui lui est associé. Un joueur possède une somme d’argent, qui est de 15 millions au début de chaque partie. Cette somme d’argent peut être positive ou négative. C’est pourquoi le joueur sera également associé à un état : soit quitte (n’ayant pas de dette) si sa somme d’argent possédée est supérieure ou égale à zéro, soit en dette envers la banque, soit en dette envers l’un des autres joueurs (dans ces deux derniers cas, la somme possédée par le joueur est strictement négative).

Chaque joueur possède à tout moment une position correspondant à l’une des cases du plateau (la différence est faite entre une simple visite en prison et être en prison), sauf s’il a perdu.

Ensuite, un joueur à plusieurs possessions: la liste des propriétés qu’il a achetée (et n’a pas échangée), le nombre de cartes “Vous êtes libéré de prison” qu’il possède, valant entre 0 et 2, le nombre total d’appartement qu’il possède, valant entre 0 et 32, et le nombre total d’hôtels qu’il possède valant entre 0 et 12, sur l’ensemble de ses propriétés.

## Propriétés 

Concernant les propriétés citées ci-dessus, on en distingue trois sortes : il y a les propriétés dites “classiques”, il s’agit des villes, il y a les gares et aussi les services.
Tous les types de propriétés possèdent un nom et une valeur d’achat constante en tout temps au cours de la partie et pour toutes les parties, ces caractéristiques ne dépendent donc pas de l’état du jeu.

Les propriétés classiques possèdent d’autres caractéristiques constantes (loyers, couleur d’appartenance) mais aussi des caractéristiques dépendant de l’état du jeu, qui sont le fait de posséder toutes les propriétés de la même couleur que la propriété en question, on a alors un monopole (il s’agit d’un booléen), le nombre d’appartement qui y sont placés (entre 0 et 4) et le nombre d'hôtel (0 ou 1). Cependant si le nombre d’appartement est différent de zéro alors le nombre d'hôtels est forcément à zéro et inversement. Les nombres d’appartements et d'hôtels ne peuvent être non nul que si le booléen, monopole, est à true.

Les propriétés de type gare possèdent aussi des caractéristiques constantes (loyers) ainsi que le nombre de gares possédées par le même joueur (entre 0 et 4).

Les propriétés de type services, possèdent un nombre de services possédés par le même joueur (entre 0 et 2).

## Decks communauté et chance

Enfin, il existe deux decks de 16 cartes chacune : le deck des cartes “caisse de communauté” et le deck des cartes “chance”. À chaque état du jeu correspond donc un ordre des cartes à l’intérieur de ces deux piles. Les cartes “Vous êtes libéré de prison” (une par deck) seront retirées du deck lorsqu’un joueur la tire et tant qu’il la possède.


