#include <stdio.h>
#include "words.c"

int main(void) {
    printf(">>> JEU DU PENDU <<<\n");
    char* motChoisi = random_word();
    secret_word(motChoisi);    
    return 0;
}

