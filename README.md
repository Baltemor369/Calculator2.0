# Calculator2.0
[First project] Create a calculator with C++ language

Premier projet en C++
Creation d'un calculatrice prenant en charge les operations + - * / ! ^ (puissance) #(racine carré), ainsi que les parenthèses pour les priorités de calcul.

Les fichiers ont été sous la forme d'un module à simplement include dans d'autre projet au besoin.

Le fichier "main.cpp" permet l'utilisation de la calculatrice tel quel:

Une seule compilation nécessaire avec la commande :

-g++ .\calculator.cpp .\main.cpp -o calcul.exe

Puis pour faire les calculs :

-calcul.exe "votre_calcul" 

La forme du resultat est la suivante : "votre_calcul = le_resultat"

Des améliorations seront bien évidemment à prévoir, le git sera donc mis à jour si nécessaire.

Les améliorations déjà pensées :
+ mettre en place une interface graphique(GUI) pour faciliter l'utilisation.
+ permettre des calculs avec des fonctions plus complexe.
+ permettre des caluls avec inconnus et ainsi des études de fonctions.
