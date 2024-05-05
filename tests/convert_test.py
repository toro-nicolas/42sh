import re
import sys


def generate_test(test_number, setup, test_commands, output_file, name):
    # Supprimer les guillemets simples autour de setup
    setup = re.sub(r"'", "", setup)

    print(f"Test({name}{test_number}, full_gcorv)", file=output_file)
    print("{", file=output_file)
    print(f"    char **env = my_str_to_word_array_select(\"{setup}\", \" ;\");", file=output_file)
    print(f"    FILE *file = fopen(\"test_input.txt\", \"w\");", file=output_file)
    print(f"", file=output_file)
    for command in test_commands:
        print(f"    fprintf(file, \"{command}\\n\");", file=output_file)
    print(f"    fprintf(file, \"exit\\n\");", file=output_file)
    print(f"    fclose(file);", file=output_file)
    print(f"    freopen(\"test_input.txt\", \"r\", stdin);", file=output_file)
    print(f"    shell(env);", file=output_file)
    print("}\n", file=output_file)


def main():
    # Lire le contenu du fichier "test.txt"
    with open("test.txt", "r") as file:
        input_str = file.read()

    # Analyse de la chaîne d'entrée
    parts = input_str.split("\n")
    test_number = parts[0][1:-1]

    try:
        name = parts[1].split("=")[1][1:-1]

        # Utiliser une expression régulière pour extraire la valeur après "export" et avant les guillemets
        setup_match = re.search(r'export ([^"]+)', parts[2])
        if setup_match:
            setup = setup_match.group(1)
        else:
            setup = ""  # En cas de correspondance non trouvée, laisser setup vide

        # Analyse des commandes de test
        test_commands = []
        for line in parts[5:]:
            if line.startswith("  echo '") and line.endswith("'"):
                test_commands.append(line[8:-1])
            elif line.startswith('  echo "') and line.endswith('"'):
                test_commands.append(line[8:-1])

        # Échapper les caractères spéciaux
        new_test_commands = []
        for command in test_commands:
            command = command.replace("\\", "\\\\")
            command = command.replace("\"", "\\\"")
            command = command.replace("\'", "\\\'")
            new_test_commands.append(command)
        test_commands = new_test_commands

        # Générer le nom du fichier de sortie
        file = "./tests/functional_test_"
        name = ""
        for c in sys.argv[1]:
            if c == ".":
                break
            name += c
        file += name + ".c"

        # Ecrire le test généré dans le fichier de sortie
        with open(file, "a") as output_file:
            generate_test(test_number, setup, test_commands, output_file, name)
    except:
        print("Erreur lors de la génération du test " + parts[1])


if __name__ == "__main__":
    main()
