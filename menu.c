#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/menu.h"
#include "include/words.h"

const char* afficherMenu() {
    printf("Bienvenue dans le jeu du Pendu !\n");
    printf("Choisissez le mode de difficulte :\n");
    printf("1. Facile\n");
    printf("2. Difficile\n");
    
    int choixDifficulte;
    scanf("%d", &choixDifficulte);
    
    printf("Choisissez un theme :\n");
    printf("1. Animaux\n");
    printf("2. Fruits\n");
    printf("3. Pays\n");
    printf("4. Metiers\n");
    printf("5. Sports\n");
    printf("6. Couleurs\n");

    int choixTheme;
    scanf("%d", &choixTheme);

    const char* theme;
    switch (choixTheme) {
        case 1:
            theme = "animaux";
            break;
        case 2:
            theme = "fruits";
            break;
        case 3:
            theme = "pays";
            break;
        case 4:
            theme = "métiers";
            break;
        case 5:
            theme = "sports";
            break;
        case 6:
            theme = "couleurs";
            break;

        default:
            fprintf(stderr, "Theme non valide. Choisissez un thème existant.\n");
            exit(EXIT_FAILURE);
    }

    return theme;
}

int choisirTheme() {
    // Affiche le menu et récupère le choix du thème
    printf("Choisissez un theme :\n");
    printf("1. Animaux\n");
    printf("2. Fruits\n");
    printf("3. Pays\n");
    printf("4. Metiers\n");
    printf("5. Sports\n");
    printf("6. Couleurs\n");

    int choixTheme;
    scanf("%d", &choixTheme);

    return choixTheme;
}

int choisirNiveau() {
    int choixNiveau;
    printf("Choisissez un niveau :\n");
    printf("1. Niveau Facile\n");
    printf("2. Niveau Intermédiaire\n");
    printf("3. Niveau Difficile\n");
    scanf("%d", &choixNiveau);
    return choixNiveau;
}
