#ifndef PARAM_H
#define PARAM_H

#include <stdlib.h>
#include <string.h>
 
typedef struct {
    char tonique[20] ; // La note qui donne donne son nom à la gamme
    char mode; // pour préciser si la gamme est mineure ou majeure
} gamme;

// un getter pour la tonique
char * get_tonique(gamme gam) ;

//un getter pour le mode
char get_mode(gamme gam) ;

// un setter pour la tonique
void set_tonique(gamme gam,char * ton) ;

// un setter pour le mode
void set_mode(gamme gam, char mode) ;

// 


#endif


