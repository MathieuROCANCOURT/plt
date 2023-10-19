# Projet Logiciel Transversal (PLT)
> Réalisé par Mathieu ROCANCOURT, Margot LALEU et Alexis RONDEAU.


[![Actions Status](https://github.com/cbares/plt/workflows/PLT%20build/badge.svg)](https://github.com/cbares/plt/actions)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

# Monopoly France (Vers. 2008)
## Règles du jeu
Nous allons implémenter un Monopoly sur le modèle du Monopoly France de la version 2008. Les principales modifications par rapport à la règle original sont l'absence d'hypothèque et d'enchère. Les autres modifications apportés sont détaillés dans le fichier suivant: https://github.com/MathieuROCANCOURT/plt/blob/master/rapport/Regles_MonopolyFrance_Adaptees.pdf.

## Ressources

Les ressources visuelles de notre projet sont constitués de logo représentant une gare, une tour symbolisant la carte propriété de service télécoms, une antenne parabolique symbolisant la carte de propriété de service satellite, des dés, un appartement, un hôtel. Nous disposons également de deux planches de 3 pions. 
Ensuite, nous disposons d'une photo du plateau de jeu, une photo du recto des cartes caisse de communauté et chance, des photos de chacun des versos de ces mêmes cartes, des photos de chacune des cartes de propriétés (villes classiques, gares et services).

L'ensemble de ces photos et images se trouvent dans le dossier https://github.com/MathieuROCANCOURT/plt/tree/master/res.

Afin de représenter quelles sont les propriétés possédées par un joueur, nous souhaitons représenter une grille, telle que sur la "ProprietesMonopoly.drawio.ong", où chaque case correspond à une des propriétés disponibles dans le jeu. Les 3 premières lignes de case représentent les propriétés classiques. Sur la dernière ligne, les deux cases de gauches représentent les services et les quatre cases de droite représentent les gares.
Cette grille de case sera disponible pour chaque joueur correspondant à ce qu'il possède. Si un des autres joueurs possède une propriété, alors l'intérieur de la case coorespondante est grisée. Si le joueur possède une des propriétés classiques, l'intérieur de la case correspondante se colore de la couleur de la case. Si le joueur possède un service ou une gare, la case se rempli avec le logo correspondant présenté ci-dessus.

# Description et conception des états

