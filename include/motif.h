#ifndef MOTIF_H
#define MOTIF_H

#include <stdio.h>
#include <stdlib.h>

// une enumeration pour savoir si on a affaire a une note ou à un silence
typedef enum {
    NOTE, SILENCE
} Type;


// la structure du noeud d'un motif
typedef struct {
    Type type;
    int hauteur ;
    int duree;
} node_m;

// structure de la liste chainée contenant le motif
typedef struct motif {
    node_m node;
    struct motif * next; 
} motif;

// alloue un maillon, le remplit, retourne le pointeur
node_m * creer_note(int type, int hauteur, int duree);

// construire une liste note par note
void ajouter_fin(motif *tete, node_m note);
void ajouter_debut(motif *tete, node_m note);

// compter les maillons
int longueur(motif *tete);

// parcourt et free chaque maillon , afin d'éviter les fuites memoires
void liberer_motif(motif *tete);

// copie profonde
motif * copier_motif(motif *tete);

// afficher le motif  , imprime chaque note en texte lisible (type, hauteur, duree
void afficher_motif(motif *tete) ;

void transposer(motif *tete, int demi_tons); 
void octave_plus(motif * tete) ;
void octave_moins(motif * tete);
void changer_duree(motif *tete, int num, int denom);
void inverser(motif *tete, int axe);
void retrograder(motif ** tete);



#endif