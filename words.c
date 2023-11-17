#include <stdio.h>
#include <string.h>
#include "jsmn.h"


char* random_word() {
    printf(">> Un mot a ete choisi <<\n");
    char* word = "TEST";
    return word;
}

void secret_word(char* word) {
    int longueur = strlen(word);
    printf("Le mot secret est : ");
    for (int i = 0; i < longueur; i++) {
        printf("_ ");
    }
    printf("\n");
}