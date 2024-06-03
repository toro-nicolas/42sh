#!/bin/bash

# Executables
executables="42sh"

# Couleur pour les messages
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'
BOLD='\033[1m'

# Fonction pour compter les occurrences d'un mot dans un fichier
count_occurrences() {
    local word=$1
    local file=$2
    grep -o -i -w "$word" "$file" | wc -l
}

# Nom du fichier de résultat
file="plum_result.txt"

# Exécution du coding style checker
plum > $file

# Compter les occurrences de MAJOR, MINOR et INFO
major_count=$(count_occurrences "MAJOR" "$file")
minor_count=$(count_occurrences "MINOR" "$file")
info_count=$(count_occurrences "INFO" "$file")

# Vérifier si le fichier contient plus de 2 occurrences de MAJOR, MINOR ou INFO
if [ $major_count -gt 2 ] || [ $minor_count -gt 2 ] || [ $info_count -gt 2 ]; then
    cat $file
    echo -e "${RED}${BOLD}${BOLD}INTERDICTION DE PUSH:${RED}${RED} Le fichier contient des erreurs de Coding-Style !$RESET"
    rm -rf $file
    exit 1
else
    echo -e "${GREEN}Aucune erreur de Coding-Style détecter.${RESET}"
fi

# Supprimer le fichier de résultat
rm -rf $file

# Tester la compilation
make >/dev/null 2>&1 &
pid=$!
wait $pid
if [ $? -ne 0 ]; then
    echo -e "${RED}${BOLD}INTERDICTION DE PUSH:${RED} La compilation a échouée.${RESET}"
    exit 1
else
    echo -e "${GREEN}La compilation s'est déroulée correctement.${RESET}"
fi

# Tester
make clean >/dev/null 2>&1 &
pid=$!
wait $pid

# Check la création de l'exécutable
.github/workflows/check_program_compilation $executables >/dev/null 2>&1 &
pid=$!
wait $pid
if [ $? -ne 0 ]; then
    echo -e "${RED}${BOLD}INTERDICTION DE PUSH:${RED} Les executables n'ont pas été trouvé.${RESET}"
    exit 1
else
    echo -e "${GREEN}Les executables ont bien été trouvé.${RESET}"
fi

# Tester les unit tests
make tests_run >/dev/null 2>&1 &
pid=$!
wait $pid
if [ $? -ne 0 ]; then
    echo -e "${RED}${BOLD}INTERDICTION DE PUSH:${RED} Les tests unitaires ont échoués.${RESET}"
    exit 1
else
    echo -e "${GREEN}Les tests unitaires se sont déroulés correctement.${RESET}"
fi

# Vérifier la taille du repository
make fclean >/dev/null 2>&1 &
pid=$!
wait $pid
size=$(du -sm --exclude='.git' | cut -f1)
limit=50
if [ "$size" -gt "$limit" ]; then
    echo -e "${RED}${BOLD}INTERDICTION DE PUSH:${RED} La taille du repository dépasse la limite autorisée ($size MB > $limit MB)${RESET}"
    exit 1
else
    echo -e "${GREEN}La taille du repository est inférieure à la limite autorisée ($size MB < $limit MB)${RESET}"
fi

# Push
echo -e "${GREEN}${BOLD}PUSH AUTORISÉ !${RESET}"
git push