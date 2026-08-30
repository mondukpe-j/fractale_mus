#include "../include/param.h"


char * get_tonique(gamme gam) {
    return gam.tonique ;
}

char get_mode(gamme gam) {
    return gam.mode ;
}

void * set_tonique(gamme gam, char * ton) {
    // Une vérification rapide par parrort à la longueyr
    if(strlen(ton) < 2 ||  strlen(ton) > 3) {
        printf("La tonique entrée est incorrecte .\n") ;
        exit(1);
    }
    
    // Vérification de lla validité du contenu de la variable 'ton'
    if(strcmp(ton, "Do") != 0 &&
        strcmp(ton, "Re") != 0 &&
        strcmp(ton, "Mi") != 0 &&
        strcmp(ton, "Fa") != 0 &&
        strcmp(ton, "Sol") != 0 &&
        strcmp(ton, "La") != 0 &&
        strcmp(ton, "Si") != 0 ) {
        printf("La tonique entrée est incorrecte .\n") ;
        exit(2);
    }

    // Copie dans la structure du contenu de 'ton'
    strcpy(gam.tonique , ton) ;
}


void * set_mode(gamme gam, char mode) {
    
    // Vérification de lla validité du contenu de la variable 'mode'
    if(mode != 'M' && mode != 'm') {
        printf("Le mode entrée est incorrect .\n") ;
        exit(2);
    }

    // Affectation dans la structure du mode
    gam.mode = mode;
}

