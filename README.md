# 💻 42sh 🐚

![42sh](https://toro-nicolas.github.io/42sh/preview.png)

## Table of contents 📑
- [Description](https://github.com/toro-nicolas/42sh/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/42sh/blob/main/README.md#usage-%EF%B8%8F)
- [Features list](https://github.com/toro-nicolas/42sh/blob/main/README.md#features-list-)
- [Result](https://github.com/toro-nicolas/42sh/blob/main/README.md#result-)
- [Compilation](https://github.com/toro-nicolas/42sh/blob/main/README.md#compilation-%EF%B8%8F)
- [Documentation](https://github.com/toro-nicolas/42sh/blob/main/README.md#documentation-)
- [Code mandatory](https://github.com/toro-nicolas/42sh/blob/main/README.md#code-mandatory-)
- [What's next ?](https://github.com/toro-nicolas/42sh/blob/main/README.md#whats-next--)
- [Contributors](https://github.com/toro-nicolas/42sh/blob/main/README.md#contributors-)

## Description 📝
The **42sh** is a project carried out by **groups of 5** (see [Contributors](https://github.com/toro-nicolas/42sh/blob/main/README.md#contributors-), during our **1st year** in [**EPITECH**](https://www.epitech.eu/) Grand Ecole program.  
Its purpose is to recreate in [**C**](https://en.wikipedia.org/wiki/C_(programming_language)) a [**Unix shell**](https://en.wikipedia.org/wiki/Unix_shell) based on [**TCSH**](https://en.wikipedia.org/wiki/Tcsh).  
In addition, we've taken inspiration from [Powerlevel10k](https://github.com/romkatv/powerlevel10k) for our **shell prompt**.  


## Usage ⚔️
You can run 42sh like this :
```sh
./42sh
```

You can execute script with 42sh like this :
```sh
./42sh [script]
```

You can also add the **42sh** to the **shebang of a script**, and when you run the script it will use the 42sh.  

For more information, please see the help section.
```sh
> ./42sh --help
USAGE
    ./42sh
    ./42sh [script]
DESCRIPTION
    A Unix shell based on TCSH.
    You can execute the help command to see the list of available builtins.
```


## Features list 📋
Our **42sh** includes many of the **features found** in **TCSH** :
- Executing a simple command
- Executing recreated builtins :
  - about
  - alias
  - cd
  - echo
  - else
  - end
  - endif
  - env
  - exit
  - foreach
  - help
  - history
  - if
  - repeat
  - set
  - setenv
  - source
  - unalias
  - unset
  - unsetenv
  - where
  - which
- Dynamic prompt
- Dynamic line edition (use arrow and ctrl command)
- Use of history and event (all commands are stock in the .42sh_history)
- Use of variable (local and environmental)
- Handle of specials variabes (~, ? and some other variables)
- Handle backticks ("`")
- Handle semi-colons (";")
- Handle operators ("&&" and "||")
- Handle pipes ("|")
- Handle redirection ("<", "<<", ">" and ">>")
- Handle inhibitors ('"', "'" and "\\")
- Handle parentheses ("()")
- Handle globbing ("*", "?", "[" and "]")
- Handle alias
- Handle scripting and scripting commands (if, else, endif, foreach and end)


## Result 🚩
The result of this project is a **almost perfect shell**, **very similar to TCSH**.  
If you discover a **problem** or an **error**, don't hesitate to **create an issue** and **report it** to us as soon as possible.

### my.epitech.eu result

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

### Tests and code coverage
Functional tests were carried out with a **bash tester** and **unit tests** using [criterion](https://criterion.readthedocs.io/en/master/intro.html).  
Unit tests are still to be performed, but a large part of the code is already covered:  
- Lines: 84.8%
- Functions: 94.7%
- Branches:	45.4%

You can run the tester with this command :
```sh
./tester.sh
```
You can compile the project and run the tester with this command :
```sh
make tests
```
You can compile the project and run the unit tests with this command :
```sh
make tests_run
```
  
For more details, please click [here](https://toro-nicolas.github.io/42sh/tests/test.html).


## Compilation 🛠️
You can compile the project with this command :
```sh
make
```

If you want to debug the program, you can compile the project with this :
```sh
make debug 
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re``` and for debugging ```make re_debug```

You can compile the unit tests with this command :
```sh
make unit_tests
```


## Documentation 📚
The documentation is accessible [here](https://toro-nicolas.github.io/42sh/html/). 

You can generate the documentation with this command :
```sh
make doc
```
You need multiple package for generate them :
- doxygen
- doxygen-latex
- doxygen-doxywizard
- graphviz


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be code-style and documented.
- Before merging, you'll need to check that all unit tests pass by running ```make tests_run```.
- If the github actions don't succeed, then ask yourself some questions
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
  - ```[+]``` : Added functionality
  - ```[-]``` : Delete feature
  - ```[~]``` : Feature modification

**Of course, in exceptional cases, we may depart from these rules.**  


## What's next ? 🚀
- Fix the latest scripting problems
- Fix final bugs in prompt and command writing
- Add job controls (background process, ctrl + Z, ...)
- Add unit tests on each piece of code


## Contributors 👥
For this project, we were a group of **5 people**. Here are the people in the group:  
- [Arthur WARIN](https://github.com/arthurwarin)
- [Christophe VANDEVOIR](https://github.com/ItsKarmaOff) : also published the [42sh](https://github.com/ItsKarmaOff/42sh)
- [Gianni TUERO](https://github.com/xJundo)
- [Nicolas TORO](https://github.com/toro-nicolas) : also published the [42sh](https://github.com/toro-nicolas/42sh)
- [Raphael ROSSIGNOL](https://github.com/RaphRoss)
