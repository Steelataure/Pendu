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
    int tentatives = 6; 

    int letters_found = 0; 
    printf("Choisi une lettre \n>");
    scanf("%c", &choice);
    char choiceUpper = toupper(choice);
    
    int longueur = strlen(word);
    int pos_letter_found[longueur];

    for (int i = 0; i < longueur; i++) {
        if (word[i] == choiceUpper){
            printf("Vous avez trouve la lettre %c \n", word[i]);
            pos_letter_found[letters_found] = i;
            letters_found++;        
        }
        else{
            tentatives -=1;
        }
    }
    printf("%d ", pos_letter_found);

    
}
