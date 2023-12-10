#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/menu.h"
#include "include/words.h"

void afficherMotCache(const char* motSecret, const char* lettresTrouvees);
void afficherPendu(int essaisRestants);

int main(void) {
    const char* theme = afficherMenu();
    const char* motSecret = random_word(theme);

    char lettresTrouvees[50];
    memset(lettresTrouvees, '_', strlen(motSecret));
    lettresTrouvees[strlen(motSecret)] = '\0';

    int essaisRestants = 6;
    while (essaisRestants > 0) {
        afficherPendu(6 - essaisRestants);

        afficherMotCache(motSecret, lettresTrouvees);

        printf("Saisissez une lettre : ");
        char choix;
        scanf(" %c", &choix);

        // Si lettre dans mot secret
        int lettreTrouvee = 0;
        for (int i = 0; i < strlen(motSecret); i++) {
            if (motSecret[i] == tolower(choix)) {
                lettresTrouvees[i] = tolower(choix);
                lettreTrouvee = 1;
            }
        }

        // Si victoire
        if (strcmp(motSecret, lettresTrouvees) == 0) {
            printf("Bravo, vous avez devine le mot : %s\n", motSecret);
            break;
        } else if (!lettreTrouvee) {
            printf("Incorrect !\n");
            essaisRestants--;

            // SI DEFAITE
            if (essaisRestants == 0) {
                afficherPendu(6 - essaisRestants); 
                printf("Dommage, vous avez epuise tous vos essais. Le mot etait : %s\n", motSecret);
                break;
            }
        }
    }

    return 0;
}

void afficherMotCache(const char* motSecret, const char* lettresTrouvees) {
    for (int i = 0; i < strlen(motSecret); i++) {
        if (lettresTrouvees[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", lettresTrouvees[i]);
        }
    }
    printf("\n");
}

void afficherPendu(int essaisRestants) {
    // Tableau représentant les différentes étapes du pendu
    const char* pendu[] = {
        " ------\n |    |\n      |\n      |\n      |\n      |\n",
        " ------\n |    |\n O    |\n      |\n      |\n      |\n",
        " ------\n |    |\n O    |\n |    |\n      |\n      |\n",
        " ------\n |    |\n O    |\n/|    |\n      |\n      |\n",
        " ------\n |    |\n O    |\n/|\\   |\n      |\n      |\n",
        " ------\n |    |\n O    |\n/|\\   |\n/     |\n      |\n",
        " ------\n |    |\n O    |\n/|\\   |\n/ \\   |\n      |\n"
    };

    printf("%s", pendu[essaisRestants]);
}
