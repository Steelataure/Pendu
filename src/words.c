#include <stdio.h>
#include <string.h>
#include "include/jsmn.h"


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
        //A rajouter par la suite
        // if (letters_found[i]) {
        //     printf("%c ", word[i]);
        // }
        // else{
        //     printf("_ ");
        // }
    }
    printf("\n");
}

void user_choice(char* word){
    char choice;
    //int letters_found = 0; 

    printf("Choisi une lettre \n>");
    scanf("%c", &choice);
    int longueur = strlen(word);
    for (int i = 0; i < longueur; i++) {
        if (word[i] == choice){
            printf("Vous avez trouve la lettre %c \n", word[i]);
        }
    }
}
