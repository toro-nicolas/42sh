# 42sh



## Description



## Documentation

### Ouvrir la documentation
Pour ouvrir la documentation, il suffit de lancer la commande suivante :    
```bash
google-chrome ./documentation/html/index.html
```
Je vous conseil d'ajouter à votre .zshrc cet alias :    
```bash
alias open_doc="google-chrome ./documentation/html/index.html"
```
Vous aurez juste à éxécuter la commande ```open_doc``` pour ouvrir la documentation    

### Générer la documentation
Vous pouvez générer la documentation en fessant un ```make doc```.    
Bien sur vous aurez besoin de Doxygen. Voici les commandes sur Fedora pour l'installer :    
```bash
sudo dnf install doxygen doxygen-latex doxygen-doxywizard graphviz
```
En cas de problème, vous pouvez me contacter.     

## Tester
Le tester que j'utilise est différent du testeur fournit par EPITECH.    
Chaque erreur et en rouge et chaque test valide en vert.    
Le chiffre afficher à la fin représenter le nombre de test qui **ne passent pas**.    
Veuillez ne pas augmenter le nombre de tests qui ne passent pas.    

Pour éxécuter le testeur, faite juste ```./tester.sh``` ou faite un ```make tests```.
Vous pouvez voir si vous perdez des tests en comparant votre vos résultats avec ceux du fichier ```test_reference```.

## Code mandatory
- Vous devrez créer une branche ou vous pusherez votre code. Une fois vos tâches réalisé sur cette branche, nous verrons à plusieurs pour la merge et vérifier que tout fonctionne
- Chaque fonctions que vous ajouterez devra être coding-style et muni d'une documentation
- Avant de merge vous vérfierez que tout les unit tests passent en fessant ```make tests run```
- Vous devrez aussi verifier que les tests du testeur fassent ne dépassent pas les 60 erreurs (votre code aura donc pété quelque chose dans le 42sh)
- Si les github actions ne réussisent pas, alors posez vous des questions
- Chaque commit contiendra ```[+]``` ou ```[-]``` ou ```[~]``` suivi d'un message  
    - ```[+]``` : Ajout de fonctionnalité
    - ```[-]``` : Suppression de fonctionnalité
    - ```[~]``` : Modification de fonctionnalité

**Bien sur lors de cas execptionnel, nous pourrons déroger à ces règles**

## Results

| Category                         | Percentage | Numbers of tests |  Crash   |
|----------------------------------|:----------:|:----------------:|:--------:|
| basic tests                      |    100%    |       4/4        |    No    |
| path handling                    |    100%    |       5/5        |    No    |
| setenv and unsetenv              |    100%    |       2/2        |    No    |
| builtin cd                       |    100%    |       3/3        |    No    |
| line formatting (space and tabs) |    100%    |       8/8        |    No    |
| error handling                   |    100%    |       6/6        |    No    |
| separator                        |    100%    |       1/1        |    No    |
| simple pipes                     |    100%    |       3/3        |    No    |
| advanced pipes                   |    100%    |       6/6        |    No    |
| redirections                     |    100%    |       5/5        |    No    |
| advanced manipulations           |    100%    |       3/3        |    No    |
| && and \|\| tests                |    100%    |       3/3        |    No    |
| globbing                         |    100%    |       1/1        |    No    |
| var interpreter                  |   66,7%    |       2/3        |    No    |
| inhibitor                        |    100%    |       2/2        |    No    |
| magic quotes                     |     0%     |       0/3        |    No    |
| alias                            |    100%    |       4/4        |    No    |
| scripting                        |     0%     |       0/1        |    No    |
| foreach                          |     0%     |       0/1        |    No    |
| which                            |    100%    |       2/2        |    No    |
| where                            |    100%    |       2/2        |    No    |
| if                               |     0%     |       0/2        |    No    |
| repeat                           |    100%    |       1/1        |    No    |
| parenthesis                      |     0%     |       0/1        |    No    |
| **Results**                      | **87,5%**  |    **63/72**     |  **No**  |

## Credits
- Nicolas TORO
- Gianni TUERO
- Arthur WARIN
- Christophe VANDEVOIR
- Raphael ROSSIGNOL
