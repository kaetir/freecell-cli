
#ifndef FONCTIONS_H 
#define FONCTIONS_H

#include <stdlib.h>

#ifdef __linux__

void clear(){
    system("clear");
    printf("\n");
}

#elif __WIN32

void clear(){
    system("cls");
    printf("\n");
}


#endif




#endif //FONCTIONS_H