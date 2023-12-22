#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LONGUEUR_MAX 1024
#define MAX_LIGNES 5
#define LONGUEUR_MAX_USERNAME 10

typedef enum { MAIN_MENU, LEVELS, GAME, CREDITS, RULES, THEMES, RANK} GameState;

Rectangle newGameButtonBounds;
Rectangle rankButtonBounds;
Rectangle rulesButtonBounds;
Rectangle creditsButtonBounds;
Rectangle backButtonBounds;
Rectangle easyButtonBounds;
Rectangle intermediateButtonBounds;
Rectangle difficultButtonBounds;
Rectangle animalsButtonBounds;
Rectangle fruitsButtonBounds;
Rectangle countryButtonBounds;
Rectangle workButtonBounds;
Rectangle resetButtonsBounds;
Rectangle sportsButtonBounds;
Rectangle colorsButtonsBounds;
Texture2D backgroundTexture;
Texture2D creditsBackgroundTexture;
Texture2D rulesBackgroundTexture;
Texture2D difficultyBackgroundTexture;
Texture2D themesBackgroundTexture; 
Texture2D rankBackgroundTexture;
Texture2D test; 
Texture2D penduImages[7];

GameState gameState = MAIN_MENU;
bool rulesWindow = false;

const char* animaux[] = {"lion", "tigre", "singe", "chien", "aigle", "elephant", "girafe", "chouette", "suricate", "antilope", "hirondelle", "rhinoceros", "raphicere", "rossignol", "cephalophe"};
const char* fruits[] = {"pomme", "kiwi", "goji", "melon", "mikan","orange", "banane", "fraise", "mangue", "cerise", "groseille", "calamondin", "framboise", "nectarine", "mandarine"};
const char* pays[] = {"qatar", "perou", "japon", "niger", "liban", "vietnam", "zimbabwe", "bresil", "france", "nigeria", "papouasie", "tadjikistan", "allemagne", "australie", "venezuela"};
const char* metiers[] = {"agent", "juge", "guide", "garde", "clown", "medecin", "eboueur", "barista", "pilote", "dentiste", "consultant", "infirmier", "professeur", "architecte", "informaticien"};
const char* sports[] = {"apnee", "boxe", "lutte", "ski", "golf", "aquagym", "baseball", "natation", "tennis", "football","taekwondo", "wakeboard", "equitation", "canyoning", "athletisme"};
const char* couleurs[] = {"rouge", "vert", "bleu", "blanc", "noir", "marron", "orange", "magenta", "ecarlate", "orpiment","aubergine", "vermillon", "citrouille", "amethyste", "polychrome"};


bool CheckVictoire(void);
const char* TheWord(const char* theme);
void DrawMainMenu(void);
void DrawNewGame(void);
void DrawCredits(void);
void DrawRules(void);
void DrawJeu(void);
const char* DrawThemes();
char HandleTextInput(void);
void DrawRank(void);
const char* LectureFichier();
void ResetGame();


int main(void) {
    // Initialisation de la fenêtre
    InitWindow(800, 600, "Pendu");
    // Chargement de l'image de fond de la page MENU
    Image background = LoadImage("assets/menu.png");
    backgroundTexture = LoadTextureFromImage(background);
    UnloadImage(background);

    // Chargement de l'image de fond de la page CREDITS
    Image creditsBackground = LoadImage("assets/credit.png");
    creditsBackgroundTexture = LoadTextureFromImage(creditsBackground);
    UnloadImage(creditsBackground);

    // Chargement de l'image de fond des thèmes
    Image themesBackground = LoadImage("assets/theme.png");
    themesBackgroundTexture = LoadTextureFromImage(themesBackground);
    UnloadImage(themesBackground);

    // Chargement de l'image de fond de la page REGLES
    Image rulesBackground = LoadImage("assets/regles.png");
    rulesBackgroundTexture = LoadTextureFromImage(rulesBackground);
    UnloadImage(rulesBackground);

    // Chargement de l'image de fond pour le MENU de DIFFICULTES
    Image difficultyBackground = LoadImage("assets/niveaux.png");
    difficultyBackgroundTexture = LoadTextureFromImage(difficultyBackground);
    UnloadImage(difficultyBackground);

    // Chargement de l'image de fond pour le menu de CLASSEMENT
    Image rankBackground = LoadImage("assets/score.png");
    rankBackgroundTexture = LoadTextureFromImage(rankBackground);
    UnloadImage(rankBackground);

    // Chargez les images "pendu" pour chaque nombre d'essai
    for (int i = 0; i <= 7; i++) {
        char imagePath[50];
        sprintf(imagePath, "assets/pendu%d.png", i + 1);
        Image penduImage = LoadImage(imagePath);
        penduImages[i] = LoadTextureFromImage(penduImage);
        UnloadImage(penduImage);
    }

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
    backButtonBounds = (Rectangle){GetScreenWidth() - 70, 10, 60, 30};
    rankButtonBounds = (Rectangle){creditsButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 50, buttonWidth, 50};

// Centre les boutons de la page "Nouvelle Partie"
    int totalButtonsWidth = 3 * buttonWidth + 2 * buttonSpacing; // Largeur totale des trois boutons et deux espaces entre eux
    easyButtonBounds = (Rectangle){(screenWidth - totalButtonsWidth) / 2, screenHeight / 2 - 30, buttonWidth, 50};
    intermediateButtonBounds = (Rectangle){easyButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 30, buttonWidth, 50};
    difficultButtonBounds = (Rectangle){intermediateButtonBounds.x + buttonWidth + buttonSpacing, screenHeight / 2 - 30, buttonWidth, 50};

    // Placement des boutons page THEMES
    int buttonWidthbis = 100;
    int buttonSpacingbis = 10;

// Centre les boutons de la page "Themes"

    int totalbisButtonsWidth = 6 * buttonWidthbis + 1 * buttonSpacingbis; // Largeur totale des six boutons et deux espaces entre eux
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
            case LEVELS:
                DrawNewGame();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case THEMES:
                DrawThemes();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case GAME:
                DrawJeu();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case CREDITS:
                DrawCredits();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case RANK:
                DrawRank();
                PlayMusicStream(musique);
                UpdateMusicStream(musique);
                break;
            case RULES:
                DrawRules();
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
    UnloadTexture(themesBackgroundTexture);
    UnloadTexture(difficultyBackgroundTexture);
    UnloadTexture(rankBackgroundTexture);
    UnloadTexture(themesBackgroundTexture);
    UnloadMusicStream(musique);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

static const char* motSecret = NULL;

char lettresCorrectes[26]; // Tableau pour stocker les lettres correctes (26 lettres de l'alphabet)
char lettresIncorrectes[26]; // Tableau pour stocker les lettres incorrectes
int essaisRestants = 6; // Vous pouvez ajuster cela selon le nombre d'essais que vous voulez accorder

char input_lettre[2] = ""; // Modifiez la taille du tableau à 2 pour un seul caractère
bool inputName = false;
static bool motSecretChoisi = false;

void DrawJeu(void) {
    BeginDrawing();
    Color customColor = (Color){253, 231, 190, 255};
    ClearBackground(customColor);
    if (!motSecretChoisi) {
        motSecret = TheWord(DrawThemes());
        motSecretChoisi = true;
    }

    // Utilisez la variable motSecret ici
    if (motSecret != NULL) {
        // Dessinez l'image correspondante au nombre d'essais restants

        int indexImage = (essaisRestants > 0) ? essaisRestants - 1 : 0;
        DrawTexture(penduImages[indexImage + 1], 0, 0, RAYWHITE);
        
        if (essaisRestants == 0){
            DrawTexture(penduImages[0], 0, 0, RAYWHITE);
        }

        // Dessinez le mot caché
        //DrawText("Mot caché :", 100, 50, 20, BLACK);
        int x = 100;

        for (int i = 0; i < strlen(motSecret); i++) {
            char lettre = motSecret[i];

            if (lettre == ' ') {
                // Si c'est un espace, dessinez simplement un espace
                DrawText(" ", x, 120, 22, BLACK);
            }

            else {
                bool lettreDevinee = strchr(lettresCorrectes, lettre) != NULL;

                if (lettreDevinee) {
                    // Si la lettre a été devinée, dessinez la lettre
                    DrawText(&lettre, x, 120, 22, BLACK);
                } else {
                    // Sinon, dessinez un trait souligné
                    DrawText("_", x, 120, 22, BLACK);
                }

                // Mettez à jour la position pour la lettre suivante
                x += (lettreDevinee || lettre == ' ') ? MeasureText(&lettre, 20) + 5 : MeasureText("_", 20) + 5;
            }
        }

        // Dessinez les lettres déjà devinées
        DrawText("Lettres devinées :", 100, 180, 20, BLACK);
        DrawText(lettresCorrectes, 100, 210, 20, GREEN);
        DrawText(lettresIncorrectes, 100, 240, 20, RED);
        //DrawText(motSecret, 400, 240, 20, BLACK);

        // Dessinez le nombre d'essais restants
        DrawText(TextFormat("Essais restants : %d", (essaisRestants > 0) ? essaisRestants : 0), 475, 15, 20, BLACK);

        // Si toutes les lettres correctes ont été trouvées, le joueur a gagné
        if (CheckVictoire()) {
            DrawText("VICTOIRE", GetScreenWidth()/2, 240, 60, BLACK);
            ResetGame();


        } else if (essaisRestants == 0) {
            DrawText("PERDU", GetScreenWidth()/2, 240, 60, BLACK);
            ResetGame();
        }
    }

    // Affichage du bouton "Retour"
    DrawRectangleRec(backButtonBounds, BROWN);
    DrawText("Retour", (int)(backButtonBounds.x + backButtonBounds.width / 2 - MeasureText("Retour", 16) / 2), (int)(backButtonBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Retour"
    if (CheckCollisionPointRec(GetMousePosition(), backButtonBounds)) {
        DrawRectangleLinesEx(backButtonBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            gameState = THEMES;
        }
    }
    HandleTextInput();
    EndDrawing();
}

void ResetGame() {

    // Affichage du bouton "Rejouer"
    resetButtonsBounds = (Rectangle){GetScreenWidth() - 70, 50, 60, 30};
    DrawRectangleRec(resetButtonsBounds, BROWN);
    DrawText("Rejouer", (int)(resetButtonsBounds.x + resetButtonsBounds.width / 2 - MeasureText("Rejouer", 16) / 2), (int)(resetButtonsBounds.y + 5), 16, BLACK);

    // Pointeur du bouton "Rejouer"
    if (CheckCollisionPointRec(GetMousePosition(), resetButtonsBounds)) {
        DrawRectangleLinesEx(resetButtonsBounds, 2, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            essaisRestants = 6;
            motSecret = NULL;
            motSecretChoisi = false;
            memset(lettresCorrectes, '\0', sizeof(lettresCorrectes));
            memset(lettresIncorrectes, '\0', sizeof(lettresIncorrectes));
            memset(input_lettre, '\0', sizeof(input_lettre));
            gameState = MAIN_MENU;
        }
    }
}

// Fonction pour vérifier si toutes les lettres correctes ont été trouvées dans le mot secret
bool CheckVictoire(void) {
    for (int i = 0; i < strlen(motSecret); i++) {
        char lettre = motSecret[i];

        if (lettre != ' ' && strchr(lettresCorrectes, lettre) == NULL) {
            return false;
        }
    }

    // Toutes les lettres correctes ont été trouvées dans le mot secret
    return true;
}

char HandleTextInput(void) {
    DrawText("Entrez une lettre : ", 100, 300, 20, BLACK);
    DrawRectangleLines(100, 330, 40, 40, BLACK);
    DrawText(input_lettre, 110, 340, 20, BLACK);
    int key = GetKeyPressed();

    if (key != 0 && essaisRestants > 0) {
        // Remappage des touches Q, W et M
        if (key == KEY_Q) {
            key = KEY_A;  
        } else if (key == KEY_W) {
            key = KEY_Z;  
        } else if (key == KEY_M) {
            key = KEY_COMMA;
        }
        // Remappage des touches A, Z et ,
        else if (key == KEY_A) {
            key = KEY_Q;  
        } else if (key == KEY_Z) {
            key = KEY_W; 
        } else if (key == KEY_SEMICOLON) {
            key = KEY_M; 
        }

        if (key == KEY_BACKSPACE && input_lettre[0] != '\0') {
            input_lettre[0] = '\0';
        } else if ((key >= KEY_A && key <= KEY_Z) || (key >= KEY_ZERO && key <= KEY_NINE)) {
            // Convertir la lettre en minuscule avant de l'ajouter
            input_lettre[0] = (char)tolower(key);
            input_lettre[1] = '\0';

            // Convertir le mot secret en minuscules
            char motSecretLower[strlen(motSecret) + 1];
            strcpy(motSecretLower, motSecret);
            strlwr(motSecretLower);

            // Vérifier si la lettre a déjà été entrée
            if (strchr(lettresCorrectes, input_lettre[0]) == NULL && strchr(lettresIncorrectes, input_lettre[0]) == NULL) {
                // La lettre n'a pas été entrée, procéder
                if (strchr(motSecretLower, input_lettre[0]) != NULL) {
                    strncat(lettresCorrectes, input_lettre, 1);
                } else {
                    strncat(lettresIncorrectes, input_lettre, 1);
                    essaisRestants--;
                }
            }
        }
    }

    return '\0';
}



const char* TheWord(const char* theme) {
    const char** word_array = NULL;
    int array_size = 0;

    if (strcmp(theme, "animaux") == 0) {
        word_array = animaux;
        array_size = sizeof(animaux) / sizeof(animaux[0]);
    } else if (strcmp(theme, "fruits") == 0) {
        word_array = fruits;
        array_size = sizeof(fruits) / sizeof(fruits[0]);
    } else if (strcmp(theme, "pays") == 0) {
        word_array = pays;
        array_size = sizeof(pays) / sizeof(pays[0]);
    } else if (strcmp(theme, "metiers") == 0) {
        word_array = metiers;
        array_size = sizeof(metiers) / sizeof(metiers[0]);
    } else if (strcmp(theme, "sports") == 0) {
        word_array = sports;
        array_size = sizeof(sports) / sizeof(sports[0]);
    } else if (strcmp(theme, "couleurs") == 0) {
        word_array = couleurs;
        array_size = sizeof(couleurs) / sizeof(couleurs[0]);
    } else {
        fprintf(stderr, "Theme non trouve\n");
        exit(EXIT_FAILURE);
    }

    int random_index = rand() % array_size;

    // Ajoutez un message pour déboguer
    printf("Theme : %s, Mot secret : %s\n", theme, word_array[random_index]);

    return word_array[random_index];
}

// Fonction de la page du MENU
void DrawMainMenu(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(backgroundTexture, 0, 0, RAYWHITE);

    // Tableaux pour les boutons et les labels correspondants
    Rectangle bounds[] = { newGameButtonBounds, rulesButtonBounds, creditsButtonBounds, rankButtonBounds };
    const char* labels[] = { "Nouvelle Partie", "Règles du jeu", "Crédits", "Classement" };

    for (int i = 0; i < sizeof(bounds) / sizeof(bounds[0]); i++) {
        DrawRectangleRec(bounds[i], BROWN);
        
        // Taille de la police
        int fontSize = 20;

        // Calcul de la position verticale du texte
        int yPos = (int)(bounds[i].y + 15);

        DrawText(labels[i], (int)(bounds[i].x + bounds[i].width / 2 - MeasureText(labels[i], fontSize) / 2), yPos, fontSize, BLACK);

        // Vérifier si la souris est sur le bouton
        if (CheckCollisionPointRec(GetMousePosition(), bounds[i])) {
            DrawRectangleLinesEx(bounds[i], 2, WHITE);
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                if (strcmp(labels[i], "Nouvelle Partie") == 0) {
                    gameState = LEVELS;
                } else if (strcmp(labels[i], "Règles du jeu") == 0) {
                    gameState = RULES;
                    rulesWindow = true;
                } else if (strcmp(labels[i], "Crédits") == 0) {
                    gameState = CREDITS;
                } else if (strcmp(labels[i], "Classement") == 0) {
                    gameState = RANK;
                }
            }
        }
    }

    EndDrawing();
}

void DrawNewGame(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(difficultyBackgroundTexture, 0, 0, RAYWHITE);

    // Tableaux pour les boutons et les labels correspondants
    Rectangle bounds[] = { easyButtonBounds, intermediateButtonBounds, difficultButtonBounds, backButtonBounds };
    const char* labels[] = { "Facile", "Intermédiaire", "Difficile", "Retour" };

    for (int i = 0; i < sizeof(bounds) / sizeof(bounds[0]); i++) {
        DrawRectangleRec(bounds[i], BROWN);

        // Déterminer la taille de la police en fonction du label
        int fontSize = (strcmp(labels[i], "Retour") == 0) ? 16 : 20;

        // Calculer la position verticale du texte
        int yPos = (strcmp(labels[i], "Retour") == 0) ? (int)(bounds[i].y + 5) : (int)(bounds[i].y + 15);

        DrawText(labels[i], (int)(bounds[i].x + bounds[i].width / 2 - MeasureText(labels[i], fontSize) / 2), 
                 yPos, fontSize, BLACK);

        // Vérifier si la souris est sur le bouton
        if (CheckCollisionPointRec(GetMousePosition(), bounds[i])) {
            DrawRectangleLinesEx(bounds[i], 2, WHITE);
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                if (strcmp(labels[i], "Retour") == 0) {
                    gameState = MAIN_MENU;
                } else {
                    gameState = THEMES;
                }
            }
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

const char* DrawThemes() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(themesBackgroundTexture, 0, 0, RAYWHITE);

    // Tableaux de boutons, de thèmes et de labels correspondants
    Rectangle bounds[] = { animalsButtonBounds, fruitsButtonBounds, countryButtonBounds, workButtonBounds, sportsButtonBounds, colorsButtonsBounds, backButtonBounds };
    const char* themes[] = { "animaux", "fruits", "pays", "metiers", "sports", "couleurs", "" };
    const char* labels[] = { "Animaux", "Fruits", "Pays", "Métiers", "Sports", "Couleurs", "Retour" };

    for (int i = 0; i < sizeof(bounds) / sizeof(bounds[0]); i++) {
        DrawRectangleRec(bounds[i], BROWN);
        
        // Définir la taille de la police en fonction du label
        int fontSize = (strcmp(labels[i], "Retour") == 0) ? 16 : 20;

        // Calculer la position verticale du texte en fonction de la taille de la police
        int yPos = (strcmp(labels[i], "Retour") == 0) ? (int)(bounds[i].y + 5) : (int)(bounds[i].y + 15);

        DrawText(labels[i], (int)(bounds[i].x + bounds[i].width / 2 - MeasureText(labels[i], fontSize) / 2), 
                 yPos, fontSize, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), bounds[i])) {
            DrawRectangleLinesEx(bounds[i], 2, WHITE);
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                if (strcmp(themes[i], "") == 0) {  // Si c'est le bouton "Retour"
                    gameState = LEVELS;
                } else {
                    gameState = GAME;  // Sinon, passer à l'état GAME
                }
                return themes[i];
            }
        }
    }

    EndDrawing();
    return "";
}



void DrawRank(void) {
    BeginDrawing();

    // Afficher l'image de fond pour la page "Classement"
    DrawTexture(rankBackgroundTexture, 0, 0, RAYWHITE);

    // Affichage du classement
    DrawText(LectureFichier(), 200, 120, 30, BLACK);

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

const char* LectureFichier() {

    FILE* rank = fopen("assets/rank.txt", "r"); // Ouverture du fichier en lecture
    static char chaine[LONGUEUR_MAX]; 
    static char concatenatedLines[MAX_LIGNES];
    concatenatedLines[0] = '\0';

    for (int i = 0; i < 4; i++)
    {
        if(fgets(chaine, LONGUEUR_MAX, rank) != NULL) {
            if (chaine[0] <= '4') {
            strcat(concatenatedLines, chaine);
            }
            if (strlen(concatenatedLines) == MAX_LIGNES) {
                break;
            }
        }
        else {
            exit(EXIT_FAILURE);
        }
    }      
    fclose(rank);
    return concatenatedLines;
}