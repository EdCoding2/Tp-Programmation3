# Question: 
c'est quoi le comportement d'un fopen

# Comment lancer à partir de la ligne cmd: x64 native tools
1. cl /Zi /W4 /EHsc main.c /Fe:program.exe
2. .\program.exe -f fichier -s 4 (exemple d'entrée)

Recompiler "1." pour que les changements de votre code soient appliqués

# Arguments

.\program.exe -f fichier -s 4

-> 5 arguments (argv[0 - 4])

Ignorer argv[0] (.\program.exe) -> commencer la boucle for à int i = 1

Faut d'abord développer un algorithme pour détecter où sont les arguments peu importe où ils sont.

---

Régles: 

1. -f est suivi du fichier  (i + 1) 
2. -s est suivi du "nombre" (i + 1)
3. -s et -i ne peuvent pas être ensemble. 
   


Pseudo-code:
// nous ne pouvons pas stocker la valeur de "char *argv[x] sur char exemple = argv[++i].
  
int indexF = 0; // 0 = argument absent
int indexS = 0; // indice de la **valeur** de -s dans argv
int indexI = 0; // indice de -i dans argv
// étant vu que nous ne pouvons pas stocker la valeur 

for(short i = 1; i < argc; ++i){
	if (strcmp(argv[i], "-f") == 0){
		if( indexF est vrai[s'il est vrai ça veut dire que il a été trouvé avant et nous avons trouvé une répétition]  OU si nous avons atteint la limite du tableau){
			usagePrint();
		}
	}

}

## Arguments inconnus
nous allons utiliser strcmp() pour détecter les différences des arguments

## Assurer les valeurs
1. valeur nom du fichier

le fichier peut être séparé par des dossiers:

>Desktop\src\text.txt

le fichier contient toujours une extension:

.exe

*Option 1*
si fopen ne fctionne pas (retourne un pointeur Null)
-> envoyer le message : "Fichier inexistant"


2. -s et -i sont exclusifs

si indexF et indexI (s'ils sont vrais)
-> erreur : "Les arguments -s et -i ne peuvent être ensemble!"

3. valeur de l'argument(-s) est numérique et positive

La fonction atoi(); retourne 0 si c'est un *char* qu'on essaye de transtyper en int.

printf("%d\n", atoi("-42")); // Output: -42 // pour les nombres négatifs.

Procédure:
nombreS = atoi(argv[indexS]);


if(nombre <= 0 && indexS){
	// le nombre a la valeur de 0(est un charactère) ou est négatif, il est invalide.
	printf("Nombre inferieur ou egal a zero!");
}

## Fonction de -s



## Passer d'un char -> int 
ATOI(Chaine);

pour transtyper le "nombre"(-s nombre) en int.


# Affichage

**En-tête**: l'en-tête est une ligne fixe. Donc, nous pouvons faire une fonction void qui print l'en-tête.

**Lignes**: une ligne -> un bloc de 16 octets. 


## Les paramètres de fread(destination, taille, compte, fichier)
Dans `fread(buffer, 1, 4, fichier)` :

`buffer` : où mettre les octets lus
`1` : chaque donnée fait 1 octet
`4` : on veut lire 4 données
`fichier` : le fichier source

