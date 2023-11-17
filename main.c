#include <stdio.h>
#include "words.c"
#include "menu.c"

#define NOMBRES_ESSAIS = 6;

int main(void) {
    printf(">>> JEU DU PENDU <<<\n");
    char* motChoisi = random_word();
    secret_word(motChoisi);    

    return 0;
}

