#include <stdio.h>
#include "include/raylib.h"
#include "include/main.h"
#include "words.c"
#include "menu.c"


int main(void) {

    // Initialisation de la fenêtre
    // const int screenWidth = 800;
    // const int screenHeight = 450;
    // InitWindow(screenWidth, screenHeight, "Ma fenêtre Raylib");
    // SetTargetFPS(60);  // Définit le nombre d'images par seconde cible


    printf(">>> JEU DU PENDU <<<\n");
    char* motChoisi = random_word();
    secret_word(motChoisi);    

    //TODO (NOMBRE_ESSAI < 6)
    while (1){
        user_choice(motChoisi);
    }
    return 0;
}       

