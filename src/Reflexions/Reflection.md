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
