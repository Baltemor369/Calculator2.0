# Calculator2.0
[First project] Create a calculator with C++ language

[Premier projet] Creation d'une calculatrice en C++ prenant en charge les operations + - * / ! ^ (puissance) #(racine carré), ainsi que les parenthèses pour les priorités de calcul.

Pour utiliser la calculatrice dans d'autre projet, il suffit de mettre les deux fichiers "calculator.cpp" et "calculator.hpp" dans votre projet, ainsi que mettre la ligne de code : 

#include ".\Path\calculator.hpp".

pour utiliser seulement la calculatrice, il vous faut les fichier "calculator.cpp","calculator.hpp" et "main.cpp" dans le même dossier, puis compiler les fichiers grâce à cette commande :

-g++ .\calculator.cpp .\main.cpp -o calcul.exe

Puis pour faire un calcul :

-calcul.exe "votre_calcul" 

La forme du resultat est la suivante : "votre_calcul = le_resultat"

Des améliorations et corrections de bug seront à prévoir, le git sera donc mis à jour si nécessaire.

Les améliorations déjà pensées :
+ mettre en place une interface graphique(GUI) pour faciliter l'utilisation.
+ permettre des calculs avec des fonctions plus complexe.
+ permettre des caluls avec inconnus et ainsi des études de fonctions.

Des erreurs de traduction Fr/En sont possible dans le programme(les commentaires en particulier), une correction sera faite.
