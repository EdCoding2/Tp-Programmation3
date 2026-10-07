#include <stdio.h>
#include <string.h>

void afficherUsage()
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
int main(int argc, char *argv[])
{
  FILE* fichier;
  int indexF = 0; // 0 = argument absent
  int indexS = 0; // indice de la valeur de -s dans argv
  int indexI = 0; // indice de -i dans argv
  int nombreS;

  // Étape 1 : Vérification du placement des arguments
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-f") == 0)
    {
      if (indexF || i + 1 >= argc)
      {
        afficherUsage();
        return 1;
      }
      indexF = ++i; // indice du nom de fichier
    }
    else if (strcmp(argv[i], "-s") == 0)
    {
      if (indexS || i + 1 >= argc)
      {
        afficherUsage();
        return 1;
      }
      indexS = ++i; // indice du nombre
    }
    else if (strcmp(argv[i], "-i") == 0)
    {
      if (indexI)
      {
        afficherUsage();
        return 1;
      }
      indexI = i;
    }
    else
    {
      afficherUsage(); // argument inconnu
      return 1;
    }
  }

  if (!indexF)
  {
    afficherUsage();
    return 1;
  }

  // Validation du fichier
  fichier = fopen(argv[indexF], "r");

  if(fichier)
    //on poursuit notre lecture
    fclose(fichier);
  else{
    printf("Fichier inexistant!");
    return 1;
  }

  // Validation de l'exclusivité de -s et -i
  if(indexI && indexF){
    printf("\nLes arguments -s et -i ne peuvent etre ensemble!");
    return 1;
  }

  // Validation de la valeur du argument -s
  if(nombreS <= 0){
    // le nombre a la valeur de 0(est un charactère) ou est négatif, il est invalide.
    printf("Nombre inferieur ou egal a zero!");
    return 1;
  }

  return 0;
}