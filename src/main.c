#include <stdio.h>

void usagePrint()
{
  printf("Usage: program -f fichier [-s nombre | -i]");
  printf("\n");
  printf("\n");
  printf("-f fichier (obligatoire) : fichier à analyser.");
  printf("\n");
  printf("-s nombre (facultatif) : affiche les chaînes d'au moins nombre caractères.");
  printf("\n");
  printf("-i (facultatif) : affiche le format du fichier.");
  printf("\n");
  printf("\n");
  printf("Sans -s ni -i, le programme affiche les données en hexadécimal.");
}

/// @brief Fonction principale
/// @param argc Nombre d'arguments
/// @param argv Arguments
/// @return Code de fin de programme
int main(int argc, char *argv[]){

  for (size_t i = 0; i < argc; ++i){
    printf("%s\n", argv[i]);
  }
  
  
  return 0;
}