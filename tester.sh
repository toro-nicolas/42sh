#!/bin/bash

rm -rf /tmp/.tester.* /tmp/.runner.* /tmp/.refer.* /tmp/.shell.* /tmp/test*
echo "Tests for PARSING :"
echo "tests/test_files/parsing.ini" > tests/file
tests/tester.sh
echo "Tests for CD :"
echo "tests/test_files/cd.ini" > tests/file
tests/tester.sh
echo "Tests for ENV :"
echo "tests/test_files/environnement.ini" > tests/file
tests/tester.sh
echo "Tests for EXIT :"
echo "tests/test_files/exit.ini" > tests/file
tests/tester.sh
echo "Tests for COMMANDS :"
echo "tests/test_files/commands.ini" > tests/file
tests/tester.sh
echo "Tests for BACKTICKS :"
echo "tests/test_files/backticks.ini" > tests/file
tests/tester.sh
echo "Tests for MULTI COMMANDS :"
echo "tests/test_files/multi_commands.ini" > tests/file
tests/tester.sh
echo "Tests for OPERATORS :"
echo "tests/test_files/operators.ini" > tests/file
tests/tester.sh
echo "Tests for PIPES :"
echo "tests/test_files/pipes.ini" > tests/file
tests/tester.sh
echo "Tests for REDIRECTIONS :"
echo "tests/test_files/redirections.ini" > tests/file
tests/tester.sh
echo "Tests for PARENTHESES :"
echo "tests/test_files/parentheses.ini" > tests/file
tests/tester.sh
echo "Tests for INHIBITORS :"
echo "tests/test_files/inhibitors.ini" > tests/file
tests/tester.sh
echo "Tests for GLOBBING :"
echo "tests/test_files/globbing.ini" > tests/file
tests/tester.sh
echo "Tests for ALIAS :"
echo "tests/test_files/alias.ini" > tests/file
tests/tester.sh
echo "Tests for WHERE :"
echo "tests/test_files/where.ini" > tests/file
tests/tester.sh
echo "Tests for WHICH :"
echo "tests/test_files/which.ini" > tests/file
tests/tester.sh
echo "Tests for REPEAT :"
echo "tests/test_files/repeat.ini" > tests/file
tests/tester.sh
echo "Tests for SCRIPTING :"
echo "tests/test_files/scripting.ini" > tests/file
tests/tester.sh
echo "Tests for VARIABLES :"
echo "tests/test_files/variables.ini" > tests/file
tests/tester.sh
echo "Tests for OTHER :"
echo "tests/test_files/other.ini" > tests/file
tests/tester.sh