#include <stdio.h>
#include <stdlib.h>


//Affichage du menu des themes
void afficherThemes() {
    
    int reponseThemes;

    printf("Avec quel thème souhaitez vous jouer ?\n");
    printf("1. Animaux\n");
    printf("2. Fruits\n");
    printf("3. Métiers\n");
    printf("4. Pays\n");
    printf("5. Sports\n");
    printf("6. Sans themes particulier");
    printf("7. Revenir en arriere\n");
    scanf("%d", &reponseThemes);

    switch (reponseThemes)
    {
    /* case 1:
        Pendu_Animaux();
        break;
    case 2:
        Pendu_Fruits();
        break;
    case 3:
        Pendu_Metiers();
        break;
    case 4:
        Pendu_Pays();
        break;
    case 5:
        Pendu_Sports();
        break; 
    case 6:
        Pendu_basique();
        break; */
    case 7:
        afficherMenu();
        break;
   default:
        printf("Cela ne fait pas partir des choix disponible veuillez reessayer");
        afficherThemes();
        break;
    }
}

/*
void Username() {

    char Username;
    char confirmation_Username;

    printf("Veuillez entrer votre nom d'utilisateur");
    scanf("%c", &Username);

    printf("Votre nom d'utilisateur est bien : %c ? Y/N", Username);

    if (confirmation_Username == 'Y') {

    
    } 
    
    else if (confirmation_Username == 'N') {

        Username();

    }   
}
*/
//Affichage du menu principal
void afficherMenu() {

    int reponseMenu;

    printf("-----------------------------------\n");
    printf("           JEU DU PENDU           \n");
    printf("-----------------------------------\n");
    printf("Veuillez choisir ce que vous souhaitez :\n");
    printf("1. Nouvelle Partie\n");
    printf("2. Classement\n");
    printf("3. Quitter\n");

    // Lire la réponse de l'utilisateur
    scanf("%d", &reponseMenu);

    switch (reponseMenu)
    {
    case 1:
        afficherThemes();
        break;
    /* case 2:
        afficherClassement(); 
        break; */
    case 3: 
        exit(1);
    default:
        printf("Cela ne fait pas partie des choix disponibles. Veuillez réessayer.\n");
        afficherMenu();
        break;
    }
}
