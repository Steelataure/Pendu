#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* animaux[] = {"lion", "elephant", "girafe", "tigre", "singe", "chien"};
const char* fruits[] = {"pomme", "banane", "fraise", "kiwi", "orange"};
const char* pays[] = {"France", "Etats-Unis", "Japon", "Bresil", "Australie"};
const char* metiers[] = {"medecin", "infirmier", "professeur", "architecte", "informaticien"};
const char* sports[] = {"football", "basketball", "tennis", "natation", "golf"};
const char* couleurs[] = {"rouge", "vert", "bleu", "jaune", "noir", "rose", "marron"};

const char* random_word(const char* theme) {
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
    for (int i = 0; i < array_size; ++i) {
        if ((strlen(word_array[i]) < 6 && strlen(word_array[0]) < 6) || (strlen(word_array[i]) >= 6 && strlen(word_array[0]) >= 6)) {
            printf("%s\n", word_array[i]);
        }
    }
    int random_index = rand() % array_size;

    return word_array[random_index];
}

