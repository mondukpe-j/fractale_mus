#include "../include/motif.h"


// alloue un maillon, le remplit, retourne le pointeur
node_m * creer_note(int type, int hauteur, int duree){
    node_m * note = malloc(sizeof(node_m));
    if (note == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour la note.\n");
        exit(3);
    }

    note->type = type;
    note->hauteur = hauteur;
    note->duree = duree;
    return note;
}

// ahouter un maillon à la fin de la liste
void ajouter_fin(motif *tete, node_m note){
    motif * nouveau = malloc(sizeof(motif));
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le maillon.\n");
        exit(4);
    }

    nouveau->node = note;
    nouveau->next = NULL;

    if (tete == NULL) {
        tete = nouveau;
    } else {
        motif * courant = tete;
        while (courant->next != NULL) {
            courant = courant->next;
        }
        courant->next = nouveau;
    }
}

// ajouter un maillon au début de la liste
void ajouter_debut(motif *tete, node_m note){
    motif * nouveau = malloc(sizeof(motif));
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le maillon.\n");
        exit(4);
    }

    nouveau->node = note;
    nouveau->next = tete;
    tete = nouveau;
}

//compter les maillons
int longueur(motif *tete){
    int count = 0;
    motif * courant = tete;
    while (courant != NULL) {
        count++;
        courant = courant->next;
    }
    return count;
}

// parcourt et free chaque maillon , afin d'éviter les fuites memoires
void liberer_motif(motif *tete){
    motif * courant = tete;
    while (courant != NULL) {
        motif * temp = courant;
        courant = courant->next;
        free(temp);
    }
}

// copie profonde
motif * copier_motif(motif *tete){
    if (tete == NULL) {
        return NULL;
    }

    motif * nouveau_tete = malloc(sizeof(motif));
    if (nouveau_tete == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le maillon.\n");
        exit(5);
    }

    nouveau_tete->node = tete->node;
    nouveau_tete->next = copier_motif(tete->next);

    return nouveau_tete;
}

// Afficher le motif  , imprime chaque note en texte lisible (type, hauteur, duree)
void afficher_motif(motif *tete) {
    motif * courant = tete;
    while (courant != NULL) {
        printf("Type: %d, Hauteur: %d, Durée: %d\n", courant->node.type, courant->node.hauteur, courant->node.duree);
        courant = courant->next;
    }
}

void transposer(motif *tete, int demi_tons){
    motif * courant = tete;
    while (courant != NULL) {
        courant->node.hauteur += demi_tons ;
        courant = courant->next;
    }
}

void octave_plus(motif * tete){
    transposer(tete , 12) ;
}

void octave_moins(motif * tete){
    transposer(tete , -12) ;
}

void changer_duree(motif *tete, int num, int denom){
    motif * courant = tete;
    while (courant != NULL) {
        courant->node.duree *= num ;
        courant->node.duree /= denom ;
        courant = courant->next;
    }
}

void inverser(motif * tete, int axe) {
    motif * courant = tete;
    int dif;
    while (courant != NULL) {
        dif = courant->node.hauteur - axe ;
        courant->node.hauteur -= (2 * dif);
        courant = courant->next;
    }
}

void retrograder(motif ** tete) {
    //inverser
    motif * courant = *tete;
    if(courant == NULL){
        printf("Chaine de motif vide");
        exit(1);
    }

    motif * prev = NULL; 
    motif * tmp = NULL;

    while(courant != NULL) {
        tmp = courant->next ;
        courant->next = prev;
        prev = courant ;
        courant = tmp ;
    }

    *tete = prev ;
}


