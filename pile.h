#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include "carte.h"

// un élément est un élement dans la pile 
// il contient un pointeur vers l'élement suivant si il y en a un
typedef struct _element
{
    carte* c;
    struct element *next;
}element;

element* newElement(carte* c); // crée un élément a partir d'une carte


typedef struct _pile
{
    size_t taille;   // le nombre de cartes dans la pile
    element *tete; // élément sur le dessus de la pile. on ne peux pas taper en dessous 
}pile;


pile* nouvelle_pile();

carte* pop(pile* p); // retourne l'élement sur le dessus d'une pile et le supprime. 

carte* touch(pile* p); // retourne l'élement sur le dessus d'une pile. 

void ajouter_carte(pile* p, carte* c); // ajoute une carte a une pile

void afficher_pile(pile* p); // affiche le contenu d'une pile 
//(fonction qui traite la pile comme une file pour éviter les access mémoire redondans)

void melanger(pile* p); // c'est le bazzard par ici ! 

void deplacer(pile* p1, pile* p2); // bouge l'élément du dessus d'une pile p1 source p2 destination

void empiler(pile* p1, pile* p2); // bouge l'élément du dessus d'une pile p1 source p2 destination

int est_vide(pile* p); // dit si une pile est vide 




#endif //PILE_H