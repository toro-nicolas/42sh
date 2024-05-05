import os
import sys


def extract_tests(input_file, output_file):
    with open(input_file, "r") as file:
        content = file.read()

    tests = content.split("\n\n")  # Séparer les tests par blocs vides
    for test in tests:
        if test.strip():  # Ignorer les blocs vides
            with open(output_file, "w") as out_file:
                out_file.write(test)
            os.system("python tests/convert_test.py " + sys.argv[1])  # Exécuter le script convert_test.py


def main():
    test_ini_file = "tests/test_files/" + sys.argv[1]
    test_txt_file = "test.txt"
    c_file = "./tests/functional_test_"
    for c in sys.argv[1]:
        if c == ".":
            break
        c_file += c
    c_file += ".c"

    try:
        os.remove(c_file)
    except FileNotFoundError:
        pass

    with open(c_file, "a") as output_file:
        print("/*\n" +
            "** EPITECH PROJECT, 2024\n" +
            "** 42sh\n" +
            "** File description:\n" +
            f"** The {sys.argv[1]}\n" +
            "*/\n" +
            "\n" +
            "#include \"criterion/criterion.h\"\n" +
            "#include \"criterion/redirect.h\"\n" +
            "#include \"../include/myshell.h\"\n", file=output_file)
    extract_tests(test_ini_file, test_txt_file)

    try:
        os.remove(test_txt_file)
    except FileNotFoundError:
        pass


if __name__ == "__main__":
    main()
