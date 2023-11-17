#include <stdio.h>

void ascii_pendu(int nombre_erreurs) {

    char pendu['''
  +---+\n
  |   |\n
      |\n
      |\n
      |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
      |\n
      |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
  |   |\n
      |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
 /|   |\n
      |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
 /|\  |\n
      |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
 /|\  |\n
 /    |\n
      |\n
=========\n''', '''
  +---+\n
  |   |\n
  O   |\n
 /|\  |\n
 / \  |\n
      |\n
=========\n''']

return pendu[nombre_erreurs];
}
