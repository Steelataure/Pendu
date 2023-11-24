#include <stdio.h>
#include <stdlib.h>

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
        printf("C'est pas dans la range enculé");
        afficherMenu();
        break;
    }
}

//Affichage du menu des themes
void afficherThemes() {

    int reponseThemes;

    printf("-----------------------------------\n");
    printf("           JEU DU PENDU           \n");
    printf("-----------------------------------\n");
    printf("Avec quel thème souhaitez vous jouer ?\n");
    printf("1. Animaux\n");
    printf("2. Fruits\n");
    printf("3. Métiers\n");
    printf("4. Pays\n");
    printf("5. Sports\n");
    printf("6. Revenir en arriere\n");
    scanf("%d", &reponseThemes);

    /* switch (reponseThemes)
    {
    case 1:
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
        afficherMenu();
        break;
   default:
        printf("Cela ne fait pas partir des choix disponible veuillez reessayer");
        afficherThemes();
        break;
    } */
}

void Username() {

    char Username;
    char confirmation_Username;

    printf("Veuillez entrer votre nom d'utilisateur");
    scanf("%c", &Username);

    printf("Votre nom d'utilisateur est bien : %c ? Y/N", Username);

    if (confirmation_Username == 'Y') {

        /* Script BDD */
    
    } 
    
    else if (confirmation_Username == 'N') {

        Username();

    }   
}