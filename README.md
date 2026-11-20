# fractale_mus — Fractales et musique en C

Projet personnel (depuis août 2026) : générer de la musique à partir de structures fractales, en C, en gardant en tête la performance et la parallélisation du calcul.

> **État : en cours de développement.** Ce dépôt contient pour l'instant la première brique (les paramètres musicaux). Les autres modules arrivent au fil de l'avancement, voir la feuille de route ci-dessous.

## Idée

Une fractale se construit en appliquant de façon répétée les mêmes transformations à un motif de départ. En musique, on peut faire la même chose : partir d'un court motif mélodique, lui appliquer des transformations classiques (transposition, inversion, rétrogradation, changement de durée), puis réinjecter le résultat dans le processus, niveau après niveau. On obtient une pièce dont la structure se répète à plusieurs échelles.

## Choix de conception

- **Approche déterministe** (« canon fractal ») plutôt qu'un moteur aléatoire de type jeu du chaos : chaque niveau de la fractale se calcule indépendamment des autres, ce qui le rend parallélisable.
- **Sortie en fichier MIDI complet**, généré d'abord puis écouté, plutôt qu'une génération en temps réel.
- **Durées en ticks entiers**, avec une unité divisible par 2 et par 3 pour gérer les triolets dès le départ.
- **Hauteurs en demi-tons relatifs à la tonique** de la gamme choisie.
- **Transformations prévues** pour la première version :
  - transposition (et octaviation, comme transposition de ±12 demi-tons) ;
  - inversion mélodique autour de la tonique ;
  - contraction / dilatation temporelle, paramétrée par une fraction d'entiers pour garder des durées exactes ;
  - rétrogradation (lecture du motif à l'envers).

## Structure du dépôt

```
.
├── include/
│   ├── param.h            # Paramètres musicaux : gamme (tonique, mode)
│   └── generateur_ifs.h   # Générateur fractal (en préparation)
└── src/
    ├── param.c
    └── generateur_ifs.c
```

## Feuille de route

- [x] Paramètres musicaux : structure `gamme` (tonique, mode) et contrôle de validité de la tonique
- [ ] Notes et motifs (note, silence, durée) et leurs opérations de base
- [ ] Transformations musicales listées ci-dessus
- [ ] Générateur fractal (itération des transformations sur plusieurs niveaux)
- [ ] Export MIDI
- [ ] Mesure des performances, puis parallélisation de la génération
- [ ] Gestion des bornes (tessiture) et quantification sur la gamme

## Compilation

Le projet n'a pas encore d'exécutable : un `Makefile` et un `main` seront ajoutés avec le générateur. Il est écrit en C standard et se compile avec `gcc` sous Linux.

## Auteur

Jean-Marie Assogba — élève ingénieur à l'ENSIIE, filière Calcul Intensif et Données Massives.
