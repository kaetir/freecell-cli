#include <stdio.h>

#include "carte.h"
#include "pile.h"
#include "fonctions.h"
#include <time.h>

#define StackNumber 7 // défini le nombre de colone sur les quels on réparti les cartes

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // initialisation de l'aléatoire

    pile *deck = nouvelle_pile();
    for(size_t j = 0; j < 4; j++)
       for(size_t i = 0; i < 13; i++)
          ajouter_carte(deck,nouvelle_carte(j,i+1 ));
    

    // afficher_pile(deck); // voir le deck
    // melange plusieurs fois parce que plus mieux
    for(size_t i = 0; i < 4; i++)   
        melanger(deck); 



    //distribution
    // les piles p0 ... p6 sont les piles sur les quelles on met les cartes en attendants de les trier
    pile *p[StackNumber];
    for(size_t i = 0; i < StackNumber; i++)
        p[i] = nouvelle_pile();
    
    int i=0;
    while(deck->taille > 0){
        ajouter_carte(p[i], pop(deck));
        i++;
        i = i % StackNumber;
    }



    // les 4 piles ou l'on stock les carte déjà trier
    pile *couleurs[4];
    for(size_t i = 0; i < 4; i++)
        couleurs[i] = nouvelle_pile();

    // les 4 cases libres
    carte* cells[4];
    for(size_t i = 0; i < 4; i++)
        cells[i] = NULL;
     

    // le jeu commence ici 

    while(1){ // boucle infinie du jeu
         
    
    clear();
    // affichage des cases a cartes
    for(size_t i = 0; i < 4; i++)
        if(cells[i] != NULL) 
            affiche_carte(cells[i]); 
        else 
            printf("[ ]\t");
    

    printf(" FREECELL \t");

    //affichage des piles de fin
    for(size_t i = 0; i < 4; i++)
        if(couleurs[i]->tete != NULL) affiche_carte(touch(couleurs[i])); 
        else printf("[ ]\t");
    
    

    //selecteur de cases
    printf("\n a \t b \t c \t d \t         \t e \t f \t g \t h\n\n");


    // selecteur de colones 
    for(size_t i = 0; i < StackNumber; i++)
        printf(" %ld \t", i);
    
    
    printf("\n");
    size_t maxStackSize= 0;
    for(size_t i = 0; i < StackNumber; i++)
        if (maxStackSize > p[i]->taille) {
        }else{
            maxStackSize = p[i]->taille;
        }
        
        
    for(size_t i = 0; i < maxStackSize ; i++)
    {
        for(size_t j = 0; j < StackNumber; j++)
        {
            if(p[j]->taille >= i+1){
                element* tmp = p[j]->tete;
                for(size_t k = 0; k < p[j]->taille-i-1; k++)
                    tmp = (element*) tmp->next;
                affiche_carte(tmp->c);
            }else
                printf("    \t");
            
        }
        printf("\n");
    }

    // interaction joueur
    int depart, arrive;
    printf("\nselectionner départ :\n");
    
    do scanf("%lc", &depart); while ( depart == 10 || depart == 32);
    
    
    printf("\nselectionner arrive :\n");
    do scanf("%lc", &arrive); while ( arrive == 10 || arrive == 32);
    

    if(depart < (48+StackNumber) && depart > 47 )
        depart -= 48 ;
    if (arrive < (48+StackNumber) && arrive > 47) 
        arrive -= 48;
    
    

    // test de déplacement

    // ca arrive meme aux meilleurs
    if (arrive == depart) {
        // rien 
    // cas d'une pile a une autre
    }else if (depart < 97 && arrive < 97) {
        deplacer(p[(int)depart], p[(int)arrive]);

    // on déplace d'une colone a une case de stockage
    }else if(depart < StackNumber && arrive <= 100 && arrive >= 97){
        if(cells[arrive-97] == NULL)
            cells[arrive-97] = pop(p[(int)depart]);

    // ca sert rien de case a case
    }else if (depart >= 97 && depart <= 100 && arrive < 100 && arrive >= 97) {
        // rien 
    // d'une case a une pile finale
    }else if (depart >= 97 && depart <= 100 && arrive >= 100 ) {
        if (peuvent_sempiler(cells[depart-97], touch(couleurs[arrive-101]) )) {
            ajouter_carte(couleurs[arrive-101], cells[depart-97] ) ;
            cells[depart-97] = NULL;
        }
        
    // d'une pile a une pile finale
    }else if (depart < 97  && arrive >= 100 ) {
        empiler(p[(int)depart], couleurs[arrive-101]);
    // cas d'une case vers une pile 
    }else if (depart >= 97 && depart <= 100 && arrive < StackNumber) {
        if(p[(int)arrive]->taille == 0){
            ajouter_carte(p[(int)arrive], cells[depart-97]);
            cells[depart-97] = NULL;
        }else if(peuvent_se_suivre(cells[depart-97], touch(p[(int)arrive]) ) ) {
            ajouter_carte(p[(int)arrive], cells[depart-97]);
            cells[depart-97] = NULL;
        }
    }

    // détection de fin du jeu
    if(couleurs[0]->taille == 13 && couleurs[1]->taille == 13 && couleurs[2]->taille == 13 && couleurs[3]->taille == 13 )
        break;
    
    }

    for(size_t i = 0; i < 4; i++)
        free(couleurs[i]);
    
    free(deck);
    for(size_t i = 0; i < 4; i++)
        free(cells[i]);
    for(size_t i = 0; i < StackNumber; i++)
        free(p[i]);


    clear();
    printf("Felicitation c'est gagne \n");
    return 0;
}






