void afficherPendu(int nombres_Erreurs) {
    printf("\n\n");
    switch (echecs) {
        case 0:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("            |\n");
            printf("            |\n");
            printf("            |\n");
            printf("            |\n");
            printf("    :=======:\n");
            break;
        case 1:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("            |\n");
            printf("            |\n");
            printf("            |\n");
            printf("    :=======:\n");
            break;
        case 2:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("        |   |\n");
            printf("            |\n");
            printf("            |\n");
            printf("    :=======:\n");
            break;
        case 3:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("       /|   |\n");
            printf("            |\n");
            printf("            |\n");
            printf("    :=======:\n");
            break;
        case 4:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("       /|\\  |\n");
            printf("        |   |\n");
            printf("            |\n");
            printf("    :=======:\n");
            break;
        case 5:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("       /|\\  |\n");
            printf("        |   |\n");
            printf("         \\  |\n");
            printf("    :=======:\n");
            break;
        case 6:
            printf("        +---+\n");
            printf("        |   |\n");
            printf("        O   |\n");
            printf("       /|\\  |\n");
            printf("        |   |\n");
            printf("       / \\  |\n");
            printf("    :=======:\n");
            break;
        default:
            printf("Impossible d'afficher le Hangman, veuillez vérifier pendu.c\n\n");
            break;
    }
}