#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void afficherEntete()
{
  printf("         "); // 9 espaces : largeur de "0x000000" + 1
  for (int i = 0; i < 16; i++)
  {
    printf("%2X ", i); // chiffre hexadécimal sur 2 caractères + espace
  }
  printf("ASCII\n");
}

void afficherUsage()
{
  printf("Usage: program -f fichier [-s nombre | -i]");
  printf("\n");
  printf("\n");
  printf("-f fichier (obligatoire) : fichier a analyser.");
  printf("\n");
  printf("-s nombre (facultatif) : affiche les chaines d'au moins nombre caracteres.");
  printf("\n");
  printf("-i (facultatif) : affiche le format du fichier.");
  printf("\n");
  printf("\n");
  printf("Sans -s ni -i, le programme affiche les donnees en hexadecimal.");
}

void programmeAffichage(FILE *fichier, char *nomFichier, int optionS, int valeurArgS, int optionI)
{

  long tailleFichier;
  long restant;
  unsigned int adresse = 0;
  int aLire;
  unsigned char contenuFichier[16];
  short erreur = 0;

  // Validation de l'exclusivité de -s et -i
  if (optionS && optionI)
  {
    printf("\nLes arguments -s et -i ne peuvent etre ensemble!");
    return;
  }

  // Validation de la valeur du argument -s
  if (valeurArgS <= 0 && optionS)
  {
    // le nombre a la valeur de 0(est un charactère) ou est négatif, il est invalide.
    printf("Nombre inferieur ou egal a zero!");
    return;
  }

  if (optionS)
  {
    printf("option -s");
  }
  else if (optionI)
  {
    printf("option -i");
  }
  else
  {

    // Ouverture du fichier

    fseek(fichier, 0, SEEK_END);

    tailleFichier = ftell(fichier);

    restant = tailleFichier;

    fseek(fichier, 0, SEEK_SET);

    afficherEntete();

    while (restant > 0)
    {

      // 4a. Nombre d'octets à lire
      if (restant >= 16)
      {
        aLire = 16;
      }
      else
      {
        aLire = restant;
      }

      // 4b. Lecture
      fread(contenuFichier, 1, aLire, fichier);

      // 4c. Adresse
      printf("0x%06X ", adresse);

      // 4d. Octets en hexadécimal
      for (int i = 0; i < aLire; i++)
      {
        printf("%02X ", contenuFichier[i]);
      }

      // 4e. Remplissage si la ligne est incomplète
      for (int i = aLire; i < 16; i++)
      {
        printf("00 ");
      }

      // 4f. Colonne ASCII
      for (int i = 0; i < aLire; i++)
      {
        if (contenuFichier[i] >= ' ' && contenuFichier[i] <= '~')
        {
          printf("%c", contenuFichier[i]);
        }
        else
        {
          printf(".");
        }
      }

      // 4g. Fin de ligne et mises à jour
      printf("\n");
      adresse = adresse + 16;
      restant = restant - aLire;
    }
  }
}

/// @brief Fonction principale
/// @param argc Nombre d'arguments
/// @param argv Arguments
/// @return Code de fin de programme
int main(int argc, char *argv[])
{
  FILE *fichier;
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
      nombreS = atoi(argv[indexS]);
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

  // si -f n'est pas présent
  if (!indexF)
  {
    afficherUsage();
    return 1;
  }

  // Validation du fichier
  fichier = fopen(argv[indexF], "rb");

  if (fichier)
  {
    programmeAffichage(fichier, argv[indexF], indexS, nombreS, indexI);
    fclose(fichier);
  }
  else
  {
    printf("Fichier inexistant!");
    return 1;
  }

  return 0;
}