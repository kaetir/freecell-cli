#ifndef CARTE_H
#define CARTE_H

#include <stdlib.h>

#define true  1
#define false 0

typedef enum _couleur {pique, trefle, carreau, coeur} couleur;


typedef struct _carte
{
    couleur c;     // pique trefle carreau ou coeur
    size_t valeur; //entre 1 et 13    11=J   12=Q    13=K 
}carte;


carte* nouvelle_carte(couleur c, size_t v); // créer une carte

int peuvent_se_suivre(carte* c1, carte* c2); // vrai si les deux cartes peuvent etre empilé (couleur diff et nombre successif)

int peuvent_sempiler(carte* c1, carte* c2); // vrai si deux cartes meme coul et val succesive

void affiche_carte(carte* c); // affiche une carte

#endif //CARTE_H