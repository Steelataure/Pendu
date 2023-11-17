#include <stdio.h>
#include "main.h"
#include "words.c"
#include "menu.c"


int main(void) {
    printf(">>> JEU DU PENDU <<<\n");
    char* motChoisi = random_word();
    secret_word(motChoisi);    

    //TODO (NOMBRE_ESSAI < 6)
    while (1){
        user_choice(motChoisi);
    }
    return 0;
}       

