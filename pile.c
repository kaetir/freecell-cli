#include "pile.h"


//elements
element* newElement(carte* c){
    element* e = malloc(sizeof(element));
    e->c = c;
    e->next = NULL;
    return e;
}



// pile 
pile* nouvelle_pile(){
    pile* p = malloc(sizeof(pile));
    p->taille = 0;
    p->tete = NULL;
    
    return p;
}



carte* pop(pile* p){
    carte *tmp = (carte* ) p->tete->c;
    carte *toReturn = nouvelle_carte(tmp->c, tmp->valeur);
    element* toDelete = p->tete;
    p->tete = (element*) p->tete->next;
    p->taille--;

    free(toDelete);
    return toReturn;
}


carte* touch(pile* p){
    return p->tete->c;
}


void ajouter_carte(pile* p, carte* c){
    element* tmp = (element*) p->tete;
    p->tete = newElement(c);
    p->tete->next = (struct element*) tmp; // parce que le C 
    p->taille++;

}


void afficher_pile(pile* p){
    element* tmp = p->tete;
    for(size_t i = 0; i < p->taille; i++)
    {
        affiche_carte(tmp->c);
        tmp = (element*) tmp->next;
    }
    
}


void melanger(pile* p){
    pile* p1 = nouvelle_pile();
    pile* p2 = nouvelle_pile();
    pile* p3 = nouvelle_pile();

    size_t tmp = p->taille;
    for(size_t i = 0; i < tmp ; i++)
    {
        size_t r = rand()%3;
        if(r == 0)
            ajouter_carte(p1, pop(p));
        if(r == 1)
            ajouter_carte(p2, pop(p));
        if(r == 2)
            ajouter_carte(p3, pop(p));
    }

    while(p1->taille > 0)
        ajouter_carte(p, pop(p1));

    while(p2->taille > 0)
        ajouter_carte(p, pop(p2));

    while(p3->taille > 0)
        ajouter_carte(p, pop(p3));

}



void deplacer(pile* p1, pile* p2){
    if(p2->tete == NULL && touch(p1)->valeur != 1) return;
    if(p2->tete == NULL && touch(p1)->valeur == 1){
        ajouter_carte(p2, pop(p1));
        return;
    }
        
    if(peuvent_se_suivre(touch(p1), touch(p2)))
        ajouter_carte(p2, pop(p1));
}

void empiler(pile* p1, pile* p2){
    if(p2->tete == NULL && p1->tete->c->valeur != 1) return;
    if(p2->tete == NULL && p1->tete->c->valeur == 1){
        ajouter_carte(p2, pop(p1));
        return;
    }
    
    if(peuvent_sempiler(touch(p2), touch(p1)))
        ajouter_carte(p2, pop(p1));
}

int est_vide(pile* p){
    return p->taille == 0; 
}





