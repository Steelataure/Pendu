#include "raylib.h"
#include <stdio.h>

#define LONGUEUR_MAX 1024

typedef enum { MAIN_MENU, NEW_GAME, CREDITS, RULES, THEMES, RANK } GameState;

Rectangle newGameButtonBounds;
Rectangle rulesButtonBounds;
Rectangle creditsButtonBounds;
Rectangle rankButtonBounds;
Rectangle backButtonBounds;
Rectangle easyButtonBounds;
Rectangle intermediateButtonBounds;
Rectangle difficultButtonBounds;
Rectangle animalsButtonBounds;
Rectangle fruitsButtonBounds;
Rectangle countryButtonBounds;
Rectangle workButtonBounds;
Rectangle sportsButtonBounds;
Rectangle colorsButtonsBounds;
Texture2D backgroundTexture;
Texture2D creditsBackgroundTexture;
Texture2D rulesBackgroundTexture;
Texture2D difficultyBackgroundTexture; //  texture pour l'image de fond des boutons de difficulté
Texture2D themesBackgroundTexture; 
Texture2D rankBackgroundTexture; 
GameState gameState = MAIN_MENU;
bool rulesWindow = false;

void DrawMainMenu(void);
void DrawNewGame(void);
void DrawCredits(void);
void DrawRules(void);
void DrawRank(void);
const char* DrawThemes();
const char* LectureFichier();

int main(void) {
    // Initialisation de la fenêtre
    InitWindow(800, 600, "Pendu");

    // Chargement de l'image de fond de la page MENU
    Image background = LoadImage("assets/pendu.png");
    backgroundTexture = LoadTextureFromImage(background);
    UnloadImage(background);

    // Chargement de l'image de fond de la page CREDITS
    Image creditsBackground = LoadImage("assets/credit.png");
    creditsBackgroundTexture = LoadTextureFromImage(creditsBackground);
    UnloadImage(creditsBackground);

    // Chargement de l'image de fond de la page REGLES
    Image rulesBackground = LoadImage("assets/regles.png");
    rulesBackgroundTexture = LoadTextureFromImage(rulesBackground);
    UnloadImage(rulesBackground);

    // Chargement de l'image de fond pour le MENU de DIFFICULTES
    Image difficultyBackground = LoadImage("assets/niveaux.png");
    difficultyBackgroundTexture = LoadTextureFromImage(difficultyBackground);
    UnloadImage(difficultyBackground);

    // Chargement de l'image de fond des thèmes
    Image themesBackground = LoadImage("assets/niveaux.png");
    themesBackgroundTexture = difficultyBackgroundTexture;
    UnloadImage(themesBackground);

    // Chargement de l'image de fond du classement
    Image rankBackground = LoadImage("assets/score.png");
    rankBackgroundTexture = LoadTextureFromImage(rankBackground);
    UnloadImage(rankBackground);

    // Chargement de la musique
    InitAudioDevice();
    IsAudioDeviceReady();
    Music musique = LoadMusicStream("assets/Sandstorm-_8-Bit-NES-Remix_.mp3");

    // Placement des boutons page MENU
    int buttonWidth = 175;
    int buttonSpacing = 20; // Espace entre les boutons
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    newGameButtonBounds = (Rectangle){(screenWidth - 4 * buttonWidth - 2 * buttonSpacing) / 2, screenHeight / 2 - 50, buttonWidth, 50};
    rulesButtonBounds = (Rectangle){newGameButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 50, buttonWidth, 50};
    creditsButtonBounds = (Rectangle){rulesButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 50, buttonWidth, 50};
    rankButtonBounds = (Rectangle){creditsButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 50, buttonWidth, 50};
    backButtonBounds = (Rectangle){GetScreenWidth() - 70, 10, 60, 30};

// Centre les boutons de la page "Nouvelle Partie"
    int totalButtonsWidth = 3 * buttonWidth + 2 * buttonSpacing; // Largeur totale des trois boutons et deux espaces entre eux
    easyButtonBounds = (Rectangle){(screenWidth - totalButtonsWidth) / 2, screenHeight / 2 - 30, buttonWidth, 50};
    intermediateButtonBounds = (Rectangle){easyButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 30, buttonWidth, 50};
    difficultButtonBounds = (Rectangle){intermediateButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 30, buttonWidth, 50};

    // Placement des boutons page THEMES
    int buttonWidthbis = 100;
    int buttonSpacingbis = 20;


// Centre les boutons de la page "Themes"
    int totalbisButtonsWidth = 7 * buttonWidthbis + 1 * buttonSpacingbis; // Largeur totale des six boutons et deux espaces entre eux
    animalsButtonBounds = (Rectangle){(screenWidth - totalbisButtonsWidth) / 2, screenHeight / 2 - 30, buttonWidthbis, 50};
    fruitsButtonBounds = (Rectangle){animalsButtonBounds.x + buttonWidthbis + buttonSpacingbis, screenHeight / 2 - 30, buttonWidthbis, 50};
    countryButtonBounds = (Rectangle){fruitsButtonBounds.x + buttonWidthbis + buttonSpacingbis, screenHeight / 2 - 30, buttonWidthbis, 50};
    workButtonBounds = (Rectangle){countryButtonBounds.x + buttonWidthbis + buttonSpacingbis, screenHeight / 2 - 30, buttonWidthbis, 50};
    sportsButtonBounds = (Rectangle){workButtonBounds.x + buttonWidthbis + buttonSpacingbis, screenHeight / 2 - 30, buttonWidthbis, 50};
    colorsButtonsBounds = (Rectangle){sportsButtonBounds.x + buttonWidthbis + buttonSpacingbis, screenHeight / 2 - 30, buttonWidthbis, 50}; 

    while (!WindowShouldClose()) {
        switch (gameState) {
            case MAIN_MENU:
                DrawMainMenu();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case NEW_GAME:
                DrawNewGame();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case THEMES:
                DrawThemes();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case CREDITS:
                DrawCredits();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case RULES:
                DrawRules();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case RANK:
                DrawRank();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            default:
                break;
        }
    }

    // Liberation de la mémoire de la texture de fond
    UnloadTexture(backgroundTexture);
    UnloadTexture(creditsBackgroundTexture);
    UnloadTexture(rulesBackgroundTexture);
    UnloadTexture(difficultyBackgroundTexture);
    UnloadMusicStream(musique);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}


// Fonction de la page du MENU
void DrawMainMenu(void) {
    BeginDrawing();

    // Affichage de l'image de fond
    DrawTexture(backgroundTexture, 0, 0, RAYWHITE);

    // Espace entre les boutons
    //int buttonSpacing = 20;

    // Affichage bouton "Nouvelle Partie"
    DrawRectangleRec(newGameButtonBounds, BROWN);
    DrawText("Nouvelle Partie", (int)(newGameButtonBounds.x + newGameButtonBounds.width / 2 - MeasureText("Nouvelle Partie", 20) / 2), (int)(newGameButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Nouvelle Partie"
    if (CheckCollisionPointRec(GetMousePosition(), newGameButtonBounds)) {
        DrawRectangleLinesEx(newGameButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = NEW_GAME;
        }
    }

    // Affichage du bouton "Règles du jeu"
    DrawRectangleRec(rulesButtonBounds, BROWN);
    DrawText("Règles du jeu", (int)(rulesButtonBounds.x + rulesButtonBounds.width / 2 - MeasureText("Règles du jeu", 20) / 2), (int)(rulesButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Règles du jeu"
    if (CheckCollisionPointRec(GetMousePosition(), rulesButtonBounds)) {
        DrawRectangleLinesEx(rulesButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = RULES;
            rulesWindow = true; // Activer la fenêtre des règles
        }
    }

    // Affichage du bouton "Crédits"
    DrawRectangleRec(creditsButtonBounds, BROWN);
    DrawText("Crédits", (int)(creditsButtonBounds.x + creditsButtonBounds.width / 2 - MeasureText("Crédits", 20) / 2), (int)(creditsButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Crédits"
    if (CheckCollisionPointRec(GetMousePosition(), creditsButtonBounds)) {
        DrawRectangleLinesEx(creditsButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = CREDITS;
        }
    }

    // Affichage du bouton "Classement"
    DrawRectangleRec(rankButtonBounds, BROWN);
    DrawText("Classement", (int)(rankButtonBounds.x + rankButtonBounds.width / 2 - MeasureText("Classement", 20) / 2), (int)(rankButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Crédits"
    if (CheckCollisionPointRec(GetMousePosition(), rankButtonBounds)) {
        DrawRectangleLinesEx(rankButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = RANK;
        }
    }

    

    EndDrawing();
}





// Fonction de la page "Nouvelle Partie"
void DrawNewGame(void) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Affichage de l'image de fond pour les boutons de difficulté
    DrawTexture(difficultyBackgroundTexture, 0, 0, RAYWHITE);

    // Affichage des boutons de "Facile"
    DrawRectangleRec(easyButtonBounds, BROWN);
    DrawText("Facile", (int)(easyButtonBounds.x + easyButtonBounds.width / 2 - MeasureText("Facile", 20) / 2), (int)(easyButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Facile"
    if (CheckCollisionPointRec(GetMousePosition(), easyButtonBounds)) {
        DrawRectangleLinesEx(easyButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = THEMES;
        }
    }

    // Affichage des boutons de "Intermediaire"
    DrawRectangleRec(intermediateButtonBounds, BROWN);
    DrawText("Intermédiaire", (int)(intermediateButtonBounds.x + intermediateButtonBounds.width / 2 - MeasureText("Intermédiaire", 20) / 2), (int)(intermediateButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Intermédiaire"
    if (CheckCollisionPointRec(GetMousePosition(), intermediateButtonBounds)) {
        DrawRectangleLinesEx(intermediateButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = THEMES;
        }
    }

    // Affichage des boutons de "Difficile"
    DrawRectangleRec(difficultButtonBounds, BROWN);
    DrawText("Difficile", (int)(difficultButtonBounds.x + difficultButtonBounds.width / 2 - MeasureText("Difficile", 20) / 2), (int)(difficultButtonBounds.y + 15), 20, BLACK);

    // Pointeur du bouton "Difficile"
    if (CheckCollisionPointRec(GetMousePosition(), difficultButtonBounds)) {
        DrawRectangleLinesEx(difficultButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = THEMES;
        }
    }

    // Affichage du bouton "Retour"
    DrawRectangleRec(backButtonBounds, BROWN);
    DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Retour"
    if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
        DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = MAIN_MENU;
        }
    }

    EndDrawing();
}






// Fonction de la page "Crédits"
void DrawCredits(void) {
    BeginDrawing();

    // Afficher l'image de fond pour la page "Crédits"
    DrawTexture(creditsBackgroundTexture, 0, 0, RAYWHITE);

    // Création du bouton "Retour"
    DrawRectangleRec(backButtonBounds, BROWN);
    DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Retour"
    if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
        DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = MAIN_MENU;
        }
    }

    EndDrawing();
}






// Fonction de la page "Règles du jeu"
void DrawRules(void) {
    if (rulesWindow) {
        BeginDrawing();

        // Affichage de l'image de fond pour la page "Règles du jeu"
        DrawTexture(rulesBackgroundTexture, 0, 0, RAYWHITE);

        // Affichage du bouton "Retour"
        DrawRectangleRec(backButtonBounds, BROWN);
        DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

        // Pointeur du bouton "Retour"
        if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
            DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                gameState = MAIN_MENU;
                rulesWindow = false; // Désactiver la fenêtre des règles
            }
        }

        EndDrawing();
    }
}

// Fonction de la page "Classement"

void DrawRank(void) {
    BeginDrawing();

    // Afficher l'image de fond pour la page "Crédits"
    DrawTexture(rankBackgroundTexture, 0, 0, RAYWHITE);

    LectureFichier();

    // Affichage du bouton "Retour"
    DrawRectangleRec(backButtonBounds, BROWN);
    DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Retour"
    if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
        DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = MAIN_MENU;
        }
    }

    EndDrawing();
}

// Fonction de la page "Themes"
const char* DrawThemes() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    //Affichage de l'image de fond pour les thèmes
    DrawTexture(themesBackgroundTexture, 0, 0, RAYWHITE);

    // Affichage du bouton animaux
    DrawRectangleRec(animalsButtonBounds, BROWN);
    DrawText("Animaux", (int)(animalsButtonBounds.x + animalsButtonBounds.width / 2 - MeasureText("Animaux", 20) / 2), (int)(animalsButtonBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "Animaux"
    if (CheckCollisionPointRec(GetMousePosition(), animalsButtonBounds)) {
        DrawRectangleLinesEx(animalsButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "animaux";
            // Mettre ici l'affichage du pendu selon Animaux
        }
    }

    // Affichage du bouton fruits
    DrawRectangleRec(fruitsButtonBounds, BROWN);
    DrawText("Fruits", (int)(fruitsButtonBounds.x + fruitsButtonBounds.width / 2 - MeasureText("Fruits", 20) / 2), (int)(fruitsButtonBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "Fruits"
    if (CheckCollisionPointRec(GetMousePosition(), fruitsButtonBounds)) {
        DrawRectangleLinesEx(fruitsButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "fruits";
            // Mettre ici l'affichage du pendu selon Fruits
        }
    }

    // Affichage du bouton pays
    DrawRectangleRec(countryButtonBounds, BROWN);
    DrawText("Pays", (int)(countryButtonBounds.x + countryButtonBounds.width / 2 - MeasureText("Pays", 20) / 2), (int)(countryButtonBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "Pays"
    if (CheckCollisionPointRec(GetMousePosition(), countryButtonBounds)) {
        DrawRectangleLinesEx(countryButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "pays";

            // Mettre ici l'affichage du pendu selon Pays
        }
    }

    // Affichage du bouton métiers
    DrawRectangleRec(workButtonBounds, BROWN);
    DrawText("Métiers", (int)(workButtonBounds.x + workButtonBounds.width / 2 - MeasureText("Métiers", 20) / 2), (int)(workButtonBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "métiers"
    if (CheckCollisionPointRec(GetMousePosition(), workButtonBounds)) {
        DrawRectangleLinesEx(workButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "metiers";
            // Mettre ici l'affichage du pendu selon métiers
        }
    }

    // Affichage du bouton Sports
    DrawRectangleRec(sportsButtonBounds, BROWN);
    DrawText("Sports", (int)(sportsButtonBounds.x + sportsButtonBounds.width / 2 - MeasureText("Sports", 20) / 2), (int)(sportsButtonBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "sports"
    if (CheckCollisionPointRec(GetMousePosition(), sportsButtonBounds)) {
        DrawRectangleLinesEx(sportsButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "sports";
            // Mettre ici l'affichage du pendu selon sports
        }
    }

    // Affichage du bouton couleurs
    DrawRectangleRec(colorsButtonsBounds, BROWN);
    DrawText("Couleurs", (int)(colorsButtonsBounds.x + colorsButtonsBounds.width / 2 - MeasureText("Couleurs", 20) / 2), (int)(colorsButtonsBounds.y + 15), 20, BLACK);

    //Pointeur du bouton "Couleurs"
    if (CheckCollisionPointRec(GetMousePosition(), colorsButtonsBounds)) {
        DrawRectangleLinesEx(colorsButtonsBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            return "couleur";
            // Mettre ici l'affichage du pendu selon Couleurs
        }
    }

    // Affichage du bouton "Retour"
    DrawRectangleRec(backButtonBounds, BROWN);
    DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Retour"
    if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
        DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = NEW_GAME;
        }
    }

    EndDrawing();
}

const char* LectureFichier() {

    FILE* rank = NULL; // Pointeur vers le flux
    char chaine[LONGUEUR_MAX] = "";

    rank = fopen("assets/rank.txt", "r"); // Ouverture du fichier en lecture

    if (rank != NULL) {
        while(fgets(chaine, LONGUEUR_MAX, rank) != NULL)
            if (chaine[0] <= 5) {
                return "%s";
            }
            else {
                LOG_ERROR == "Impossible de charger le fichier";
                gameState = MAIN_MENU;
            }
    }
} 