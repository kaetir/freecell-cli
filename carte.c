#include "carte.h"

#include <stdlib.h>
#include <stdio.h>


carte* nouvelle_carte(couleur c, size_t v){
    if(v < 1 || v > 13 ) return NULL; // un truc valid stp

    carte* car = (carte*) malloc(sizeof(carte));
    car->c = c;
    car->valeur = v;
    return car;
} 


int peuvent_se_suivre(carte* c1, carte* c2){
    // test de consécutivité 
    if (c1->valeur != c2->valeur-1) return false;
    
    // test de couleurs
    if((c1->c == trefle || c1->c == pique) && (c2->c == carreau || c2->c == coeur))
        return true;

    if((c2->c == trefle || c2->c == pique) && (c1->c == carreau || c1->c == coeur))
        return true;

    return false;
}

int peuvent_sempiler(carte* c1, carte* c2){ 
    // test de consécutivité 
    if (c1->valeur != c2->valeur-1) return false;
    
    // test de couleurs
    if(c1->c == c2->c) return true;

    return false;
}


void affiche_carte(carte* c){
    switch (c->c)
    {
        case pique:
            printf("p ");
            break;
    
    
        case trefle:
            printf("t ");
            break;
    
        case coeur:
            printf("co");
            break;
    
        case carreau:
            printf("ca");
            break;

        default:
            printf("oupsi");
            break;
    }
    printf("%2ld\t", c->valeur);
}




